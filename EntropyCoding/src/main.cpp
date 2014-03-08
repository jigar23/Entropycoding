//============================================================================
// Name        : EntropyCoding.cpp
// Author      : Jigar Gada
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "global.h"
#include <string>
#include "Huffman/HuffmanTable.h"
#include "ShannonFano/SFTable.h"
#include "Ahuffman/encodeSymbol.h"
#include "FrequencyChart/LetterFrequency.h"
#include "CodeTable/codetable.h"
#include "FileIO/fileIO.h"
#include "CodeAnalyse/analyseCode.h"

using namespace std;

int main() {
	//Read the file and store it the memory byte by byte.
	cout << "-----------------------------" << endl;
	cout << "Enter the *full* file Path with name: " << endl;
	char fileName[256];
	cin.getline(fileName, 256);
//	char fileName[] = "resources/image.dat";
	char opFileName[] = "encodedData.dat";
	char *memblock = readFileByBytes(fileName);

	//Make frequency chart of the symbols
	setLetterFrequency(memblock);

	//Get the codeword table
	codetable** codeWords;

	int flag = 0;

	while (flag == 0) {
		int k;
		cout << "Enter" << endl << "1. Huffman Coding" << endl
				<< "2. Shannon Fano coding" << endl << "3. Adaptive Huffman"
				<< endl;
		cin >> k;
		switch (k) {
		case 1:
			cout << "Huffman Coding details are as follows:" << endl;
			codeWords = getHuffmanCodeWords(memblock, opFileName);
			//	Analyse the codewords, Their entropy, Avg codeword length etc.
			analyseCode(codeWords, fileName, opFileName);
			flag = 1;
			break;

		case 2:
			cout << "Shannon Fano Coding details are as follows:" << endl;
			codeWords = getSFCodeWords(memblock, opFileName);
			//	Analyse the codewords, Their entropy, Avg codeword length etc.
			analyseCode(codeWords, fileName, opFileName);
			flag = 1;
			break;

		case 3:
			cout << "Adaptive Coding details are as follows:" << endl;
			buildAHuffmanTree(memblock, FileSizeinBytes, opFileName);
			analyseAHuffmanCode(fileName, opFileName);
			flag = 1;
			break;

		default:
			cout << "Invalid Entry..!!!!" << endl;
			cout << "Try Again" << endl;
		}
	}

	return 0;

}
