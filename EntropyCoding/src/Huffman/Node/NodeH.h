/*
 * NodeH.h
 *
 *  Created on: Jan 30, 2014
 *      Author: jigar
 */

#ifndef NODEH_H_
#define NODEH_H_
#include <iostream>
using namespace std;

class NodeH {
	int symbol;
	float prob;
	bool bit;
	NodeH *next;
public:
	static int COUNT;
	NodeH();
	virtual ~NodeH();
	bool isBit() const;
	void setBit(bool bit);
	NodeH* getNext() const;
	void setNext(NodeH* next);
	float getProb() const;
	void setProb(float prob);
	int getSymbol() const;
	void setSymbol(int symbol);
	void printNode(NodeH* node);
};

#endif /* NODEH_H_ */
