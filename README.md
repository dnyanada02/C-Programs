# Binary Tree
Binary tree.cpp file consist of implementation of binary tree and various operations performed on a binary tree such as insert, delete, search, tree traversal, etc. A binary tree is a tree data structure in which each node has at most two children.

## Functions:
### Insert Node
This function is used for inserting a new node in the binary tree. Insert node function has 3 cases :-
- If node is already present.
- If the node we are inserting is first node i.e the root node.
- Else there are already nodes present in tree.

### Recursive Inorder, preorder, postorder
These functions perform the traversal of tree through recursive method (i.e by calling function again within the same function).
- Inorder (Left, Root, Right) 
- Preorder (Root, Left, Right) 
- Postorder (Left, Right, Root)

### Search
This function is used for searching a given node in the binary tree. This function returns output of: ‘node is present in tree’, ‘node is not present in tree’, ‘Tree is empty’.

### Delete
This function is used for deleting an existing node in the binary tree. delete node function has 3 cases: -
- Delete a leaf node.
- Delete a node with only one child.
- Delete a node with two children.

### Display
This function is used to display the created or modified binary tree.

### Non-Recursive Inorder, preorder, postorder
These functions perform the traversal of tree through non-recursive method. For non-recursive traversal I have used stack in this code.



