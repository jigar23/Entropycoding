/*
 * Node.h
 *
 *  Created on: Jan 27, 2014
 *      Author: jigar
 */

#ifndef NODE_H_
#define NODE_H_
#include <iostream>
#include "../global.h"

class Node {
	Node *parent;
	int start;
	int end;
	bool bit;

public:
	static int COUNT;
	Node();
	virtual ~Node();
	bool isBit() const;
	void setBit(bool bit);
	void setEnd(int end);
	int getEnd() const;
	Node*& getParent();
	void setParent(Node*& parent);
	int getStart() const;
	void setStart(int start);
	int getEndValue(int, int);
};

#endif /* NODE_H_ */
