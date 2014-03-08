#include "encodeSymbol.h"
codetable* encodeNewValue(int value, bool eof);
codetable* encodeValue(int pos);

/**
 * This is the main function which builds the adaptive huffman tree.
 */
void buildAHuffmanTree(char *val, int length, char *opFile) {

	//Prepare the file for writing (i.e open the file)
	writePrepare(opFile);

	//set root params
	Tree *root = new Tree;
	root->setValue(-2);
	root->setOrder(512);
	treeElements.push_back(root);

	codetable *ct = new codetable;
	for (int i = 0; i < length; i++) {
		//new symbol
		int pos = findSymbol(val[i]);
		if (pos == -1) {
			ct = encodeNewValue(val[i], 0);
			//give birth to new new nodes
			giveBirth(val[i]);
		} else {
			//symbol already present
			ct = encodeValue(pos);
			//check and swap if any branches are to be swapped.
			checkNodeForSwapping(pos);
		}
//		cout << "Symbol is " << val[i] << " code is :" << ct->getCode() << " with size : " << (int)ct->getSize() << endl;
//		cout << printBitStream(ct->getCode(), ct->getSize()) << endl;
		writeSingleCode(ct->getCode(), ct->getSize());
	}

	ct = encodeNewValue('a', 1);
//	cout << "Symbol is " << 'a' << " code is :" << ct->getCode() << " with size : " << (int)ct->getSize() << endl;
//		cout << codetable::printBitStream(ct->getCode(), ct->getSize()) << endl;

	writeSingleCode(ct->getCode(), ct->getSize());

	checkStatusOfLastBit();

	closeFile();
}

/**
 * This function encodes a values which is
 * already present in the tree and returns the
 * codeword.
 */
codetable* encodeValue(int pos) {
	codetable *ct = new codetable;
	long unsigned code = 0;
	unsigned char size = 0;

	do {
		code = code << 1;
		size++;
		if ((treeElements.at(pos)->getOrder() % 2) != 0)
			code = (code | 1);
		pos = (512 - treeElements.at(pos)->getParent()->getOrder());
	} while (treeElements.at(pos)->getParent() != NULL);

	ct->setCode(code);
	ct->setSize(size);
	return ct;
}

/**
 * This function encodes new values which is
 * not present in the tree and returns the
 * codeword.
 */

codetable* encodeNewValue(int value, bool eof) {
	codetable *ct = new codetable;
	long unsigned code = 0;
	unsigned char size = 0;

	if (eof) {
		code = (code | 1);
	}
	size++;
	//Write the value in reverse order first
	//This is useful while writing in the file. SInce
	//the data is read in reverse fashion.
	for (int i = 0; i < 8; i++) {
		code = code << 1;
		size++;
		if ((value & (128 >> i)))
			code = (code | 1);

	}

	int pos = 512 - Tree::COUNT;

	//If root node then skip
	if (treeElements.at(pos)->getParent() != NULL) {
		while (treeElements.at(pos)->getParent() != NULL) {
			code = code << 1;
			size++;
			if ((treeElements.at(pos)->getOrder() % 2) != 0)
				code = (code | 1);
			pos = (512 - treeElements.at(pos)->getParent()->getOrder());
		}
	}
	ct->setCode(code);
	ct->setSize(size);
	return ct;

}
