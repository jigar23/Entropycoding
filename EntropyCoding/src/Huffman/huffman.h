/*
 * huffman.h
 *
 *  Created on: Jan 20, 2014
 *      Author: jigar
 */

#ifndef HUFFMAN_H_
#define HUFFMAN_H_

#include <iostream>
#include "Node/NodeH.h"
#include "../global.h"
#include "../FrequencyChart/LetterFrequency.h"
#include "HuffmanTable.h"
#include "../CodeTable/codetable.h"

//Hoover on the function names to get
//details of the function.

//Let the compiler know that such a class exists.

int findSmaller(NodeH*[], int);

void buildHuffmanTree(NodeH **);

codetable getHuffmanCodeWordForSymbol(NodeH **, int);

void printAllNodeValues(NodeH*[]);

codetable** getHuffmanCodeWords();

#endif /* HUFFMAN_H_ */
