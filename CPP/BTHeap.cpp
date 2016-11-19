//MAX_HEAP Implementation
//
//File: BTHeap.cpp
//
//Author: Eric Liang
//Website: http://www.eric-liang.com

#include "BTHeap.h"
#include "Node.h"
#include <iostream>
using namespace std;

BTHeap::BTHeap(Node* r)
{	
	root = r;
	no_of_nodes = 0;
}
bool BTHeap::empty()
{
	if (root == NULL)
		return true;
	else
		return false;
}

#ifdef new_imp
void BTHeap::insert(Node*r, Node *n)
{
	Node *ret;
	
	//cout <<  "in insert (new)" << endl;
	last = n;
	ret = posorderinsert(r);
	cout <<  "ret->data= " << ret->data <<endl;
	n->parent = ret;
	ret->left = n;
	
	perculateUp(n->parent,n);
}
#else
void BTHeap::insert(Node*r, Node *n)
{	
	last = n;
	if(r->parent == NULL) //ROOT
	{
		if(r->left == NULL) //LEFT IS NULL
		{
			n->parent = r;
			r->left = n;
			if(n->data > r->data) //CHILD > PARENT?
			{ //but doesn't this way of things mean the nodes swap location but parent pointer still points to old location??? :X PROBLEM!
				int temp;
				temp = r->data;
				r->data = n->data;
				n->data = temp;
			}
		}
		else if(r->right == NULL) //RIGHT IS NULL
		{
			n->parent = r;
			r->right = n;
			if(n->data > r->data) //CHILD > PARENT?
			{
				int temp;
				temp = r->data;
				r->data = n->data;
				n->data = temp;
			}
		}
		else //LEFT AND RIGHT NOT NULL
		{
			insert(r->left, n);
		}
	}
	else //NOT A ROOT
	{
		if(r->left == NULL) //LEFT IS NULL
		{
			n->parent = r;
			r->left = n;
			perculateUp(r, n);
		}
		else if(r->right == NULL) //RIGHT IS NULL
		{
			n->parent = r;
			r->right = n;
			perculateUp(r, n);
		}
		else //LEFT AND RIGHT NOT NULL
		{
			if(r->parent->right == r)
			{//right sub-branch case -- maybe it's farthest right
				if(r->parent->parent != NULL)
				{
					if(r->parent->parent->right == r->parent) //right most case
					{//right most case
						Node *traverser;
						traverser = root;
						Node *leftMostNode = levelDown(traverser);
						insert(leftMostNode, n);
					}
					else
					{
						insert(r->parent->parent->right->left, n);
					}
				}
				else if(r->parent->parent == NULL)
				{
					Node *traverser;
					traverser = root;
					Node *leftMostNode = levelDown(traverser);
					insert(leftMostNode, n);
				}
			}
			else if(r->parent->right != r)
			{//left sub-branch case
				insert(r->parent->right, n);
			}
		}
	}
	
	no_of_nodes++;
}
#endif
void BTHeap::perculateUp(Node *p, Node *n)
{
	if(n->data > p->data)
	{
		int temp = p->data;
		p->data = n->data;
		n->data = temp;
	}
	if(p->parent != NULL)
		perculateUp(p->parent, p);
}

Node* BTHeap::levelDown(Node *t)
{
	Node *ret;
	if(t->left != NULL)
		ret = levelDown(t->left);
	else
		ret = t;
	
	return ret;
}

void BTHeap::retrieve()
{
	if(this->empty()) //Tree is Empty Safeguard
	{
		cout << "Tree is Empty!" << endl;
	}
	else
	{
		cout << root->data << " " << endl;
	}
}

