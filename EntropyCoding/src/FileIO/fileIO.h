/*
 * fileIO.h
 *
 *  Created on: Jan 24, 2014
 *      Author: jigar
 */

#ifndef FILEIO_H_
#define FILEIO_H_
#include <iostream>
#include <fstream>
#include "../global.h"
#include "../CodeTable/codetable.h"

char* readFileByBytes(char *);
void writeSingleCode(unsigned long code, char size);
void writePrepare(char *fileName);
void closeFile();
void checkStatusOfLastBit();
int getFileSize(char *filename);
void writeHeader();

#endif /* FILEIO_H_ */
