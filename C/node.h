#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
	struct node *parent;
	struct node *right;
	struct node *left;
};

typedef struct node Node;

Node* InitialNode(int d);
void DataSWapNode(Node *p, Node *n);