Node* BTHeap::levelDownRight(Node *t)
{
	Node *ret;
	if(t->right != NULL)
		ret = levelDownRight(t->right);
	else
		ret = t;
	
	return ret;
}
#ifdef new_imp
void BTHeap::remove()
{
	int temp;
	Node *tempLast;
	
	if(root == last){
		root = NULL;
		last = NULL;
		return;
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
}
#else
void BTHeap::remove()
{
	int i = 0;
	if(root != last)
	{
		Node *tempLast;
		int temp;
		if(root->left == last) //root + left child left
		{
			tempLast = root;
			temp = root->data;
			root->data = last->data;
			last->data = temp;
			last = NULL;
			last = tempLast;
		}
		else if(root->right == last)
		{
			tempLast = root->left;
			temp = last->data;
			last->data = root->data;
			root->data = temp;
			if(root->left->data > root->data)
			{
				temp = root->left->data;
				root->left->data = root->data;
				root->data = temp;
			}
			
			Node *leftMostNode = levelDown(tempLast);
			tempLast = leftMostNode;

			last->parent->right = NULL;
			
			last = NULL;
			last = tempLast;
			
		}
		else
		{
			temp = root->data;
			root->data = last->data;
			last->data = temp;
			tempLast = last;
			//REASSIGN LAST
			
			//check which child (L or R)
			//then determine whether you need to go up and outer
			//assume small tree
			//then large tree

			if(last->parent->left == last) //L child
			{//need to travel out
				if(last->parent->parent->left != last->parent)
				{//no need to travel super out, just stay within 
					tempLast = last->parent->parent->left->right;
				}
				else
				{//must travel out as long as not left most half of tree
					if(last->parent->parent != root)
					{
						if(last->parent->parent->parent->left != last->parent->parent)
						{
							tempLast = last->parent->parent->parent->left->right->right;
						}
						else
						{//must go up one level's last item as tempLast
							//travel down right
							Node *rLast = levelDownRight(root);
							if(rLast != root)
								tempLast = rLast;
							else
								tempLast = last->parent;
						}
					}
					else
					{
						if(last->parent->parent->left->right != NULL)
							tempLast = last->parent->parent->left->right;
						else
							tempLast = last->parent->parent->left;
					}
				}
			}
			else //R child
			{//no need to jump out
				Node *leftMostNode = levelDown(last->parent);
			    tempLast = leftMostNode;
			}

			//END
			if(last->parent->right == last)
				last->parent->right = NULL;
			else if(last->parent->left == last)
				last->parent->left = NULL;
				
			last = NULL;
			last = tempLast;
			
			for(i=0;i<no_of_nodes;i++)
				perculateDown(root);
		}
	}
	else //Root Remains
	{
		root = NULL;
		last = NULL;
	}
	
	no_of_nodes--;
}
#endif
void BTHeap::perculateDown(Node *p)
{
	int temp;
	if(p->left == NULL) //LEFT NULL -- p is last node AND no right node
	{
		//nothing happens
	}
	else //LEFT NOT NULL
	{
		if(p->right != NULL) //RIGHT NOT NULL
		{
			//compare left to right to find out which is bigger
			if(p->left->data > p->right->data)
			{//LEFT BIGGER THAN RIGHT
				//LEFT vs PARENT
				if(p->left->data > p->data)
				{//LEFT > PARENT -> SWAP!
					temp = p->data;
					p->data = p->left->data;
					p->left->data = temp;
					perculateDown(p->left);
				}
			}
			else
			{//RIGHT BIGGER THAN LEFT
				//RIGHT vs PARENT
				if(p->right->data > p->data)
				{//RIGHT > PARENT -> SWAP!
					temp = p->data;
					p->data = p->right->data;
					p->right->data = temp;
					perculateDown(p->right);
				}
			}
		}
		else //RIGHT NULL
		{
			//left compare to parent -- because outermost checked for left's existence, in here left is guaranteed to exist
			if(p->left->data > p->data)
			{//SWAP
				temp = p->data;
				p->data = p->left->data;
				p->left->data = temp;
				perculateDown(p->left);
			}
		}
	}
}

void BTHeap::HeapSort()
{
	while(!empty())
	{
		retrieve();
		remove();
	}
}

void BTHeap::inorderTraversal(Node *Tree) // LVR
{
	if( Tree ==  NULL ) return;  // Empty tree?
	inorderTraversal(Tree->left);  // Traversal the left sub-tree
	//printf("%d,",Tree->data);    // Traversal current node
	cout << Tree->data << "," ;
	inorderTraversal(Tree->right); // Traversal the right sub-tree
} // end of function inorderTraversal

void BTHeap::posorderTraversal(Node *Tree) // LRV
{
	if( Tree ==  NULL ) return;  // Empty tree?
	inorderTraversal(Tree->left);  // Traversal the left sub-tree
	inorderTraversal(Tree->right); // Traversal the right sub-tree
	cout << Tree->data << "," ;
	//printf("%d,",Tree->data);    // Traversal current node
	
} // end of function inorderTraversal

Node* BTHeap::posorderinsert(Node *Tree) // LRV
{
	Node *ret;
	ret = Tree;
	if( Tree->left !=  NULL )   // Empty tree?
	ret = posorderinsert(Tree->left);  // Traversal the left sub-tree
	else if ( Tree->right !=  NULL )
	ret = posorderinsert(Tree->right); // Traversal the right sub-tree
	
	cout << Tree->data << "," ;
	//printf("%d,",Tree->data);    // Traversal current node
	return ret;
} // end of function inorderTraversal


void BTHeap::posorderremove(Node *Tree) // LRV
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
	cout << Tree->data << "," ;
	//printf("%d,",Tree->data);    // Traversal current node
	return ;
} // end of function inorderTraversal
