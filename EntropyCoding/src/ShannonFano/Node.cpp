/*
 * Node.cpp
 *
 *  Created on: Jan 27, 2014
 *      Author: jigar
 */

#include "Node.h"

Node::Node() {
	// TODO Auto-generated constructor stub
	this->parent = NULL;
	this->start = -1;
	this->end = -2;
	this->bit = 0;
}

Node::~Node() {
	// TODO Auto-generated destructor stub
}

bool Node::isBit() const {
	return bit;
}

void Node::setBit(bool bit) {
	this->bit = bit;
}

int Node::getEnd() const {
	return end;
}

void Node::setEnd(int end) {
	this->end = end;
}

Node*& Node::getParent() {
	return parent;
}

void Node::setParent(Node*& parent) {
	this->parent = parent;
}

int Node::getStart() const {
	return start;
}

void Node::setStart(int start) {
	this->start = start;
}

int Node::getEndValue(int start, int end) {
	long int sum = 0;
	float runningSum = 0;
	for (int i = start; i <= end; i++) {
		sum += symbolFreq[i];
	}
	int i = 0;
	for (i = start; i <= end; i++) {
		if (runningSum / sum >= 0.5) {
			break;
		} else {
			runningSum += symbolFreq[i];
		}
	}
	return --i;
}
