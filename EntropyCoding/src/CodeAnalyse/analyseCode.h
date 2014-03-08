/*
 * analyseCode.h
 *
 *  Created on: Jan 25, 2014
 *      Author: jigar
 */

#ifndef ANALYSECODE_H_
#define ANALYSECODE_H_

#include <iostream>
#include <tgmath.h>
#include "../global.h"
#include "../CodeTable/codetable.h"
#include "../FileIO/fileIO.h"

//float* calculateProb();
//class HuffmanTable;

void analyseCode(codetable **, string, char *opFileName);
void analyseAHuffmanCode(string fileName, char *opFileName);
float computeEntropy();
float averageCodeLength(codetable **);
float fileSizeAfterCompression(codetable **);

#endif /* ANALYSECODE_H_ */
