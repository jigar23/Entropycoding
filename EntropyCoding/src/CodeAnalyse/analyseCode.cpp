/*
 * analyseCode.cpp
 *
 *  Created on: Jan 25, 2014
 *      Author: jigar
 */

#include "analyseCode.h"

using namespace std;

void analyseAHuffmanCode(string fileName, char *opFileName) {
	int opFileSize;
	opFileSize = getFileSize(opFileName);
	cout << "*encoded.dat* file in this folder contains the encoded data"
			<< endl;
	cout << endl;
	cout << "*****************************" << endl;
	cout << "Filename:" << fileName << endl;
	cout << "Original File size : " << FileSizeinBytes << " bytes" << endl;
	cout << "File Size after compression : " << opFileSize << " bytes" << endl;
	cout << "Compression Ratio : " << (float) opFileSize / FileSizeinBytes * 100
			<< "%" << endl;
	cout << "*****************************" << endl;

}

void analyseCode(codetable **codewords, string filename, char *opFileName) {
	float entropy, avgLength, redundancy;
	int fileSize;
	entropy = computeEntropy();
	avgLength = averageCodeLength(codewords);
	redundancy = avgLength - entropy;
//	fileSize = fileSizeAfterCompression(codewords);
	fileSize = getFileSize(opFileName);
	cout << "*encoded.dat* file in this folder contains the encoded data"
			<< endl;
	cout << endl;
	cout << "*****************************" << endl;
	cout << "Filename:" << filename << endl;
	cout << "Entropy : " << entropy << endl;
	cout << "Average Code length : " << avgLength << endl;
	cout << "Coding Redundancy : " << redundancy << endl;
	cout << "Original File size : " << FileSizeinBytes << " bytes" << endl;
	cout << "File Size after compression : " << fileSize << " bytes" << endl;
	cout << "Compression Ratio : " << (float) fileSize / FileSizeinBytes * 100
			<< "%" << endl;
	cout << "*****************************" << endl;

}

//Compute the entropy using counts of each symbol
float computeEntropy() {
	float entropy = 0;
//	for(int i = 0; i < no_of_symbols; i++){
//		entropy -= prob[i]*log2f(prob[i]);
//	}
	long int count = FileSizeinBytes;
	float temp = log2f(count);
	for (int i = 0; i < no_of_symbols; i++) {
		entropy += symbolFreq[i] * log2f(symbolFreq[i]) - symbolFreq[i] * temp;
	}
	entropy = -entropy / count;
//	cout << "ENtropy is:" << entropy << endl;
	return entropy;
}

float averageCodeLength(codetable **codewords) {
	float avgLength = 0;
	for (int i = 0; i < no_of_symbols; i++) {
		avgLength += symbolFreq[i] * codewords[i]->getSize();
	}
	avgLength /= FileSizeinBytes;
//	cout << "Average Length is : " << avgLength << endl;
	return avgLength;

}

float fileSizeAfterCompression(codetable **codewords) {
	float fileSize = 0;
	for (int i = 0; i < no_of_symbols; i++) {
		fileSize += symbolFreq[i] * codewords[i]->getSize();
	}
	//convert into bytes
	fileSize /= 8;
	return fileSize;
}

//float* calculateProb(){
//	long int sum = sumOfProb();
//	cout << "total count: " << FileSizeinBytes <<endl;
//	float *prob = new float[no_of_symbols];
//	for (int i = 0; i < no_of_symbols; i++){
//		prob[i] = (float)symbolFreq[i]/sum;
//		cout << "prob of " << LetterMap[i] << " is " << prob[i] << endl;
//	}
//	return prob;
//}
