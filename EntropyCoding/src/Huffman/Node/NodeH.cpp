/*
 * NodeH.cpp
 *
 *  Created on: Jan 30, 2014
 *      Author: jigar
 */

#include "NodeH.h"

int NodeH::COUNT = 0;
NodeH::NodeH() {
	// TODO Auto-generated constructor stub
	this->bit = 0;
	this->next = NULL;
	this->prob = -1;
	this->symbol = -1;
}

bool NodeH::isBit() const {
	return bit;
}

void NodeH::setBit(bool bit) {
	this->bit = bit;
}

NodeH* NodeH::getNext() const {
	return next;
}

void NodeH::setNext(NodeH* next) {
	this->next = next;
}

float NodeH::getProb() const {
	return prob;
}

void NodeH::setProb(float prob) {
	this->prob = prob;
}

int NodeH::getSymbol() const {
	return symbol;
}

void NodeH::setSymbol(int symbol) {
	this->symbol = symbol;
}

NodeH::~NodeH() {
	// TODO Auto-generated destructor stub
}

void NodeH::printNode(NodeH* node) {
	cout << "Symbol: " << node->getSymbol() << endl;
	cout << "Probability: " << node->getProb() << endl;
	cout << "Bit Value: " << node->isBit() << endl;
	cout << "Current count: " << NodeH::COUNT << endl;
	// if next node is not set,  it is NULL
	if (node->next == NULL) {
		cout << "Next pointer is null" << endl;
	} else {
		cout << "Next pointer: " << node->next->getSymbol() << endl;
	}

	cout << "---------------" << endl;

}

