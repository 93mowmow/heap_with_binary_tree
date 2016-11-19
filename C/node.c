#include "node.h"

Node *InitialNode(int d)
{
    Node *N;
	N = (Node *) malloc( sizeof(Node) );
	N->data = d;
	N->parent = NULL;
	N->right = NULL;
	N->left = NULL;
    return N;
} // end of function InitialNode


//if node->data > parent->data, then swap the value
void DataSWapNode(Node *p, Node *n)
{
    int temp;
	
	if(n->data > p->data)
	{
		temp = p->data;
		p->data = n->data;
		n->data = temp;
	}

} // end of function InitialNode
