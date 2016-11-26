//#include "node.h"
#include "btheap.h"

int main(void)
{
	char ch;
	Node *root, *last;
	//HEAP TREE CREATION
	Node *n1,*n2,*n3,*n4,*n5,*n6,*n7,*n8,*n9,*test,*fin ;
	/*
	n1 = (Node *) malloc( sizeof(Node) );
	n1->data = 1;
	n1->parent = NULL;
	n1->right = NULL;
	n1->left = NULL;
	*/
	n1 = InitialNode(1);
	//printf("n1->data= %d",n1->data);
	
	n2 = InitialNode(3); //Child swap
	n3 = InitialNode(5);
	n4 = InitialNode(7); //Lv1 New Level and Swap
	n5 = InitialNode(9);
	n6 = InitialNode(8);
	n7 = InitialNode(6);
	n8 = InitialNode(4);
	n9 = InitialNode(2);
	test = InitialNode(1000); //Tests for Perculate All the Way Up from Very Bottom
	fin = InitialNode(10); //Tests for New Root Node Case if Retrieve After Remove() once.

	InitialBTHeap(&root, &last, n1);
	//root = n1;
	//last = n1;	
	//printf("root->data= %d\n",root->data);
	
	//HEAP NODE INSERTION
	last = insert(root, n2);
	last = insert(root, n3);
	last = insert(root, n4);
	last = insert(root, n5);
	last = insert(root, n6);
	last = insert(root, n7);
	last = insert(root, n8);
	last = insert(root, n9);
	last = insert(root, test); 
	last = insert(root, fin);
    
	//printf("root->data= %d\n",root->data); 
	//printf("last->data= %d\n",last->data);
	 
	//Display Purposes
	printf ("Data Used: 1  3  5  7  9  8  6  4  2  1000  10\n");
    printf ("InorderTraversal: " );
	inorderTraversal(root);
	printf ("\n");
	//EMPTY CHECK
	if(empty(root))
		printf ("HEAP STATUS: EMPTY\n" );
	else
		printf ("HEAP STATUS: NOT EMPTY\n");

	//RETRIEVE LARGEST ITEM
	printf ("LARGEST NUMBER: \n");
	retrieve(root,last);

	//REMOVE LARGEST NODE
	printf ("CURRENT ROOT: \n"); 
	retrieve(root,last);
	last = heap_remove(root,last);
	
	printf ("InorderTraversal: ");
	inorderTraversal(root);
	printf("\n");
	
	printf ("NEW ROOT AFTER REMOVAL: ");
	retrieve(root,last);
	printf("\n");

	//HEAP SORT
	printf ("<<HEAP SORT BEGINS>>");

	retrieve(root,last);
	if(last != NULL)
		last = heap_remove(root,last);

	printf ("InorderTraversal: ");
	inorderTraversal(root);
	printf("\n");
	
	retrieve(root,last);
	if(last != NULL)
		last = heap_remove(root,last);

	printf ("InorderTraversal: ");
	inorderTraversal(root);
	printf("\n");
	
	retrieve(root,last);
	if(last != NULL)
		last = heap_remove(root,last);

	printf ("InorderTraversal: ");
	inorderTraversal(root);
	printf("\n");
	
	retrieve(root,last);
	if(last != NULL)
		last = heap_remove(root,last);

	printf ("InorderTraversal: ");
	inorderTraversal(root);
	printf("\n");
	
	retrieve(root,last);
	if(last != NULL)
		last = heap_remove(root,last);

	printf ("InorderTraversal: ");
	inorderTraversal(root);
	printf("\n");
	
	retrieve(root,last);
	if(last != NULL)
		last = heap_remove(root,last);

	printf ("InorderTraversal: ");
	inorderTraversal(root);
	printf("\n");
	
	retrieve(root,last);
	if(last != NULL)
		last = heap_remove(root,last);

	printf ("InorderTraversal: ");
	inorderTraversal(root);
	printf("\n");
	
	retrieve(root,last);
	if(last != NULL)
		last = heap_remove(root,last);

	printf ("InorderTraversal: ");
	inorderTraversal(root);
	printf("\n");
	
	retrieve(root,last);
	if(last != NULL)
		last = heap_remove(root,last);

	printf ("InorderTraversal: ");
	inorderTraversal(root);
	printf("\n");
	
	retrieve(root,last);
	if(last != NULL)
		last = heap_remove(root,last);

	if(last == NULL)
		root = NULL;
		
	printf ("InorderTraversal: ");
	inorderTraversal(root);
	printf("\n");
	
	retrieve(root,last);
	if(last != NULL)
		last = heap_remove(root,last);

	ch = getchar();
	return 0;
}
