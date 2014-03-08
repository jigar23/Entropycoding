#include "shannonFano.h"

int count = 0;
Node **list;

Node** ShannonTree() {
	list = new Node*[no_of_symbols];
	Node *rootNode = new Node;
	rootNode->setStart(0);
	rootNode->setEnd(no_of_symbols - 1);
	buildShannonTree(rootNode);
	return list;

}
/**
 * This function build the Shannon tree given the root node.
 * Procedure is explained in the README file.
 */

void buildShannonTree(Node *node) {

	if (node->getEnd() != node->getStart()) {
		//Get the split point
		int end = node->getEndValue(node->getStart(), node->getEnd());
		Node *leftNode = new Node;
		Node *rightNode = new Node;

		//set the start and end value for left and right node.
		leftNode->setStart(node->getStart());
		leftNode->setEnd(end);
		rightNode->setStart(end + 1);
		rightNode->setEnd(node->getEnd());

		//bit 0 for left node, bit 1 for right node.
		leftNode->setBit(0);
		rightNode->setBit(1);

		//set the current node as the parent node for
//		both left and right child
		leftNode->setParent(node);
		rightNode->setParent(node);

		//recurse the procedure for left and right nodes
		buildShannonTree(leftNode);
		buildShannonTree(rightNode);
	} else {
		//maintain a list of all leaf nodes.
		list[count++] = node;
	}
}

/**
 * This function returns a codeword for the symbol given
 * in the parameter list from list of leaf nodes.
 */

codetable getCodeWordForSymbol(Node **list, int symbol) {
	unsigned long code = 0;
	unsigned char size = 0;
	//create an object of codetable.
	codetable ht;
	int i = symbol;

	Node *temp = list[i];
	// Check if bit is set, If Yes, then set corresponding bit in code as 1.
	// else let it remain 0.
	if (temp->isBit()) {
		code = (code | 1);
	}
	//increment size and point to the temp node
	size++;
	temp = temp->getParent();

	//if next parent is null, then return else got inside while loop
	if (temp == NULL) {
		ht.setCode(code);
		ht.setSize(size);
		return ht;
	}
	code = code << 1;
	//iterate till the next node is NULL
	while (temp->getParent() != NULL) {
		if (temp->isBit()) {
			code = (code | 1);
		}

		temp = temp->getParent();
		size++;
		if (temp->getParent() != NULL)
			code = code << 1;
	}

	ht.setCode(code);
	ht.setSize(size);
	// No need to set the symbol value
	// as it is already being set while calling
	return ht;

}

