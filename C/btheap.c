#include "btheap.h"

void InitialBTHeap(Node** root, Node** last,Node* r)
{	
	*root = r;
	*last = r;
}

int empty(Node* root)
{
	if (root == NULL)
		return 1;
	else
		return 0;
}

Node* insert(Node *root, Node *n)
{
	Node *ret;
	Node *last;
	
	last = n;
	ret = posorderinsert(root);
	//printf ("ret->data= %d\n",ret->data);
	n->parent = ret;
	ret->left = n;
	perculateUp(n->parent,n);
	
	return last;
}

void perculateUp(Node *p, Node *n)
{
	/*
	if(n->data > p->data)
	{
		int temp = p->data;
		p->data = n->data;
		n->data = temp;
	}
	*/
	DataSWapNode(p,n);
	if(p->parent != NULL)
		perculateUp(p->parent, p);
}


Node* remove(Node *root, Node *last)
{
	int temp;
	Node *tempLast;
	
	if(root == last){
		root = NULL;
		last = NULL;
		return NULL;
	}	
	tempLast = last;
	temp = root->data;
	root->data = last->data;
	last->data = temp;
	
	if (last == tempLast->parent->left){
		
		if(last->parent->right !=NULL)
			last = tempLast->parent->right;
		else
			last = tempLast->parent;
			
		tempLast->parent->left = NULL;
		//free(tempLast);	
		
	} else {
	
		if(last->parent->left !=NULL)
			last = tempLast->parent->left;
		else
			last = tempLast->parent;
	
		tempLast->parent->right = NULL;
		//free(tempLast);	
	}	
	
	posorderremove(root);
	

	return last;
}

void posorderremove(Node *Tree) // LRV
{
	Node *ret;
	int temp;
	ret = Tree;
	if( Tree->left !=  NULL ){   // Empty tree?
		if(Tree->left->data > Tree->data)
		{//LEFT > PARENT -> SWAP!
			temp = Tree->data;
			Tree->data = Tree->left->data;
			Tree->left->data = temp;
		}		
		posorderremove(Tree->left);  // Traversal the left sub-tree
	}
	else if ( Tree->right !=  NULL ){
		if(Tree->right->data > Tree->data)
		{//LEFT > PARENT -> SWAP!
			temp = Tree->data;
			Tree->data = Tree->left->data;
			Tree->right->data = temp;
		}
		posorderremove(Tree->right); // Traversal the right sub-tree
	}
	//printf("%d,",Tree->data);    // Traversal current node
	return ;
} // end of function inorderTraversal


void inorderTraversal(Node *Tree) // LVR
{
	if( Tree ==  NULL ) return;  // Empty tree?
	inorderTraversal(Tree->left);  // Traversal the left sub-tree
	printf("%d,",Tree->data);    // Traversal current node
	inorderTraversal(Tree->right); // Traversal the right sub-tree
} // end of function inorderTraversal

void retrieve(Node *root,Node *last)
{
	if(empty(root))
		printf ("Tree is Empty!\n");
	else if(last == NULL)
		printf ("Tree is Empty!\n");
	else
		printf ("Pop max data out: %d \n",root->data);
}

Node* posorderinsert(Node *Tree) // LRV
{
	Node *ret;
	ret = Tree;
	if( Tree->left !=  NULL )   // Empty tree?
	ret = posorderinsert(Tree->left);  // Traversal the left sub-tree
	else if ( Tree->right !=  NULL )
	ret = posorderinsert(Tree->right); // Traversal the right sub-tree
	
	//printf("%d,",Tree->data);    // Traversal current node
	return ret;
} // end of function inorderTraversal
