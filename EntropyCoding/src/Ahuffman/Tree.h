/*
 * Tree.h
 *
 *  Created on: Feb 1, 2014
 *      Author: jigar
 */

#ifndef TREE_H_
#define TREE_H_
#include <stddef.h>
#include <iostream>
using namespace std;
class Tree {
	int value;
	int order;
	int weight;
	Tree *parent;
	Tree *leftChild;
	Tree *rightChild;

public:
	static int COUNT;
	Tree();
	virtual ~Tree();
	Tree* getLeftChild() const;
	void setLeftChild(Tree* leftChild);
	int getOrder() const;
	void setOrder(int order);
	Tree* getParent() const;
	void setParent(Tree* parent);
	Tree* getRightChild() const;
	void setRightChild(Tree* rightChild);
	int getValue() const;
	void setValue(int value);
	int getWeight() const;
	void setWeight(int weight);
	static void printTree(Tree*);
};

#endif /* TREE_H_ */
