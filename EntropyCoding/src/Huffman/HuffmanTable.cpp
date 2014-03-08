/*
 * HuffmanTable.cpp
 *
 *  Created on: Jan 21, 2014
 *      Author: jigar
 */

#include "HuffmanTable.h"
void writeHuffmanCodeValues(codetable **codeTable, char *memblock, char*);

/**
 * This function does all the major work of the huffman coding.
 * It generates the huffman codes by building the huffman tree first
 * and then encoding it.
 */
codetable ** getHuffmanCodeWords(char *memblock, char *opFile) {

	//set the initial count value
	//no_of_symbols is a global variable.
	NodeH::COUNT = no_of_symbols;

	//set the size of the array as the
	//total # of nodes = 2*n-1
	int size = 2 * no_of_symbols - 1;
	NodeH **LLArray = new NodeH*[size];

	//Build huffman tree
	buildHuffmanTree(LLArray);

	codetable **codeTable = new codetable*[no_of_symbols];

	//ht.setSymbol(0);
	// Generate huffman codes for each symbol.

	for (int i = 0; i < no_of_symbols; i++) {
		codeTable[i] = new codetable;
		codeTable[i]->setSymbol(i);
		codetable ht;
		//ht.setSymbol(i);
		ht = getHuffmanCodeWordForSymbol(LLArray, i);

		codeTable[i]->setSize(ht.getSize());
		codeTable[i]->setCode(ht.getCode());
//		cout << "Symbol : " << codeTable[i]->getSymbol() << " CodeWord: " <<
//				ht.printBitStream(ht.getCode(), ht.getSize()) << endl;

	}

	writeHuffmanCodeValues(codeTable, memblock, opFile);
//	printCodeValues(codeTable);
	//free the memory of Linked List Array
	delete[] LLArray;
	return codeTable;

	//printAllNodeValues(LLArray);
}
void writeHuffmanCodeValues(codetable **ct, char *memblock, char *opFile) {

	//Prepare the file for writing (i.e open the file)
	writePrepare(opFile);

	//write the overhead indicating the frequency of each symbol.
	writeHeader();
	for (int i = 0; i < FileSizeinBytes; i++) {
		int pos = LetterMap[memblock[i]];
		unsigned long int code = ct[pos]->getCode();
		unsigned char size = ct[pos]->getSize();
		writeSingleCode(code, size);
	}

	checkStatusOfLastBit();
	closeFile();
}

