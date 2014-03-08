/*
 * Tree.cpp
 *
 *  Created on: Feb 1, 2014
 *      Author: jigar
 */

#include "Tree.h"

int Tree::COUNT = 512;

Tree::Tree() {
	// TODO Auto-generated constructor stub
	value = -1;
	order = -1;
	weight = 0;
	parent = NULL;
	leftChild = NULL;
	rightChild = NULL;
}

Tree* Tree::getLeftChild() const {
	return leftChild;
}

void Tree::setLeftChild(Tree* leftChild) {
	this->leftChild = leftChild;
}

int Tree::getOrder() const {
	return order;
}

void Tree::setOrder(int order) {
	this->order = order;
}

Tree* Tree::getParent() const {
	return parent;
}

void Tree::setParent(Tree* parent) {
	this->parent = parent;
}

Tree* Tree::getRightChild() const {
	return rightChild;
}

void Tree::setRightChild(Tree* rightChild) {
	this->rightChild = rightChild;
}

int Tree::getValue() const {
	return value;
}

void Tree::setValue(int value) {
	this->value = value;
}

int Tree::getWeight() const {
	return weight;
}

void Tree::setWeight(int weight) {
	this->weight = weight;
}

Tree::~Tree() {
	// TODO Auto-generated destructor stub
}

void Tree::printTree(Tree *node) {

	cout << "Order : " << node->getOrder() << endl;
	cout << "Weight : " << node->getWeight() << endl;
	cout << "Value : " << node->getValue() << endl;
	if (node->getParent() != NULL) {
		cout << "ParentOrder : " << node->getParent()->getOrder() << endl;
	} else {
		cout << "Parent : Root" << endl;
	}
	cout << "------------------" << endl;
	Tree *left = node->getLeftChild();
	Tree *right = node->getRightChild();

	if (left == NULL)
		return;
	else
		printTree(left);
	if (right == NULL)
		return;
	else
		printTree(right);

}
