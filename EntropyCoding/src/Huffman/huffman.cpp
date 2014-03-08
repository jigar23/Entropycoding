#include "huffman.h"

/**
 * This function build the huffman tree and stores it in the
 * LLArray. <br />
 * Procedure for building the huffman tree has been explained in the
 * README file.
 * This can build a huffman tree with max 8 bits used to encode a
 * particular symbol.
 *
 * TO increase the limit, make changes in the file HuffmanTable.c
 *
 * @param - Node **LLArray - Array of Pointers of Node
 */
void buildHuffmanTree(NodeH **LLArray) {

	//set the initial values of the nodes.
	//Remember as the default constructor is called,
	//the next pointer is set to NULL, bit set to zero.
	//So no need to set these values.
	for (int i = 0; i < no_of_symbols; i++) {
		LLArray[i] = new NodeH;
		//Symbols are given numerical values.
		LLArray[i]->setSymbol(i);
		LLArray[i]->setProb(symbolFreq[i]);
	}

	//K value are the no. of iterations required for the main loop.
	//No of iterations = no_of_chars-1;
	int k = no_of_symbols;

	while (k > 1) {
		//Find the two small nodes
		int smallone = findSmaller(LLArray, -1);
		int smallTwo = findSmaller(LLArray, smallone);

		//Create a new Node, Calling the default constructor
		NodeH *newNode;
		newNode = new NodeH;

		//Prob of the new node = smallOne Prob + SamllTwo Prob
		int newProb = LLArray[smallone]->getProb()
				+ LLArray[smallTwo]->getProb();
		newNode->setProb(newProb);

		//New node symbol is ' ' which is used later to differentiate it.
		//newNode->setSymbol(' ' + Node::COUNT);
		newNode->setSymbol(' ');

		//Set the smallOne bit to 0.
		//Its prob = -1 (destroyed)
		//Make it point to the new node.
		LLArray[smallone]->setBit(0);
		LLArray[smallone]->setProb(-1);
		LLArray[smallone]->setNext(newNode);

		//Set the smallTwo bit to 1.
		LLArray[smallTwo]->setBit(1);
		LLArray[smallTwo]->setProb(-1);
		LLArray[smallTwo]->setNext(newNode);

		// Add new node to the Link List array and Increment the counter
		LLArray[NodeH::COUNT] = newNode;
		NodeH::COUNT++;
		k--;
	}

	//printAllNodeValues(LLArray);
}

/**
 * This function prints all the values in
 * the LinkList array.
 *
 * @param :
 * Node Pointer- which has the LinkList
 */
void printAllNodeValues(NodeH** LLArray) {
	NodeH node;
	for (int i = 0; i < NodeH::COUNT; i++) {
		node.printNode(LLArray[i]);
	}
}

/**
 * This function finds the minimum of the nodes
 * on the basis of its probability value.
 *
 * @param :
 * 1.  Node Pointer - which has the linkList
 * 2. int DifferentFrom - value = -1 if the node has been destroyed
 * or value = Previous smaller value.
 * Remember findSmaller function is used to find least
 * *two* small values. <br/>
 *
 * @return :
 * integer value which is the index of the
 * smaller value in the LLArray.
 */
int findSmaller(NodeH* LLArray[], int differentFrom) {
	//set the minimum as the first value
	//which is not -1 or last smaller value.
	int i, smaller;
	float min;
	int noOfNodes = NodeH::COUNT;
	for (i = 0; i < noOfNodes; i++) {
		if ((LLArray[i]->getProb() != -1) && (i != differentFrom)
				&& (LLArray[i]->getProb() != 0)) {
			min = LLArray[i]->getProb();
			smaller = i;
			break;
		}
	}
	//Check the next node
	i++;
	for (; i < noOfNodes; i++) {
		if (i == differentFrom)
			continue;
		if (LLArray[i]->getProb() == -1)
			continue;
		if (LLArray[i]->getProb() == 0)
			continue;
		// Less than equal to - so that new node that is created is given
		//preference if two prob values are same.
		if (LLArray[i]->getProb() <= min) {
			min = LLArray[i]->getProb();
			smaller = i;
		}
	}
//	cout << "smaller value is: " << min <<endl;
//	cout << "smaller position is: " << smaller <<endl;
	return smaller;
}

/**
 * This function returns the codeword for symbol sent.
 * CodeWords are stored in object of HuffmanTable which has following 3 values:
 * 1. unsigned char codeword - 8 bits in which the codeword is stored.
 * 2. unsigned char size - size of the codeword (Its a variable length coding
 * so the size info has to be present)
 * 3. int symbol - symbol.
 *
 * Codewords are stored in the variable codeword in *reverse* order
 * for simplicity.
 *
 * @param :
 * 1. Linked List Pointer - Node**
 * 2. int symbol - symbol for which the codeword is to be found
 *
 * @return : HuffmanTable object.
 *
 */

codetable getHuffmanCodeWordForSymbol(NodeH **LLArray, int symbol) {
	unsigned long code = 0;
	unsigned char size = 0;
	//create an object of codetable.
	codetable ht;
	//set the symbol to the sent argument
	ht.setSymbol(symbol);
	//Match the symbol ans return its codeword and size
	for (int i = 0; i < NodeH::COUNT; i++) {
		if (symbol == LLArray[i]->getSymbol()) {
			//store the symbol pointer in temp node.
			NodeH *temp = LLArray[i];
			// Check if bit is set, If Yes, then set corresponding bit in code as 1.
			// else let it remain 0.
			if (temp->isBit()) {
				code = (code | 1);
			}
			//increment size and point to the temp node
			size++;
			temp = temp->getNext();
			//If this is the last node then break;
			//else shift the bit to the left once.
//			if(temp->getNext() == NULL){
			if (temp == NULL) {
				break;
			}
			if (temp->getNext() == NULL) {
				break;
			}
			code = code << 1;
			//iterate till the next node is NULL
			while (temp->getNext() != NULL) {
				if (temp->isBit()) {
					code = (code | 1);
				}
//				else {
//					code = code*10 + 2;
//				}
				temp = temp->getNext();
				size++;
				if (temp->getNext() != NULL)
					code = code << 1;
			}

			break;
		}
	}
	//cout << "Code is : " << (int)code << "// size is: " << (int)size << endl;
	ht.setCode(code);
	ht.setSize(size);
//	code = reverse(code);
	return ht;

}

