//MAX_HEAP Implementation
//
//File: Node.cpp
//
//Author: Eric Liang
//Website: http://www.eric-liang.com

#include "Node.h"
Node::Node(int d)
{
	data = d;
	parent = NULL;
	right = NULL;
	left = NULL;
}