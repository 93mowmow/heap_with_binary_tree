# heap_with_binary_tree

This project include C&amp;C++ implementation of a Max heap with binary tree data structure.

The insert function is:
	Using LRV Traversal to add the new node as a leaf. And then, bobble up the node, swap it data with it's parent.
	
The remove function is:
	Swap the root and the last node, and then prun the last node. 
	Chose it's parent or the other child of it's parent as the new last node.
	Using LRV Traversal to swap down the root, and then the max value of node will be bobble up to the root.
