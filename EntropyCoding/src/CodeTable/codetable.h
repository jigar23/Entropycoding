/*
 * codetable.h
 *
 *  Created on: Jan 29, 2014
 *      Author: jigar
 */

#ifndef CODETABLE_H_
#define CODETABLE_H_
#include <string>
#include <iostream>
using namespace std;
class codetable {
	unsigned long code;
	unsigned char size;
	int symbol;
public:
	codetable();
	virtual ~codetable();
	unsigned long getCode() const;
	void setCode(unsigned long code);
	unsigned char getSize() const;
	void setSize(unsigned char size);
	int getSymbol() const;
	void setSymbol(int symbol);
	string printBitStream(char code, char size);
};

#endif /* CODETABLE_H_ */
