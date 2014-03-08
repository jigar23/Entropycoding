#include "TreeManipulations.h"

//Global values define
std::vector<Tree*> treeElements;
std::vector<Tree*> leafNodes;

/**
 * This function gives birth to two new nodes
 * when a new symbol occurs.
 * the left child --> NYT node and
 * the right right --> new Symbol
 * @param:
 * 1. int value - value of the symbol
 */
void giveBirth(int value) {
	checkNodeForSwapping(512 - Tree::COUNT);
	Tree *par = treeElements.at(512 - Tree::COUNT);
	Tree *left = new Tree;
	Tree *right = new Tree;
	//Make it the intermediate node
	par->setValue(-1);
	par->setWeight(1);

	left->setParent(par);
	right->setParent(par);

	left->setWeight(0);
	right->setWeight(1);

	left->setValue(-2);
	right->setValue(value);

	right->setOrder(--Tree::COUNT);
	left->setOrder(--Tree::COUNT);

	par->setLeftChild(left);
	par->setRightChild(right);

	treeElements.push_back(right);
	treeElements.push_back(left);

	leafNodes.push_back(right);
}

/**
 * This function just prints all the tree params
 * present in the vector.
 */
void printAllVectors() {
	for (unsigned int i = 0; i < treeElements.size(); i++) {
		Tree *node = treeElements.at(i);
		cout << "Order : " << node->getOrder() << endl;
		cout << "Weight : " << node->getWeight() << endl;
		cout << "Value : " << (char) node->getValue() << endl;
		if (node->getParent() != NULL) {
			cout << "ParentOrder : " << node->getParent()->getOrder() << endl;
		} else {
			cout << "Parent : Root" << endl;
		}
		cout << "------------------" << endl;
	}

	cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
}

/**
 * This function is useful when swapping two
 * pointers.
 * In this we copy the contents of a pointer in a
 * new pointer,
 */
Tree* copyContentsinObject(Tree *node) {
	Tree *obj = new Tree;
	obj->setParent(node->getParent());
	obj->setOrder(node->getOrder());
	return obj;
}

/**
 * This function checks the sibling property if the symbol
 * is already present in the tree or the NYT's weight.
 * Note the vectors of tree elements are arranged
 * in descending order of 'Order'.
 * If Any of the vector having a higher weight has a lower order
 * than the vector with lower weight, then those two branches
 * are swapped.
 * @param:
 * 1. int pos - position in the vector of tree elements
 */
void checkNodeForSwapping(int pos) {
	Tree *current = treeElements.at(pos);
	int nextpos = -1;

	//root node
	if (pos == 0) {
		//increment the weight before returning.
		int wt = treeElements.at(pos)->getWeight();
		treeElements.at(pos)->setWeight(++wt);
//		printAllVectors();
		return;
	}

	for (int i = pos - 1; i >= 0; i--) {
		Tree *nextT = treeElements.at(i);
		//previous weight bigger, then break.
		//else get the position
		if (nextT->getWeight() > current->getWeight())
			break;
		//dont check if parent
		else if (current->getParent() == nextT)
			continue;
		else
			nextpos = i;
	}
	//Swap the positions
	if (nextpos != -1) {
		Tree *swapTree = treeElements.at(nextpos);
		//copy contents in new pointer before swapping
		Tree *st = copyContentsinObject(swapTree);
		//Interchange the parent
		treeElements.at(nextpos)->setParent(current->getParent());
		treeElements.at(pos)->setParent(st->getParent());

		//Change the order
		treeElements.at(nextpos)->setOrder(current->getOrder());
		treeElements.at(pos)->setOrder(st->getOrder());

		//Change the positions in the vector array
		Tree *temp = treeElements.at(nextpos);
		treeElements.at(nextpos) = treeElements.at(pos);
		treeElements.at(pos) = temp;

		//increment the weight
		int wt = treeElements.at(nextpos)->getWeight();
		treeElements.at(nextpos)->setWeight(++wt);
		//Call its parent
		int parentPos =
				(512 - treeElements.at(nextpos)->getParent()->getOrder());
		checkNodeForSwapping(parentPos);
	}
	//dont swap and goto the parent
	else {
		int wt = treeElements.at(pos)->getWeight();
		treeElements.at(pos)->setWeight(++wt);
		int order = ((treeElements.at(pos)->getParent())->getOrder());
		int parentPos = 512 - order;
		checkNodeForSwapping(parentPos);
	}
}

/**
 * This function checks if the sybol is present in the leaf nodes.
 * If present, it returns the position of the symbol in the vector of tree
 * elements else returns -1 indicating that the symbol is not present in
 * the leaf node (i.e. new symbol)
 */
int findSymbol(int val) {
	int pos = -1;
	unsigned int i;
	for (i = 0; i < leafNodes.size(); i++) {
		if (val == leafNodes.at(i)->getValue())
			break;
	}
	//Symbol found
	if (i < leafNodes.size()) {
		int order = leafNodes.at(i)->getOrder();
		pos = 512 - order;
	}
	return pos;
}
