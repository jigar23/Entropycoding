/*
 * HuffmanTable.h
 *
 *  Created on: Jan 21, 2014
 *      Author: jigar
 */

#ifndef HUFFMANTABLE_H_
#define HUFFMANTABLE_H_
#include "huffman.h"
#include "Node/NodeH.h"
#include "../FileIO/fileIO.h"

class codetable;
codetable** getHuffmanCodeWords(char *memblock, char *opFile);

#endif /* HUFFMANTABLE_H_ */
