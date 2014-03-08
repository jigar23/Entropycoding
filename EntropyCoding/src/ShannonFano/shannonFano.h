/*
 * shannonFano.h
 *
 *  Created on: Jan 27, 2014
 *      Author: jigar
 */

#ifndef SHANNONFANO_H_
#define SHANNONFANO_H_
#include <iostream>
#include "Node.h"
#include "SFTable.h"
#include "../CodeTable/codetable.h"

Node** ShannonTree();
void buildShannonTree(Node *node);
codetable getCodeWordForSymbol(Node **list, int symbol);

#endif /* SHANNONFANO_H_ */
