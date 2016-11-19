//MAX_HEAP Implementation
//
//File: BTHeap.h
//
//Author: Eric Liang
//Website: http://www.eric-liang.com

#pragma once
#include "Node.h"
#include <vector>
#define new_imp
class BTHeap
{
public:
	Node * root;
	Node * last;
	int no_of_nodes;
	
	BTHeap(Node*);
	bool empty();
	void perculateUp(Node *p, Node *n);
	Node* levelDown(Node *n);
	void perculateDown(Node *p);
	void insert(Node* r, Node* n);
	void retrieve();
	Node* levelDownRight(Node *n);
	void remove();
	void HeapSort();
	void inorderTraversal(Node *Tree);
	void posorderTraversal(Node *Tree);
	Node* posorderinsert(Node *Tree);
	void posorderremove(Node *Tree);
};
