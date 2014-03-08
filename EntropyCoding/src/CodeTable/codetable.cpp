/*
 * codetable.cpp
 *
 *  Created on: Jan 29, 2014
 *      Author: jigar
 */

#include "codetable.h"

codetable::codetable() {
	// TODO Auto-generated constructor stub
	code = 0;
	size = 0;
	symbol = -1;

}

unsigned long codetable::getCode() const {
	return code;
}

void codetable::setCode(unsigned long code) {
	this->code = code;
}

unsigned char codetable::getSize() const {
	return size;
}

void codetable::setSize(unsigned char size) {
	this->size = size;
}

int codetable::getSymbol() const {
	return symbol;
}

void codetable::setSymbol(int symbol) {
	this->symbol = symbol;
}

codetable::~codetable() {
	// TODO Auto-generated destructor stub
}

//
/**
 * This function generates the string using the codeword and the size.
 * The function prints the string in reverse order thus reversing the reversed code
 * and we get the proper code.
 *
 */
string codetable::printBitStream(char code, char size) {
	string str = "";
	for (int i = 0; i < size; i++) {
		str.append(((code & (1 << i)) ? "1" : "0"));
	}
	return str;
}
