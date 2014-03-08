/*
 * SFTable.cpp
 *
 *  Created on: Jan 27, 2014
 *      Author: jigar
 */

#include "SFTable.h"
void writeSFCodeValues(codetable **ct, char *memblock, char*opFile);

/**
 * This function sorts the symbol Frequency in descending
 * order and stores their indices as well.
 *
 */

void quicksort(unsigned short int arr[], int left, int right, int pos[]) {
	int i = left, j = right;
	int tmp;
	int pivot = arr[(left + right) / 2];

	/*partition */
	while (i <= j) {
		while (arr[i] > pivot)
			i++;
		while (arr[j] < pivot)
			j--;
		if (i <= j) {
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;

			tmp = pos[i];
			pos[i] = pos[j];
			pos[j] = tmp;
			i++;
			j--;

		}
	}

	if (left < j)
		quicksort(arr, left, j, pos);
	if (right > i)
		quicksort(arr, i, right, pos);
}

int *pos;
/**
 * This function does all the major work of the huffman coding.
 * It generates the huffman codes by building the huffman tree first
 * and then encoding it.
 */
codetable** getSFCodeWords(char *memblock, char *opFile) {

	//initialize the position array
	pos = new int[no_of_symbols];
	for (int i = 0; i < no_of_symbols; i++)
		pos[i] = i;
	//Sort the symbols in descending ordersymbols
	quicksort(symbolFreq, 0, no_of_symbols - 1, pos);

	//Build huffman tree
	Node **list;
	list = ShannonTree();

	codetable **codeTable = new codetable*[no_of_symbols];

	for (int i = 0; i < no_of_symbols; i++) {
		codeTable[i] = new codetable;

		//IMP: set the symbol as pos[i] but call only i.
		codeTable[i]->setSymbol(i);
		codetable ht;
		//ht.setSymbol(i);
		//In the position array, check where each of the symbols are
		int j;
		for (j = 0; j < no_of_symbols; j++) {
			if (i == pos[j])
				break;
		}
		ht = getCodeWordForSymbol(list, j);

		codeTable[i]->setSize(ht.getSize());
		codeTable[i]->setCode(ht.getCode());

	}

	//printCodeValues(codeTable);
	//free the memory of Linked List Array
	delete[] list;
	writeSFCodeValues(codeTable, memblock, opFile);
	return codeTable;
	//printAllNodeValues(LLArray);
}

void writeSFCodeValues(codetable **ct, char *memblock, char* opFile) {

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

