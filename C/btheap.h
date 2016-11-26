#include <stdio.h>
#include "node.h"

void InitialBTHeap(Node** root, Node** last,Node* r);
int empty(Node* root);
Node* insert(Node *root, Node *n);
void perculateUp(Node *p, Node *n);
Node* heap_remove(Node *root, Node *last);
void posorderremove(Node *Tree);
void inorderTraversal(Node *Tree);
void retrieve(Node *root,Node *last);
Node* posorderinsert(Node *Tree);
void HeapSort(Node *root, Node *last);