/*
 * global.h
 *
 *  Created on: Jan 21, 2014
 *      Author: jigar
 */

#ifndef GLOBAL_H_
#define GLOBAL_H_

#include <map>
#include <vector>
#include "Ahuffman/Tree.h"

//Definition of these variables are in the LetterFrequency.cpp file.
//no_of_chars are the total #of symbols used
extern int no_of_symbols;

// This array stores the probability/frequency of each symbol used.
//2 bytes
extern unsigned short int *symbolFreq;

extern int FileSizeinBytes;

//Map which maps integers to their corresponding symbol values.
extern std::map<int, int> LetterMap;

//Store the list of symbols present
extern vector<char> symbolList;

//for Adaptive huffman
extern std::vector<Tree*> treeElements;

extern std::vector<Tree*> leafNodes;

#endif /* GLOBAL_H_ */
