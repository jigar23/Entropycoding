/*
 * encodeSymbol.h
 *
 *  Created on: Feb 2, 2014
 *      Author: jigar
 */

#ifndef ENCODESYMBOL_H_
#define ENCODESYMBOL_H_

#include "TreeManipulations.h"
#include "../CodeTable/codetable.h"
#include "../global.h"
#include "../FileIO/fileIO.h"
#include <iostream>

using namespace std;
void buildAHuffmanTree(char *val, int length, char *opFile);

#endif /* ENCODESYMBOL_H_ */
