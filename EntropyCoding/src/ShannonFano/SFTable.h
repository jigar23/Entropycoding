/*
 * SFTable.h
 *
 *  Created on: Jan 27, 2014
 *      Author: jigar
 */

#ifndef SFTABLE_H_
#define SFTABLE_H_
#include "../CodeTable/codetable.h"
#include "shannonFano.h"
#include "../FileIO/fileIO.h"
using namespace std;

codetable** getSFCodeWords(char *memblock, char *opFileName);

#endif /* SFTABLE_H_ */
