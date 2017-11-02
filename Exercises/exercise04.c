/* Description of the content of the file and important remarks. *
 * File: <exercise04.c>                Author:  <Prithvi Raj Moorani>
 * Date: <31 October 2017>                     Version: <01>
 */

#include <stdio.h>
#include <stdlib.h>

struct Node* create_new_node (int data);
struct Node* insert_node (struct Node *root, int data);
void print_tree_pre_order (struct Node *root);
void print_tree_in_order (struct Node *root);
void print_tree_post_order (struct Node *root);
void delete_tree (struct Node *root);

struct Node
{
	int data;               // variable to store data in a node
	struct Node *left;                // pointer to left in a node
	struct Node *right;               // pointer to right in a node
};


struct Node* create_new_node (int data)
{
	/* Create New Node */
	struct Node *new_node = (struct Node*) malloc ( sizeof (struct Node) ); 
	
	new_node->data = data;                // Set the data 
	new_node->left = NULL;                // Set the left to NULL
	new_node->right = NULL;               // Set the right to NULL

	return new_node;                // Return the address of the new node.
}

/* Insert a node in Binary tree */
struct Node* insert_node (struct Node *root, int data)
{
	if (root == NULL)
	{
		root = create_new_node(data);               // root gets new node address
	}
	else if (data <= root->data)
	{
		/* Recursive call to insert_node function */
		root->left = insert_node (root->left, data);  
	}
	else
	{
		/* Recursive call to insert_node function */
		root->right = insert_node (root->right, data);  
	}

	return root;
}

/* Print Binary Tree nodes in Pre-Order Traversal*/
void print_tree_pre_order (struct Node *root)
{
	if (root == NULL)
	{
		return;
	}

	/* first print data of root */
	printf ("%d ", root->data);  

	/* then perform recursion on left subtree */
	print_tree_pre_order (root->left);  

	/* now perform recursion on right subtree */
	print_tree_pre_order (root->right);
}    

/* Print Binary Tree nodes in In-Order Traversal*/
void print_tree_in_order (struct Node *root)
{
	if (root == NULL)
	{
		return;
	}

	/* first perform recursion on left subtree */
	print_tree_in_order (root->left);

	/* then print the data of root */
	printf ("%d ", root->data);  

	/* then perform recursion on right subtree */
	print_tree_in_order (root->right);
}

/* Print Binary Tree nodes in Post-Order Traversal*/
void print_tree_post_order (struct Node *root)
{
	if (root == NULL)
	{ 
		return;
	}

	/* first perform recursion on left subtree */
	print_tree_post_order (root->left);

	/* then perform recursion on right subtree */
	print_tree_post_order (root->right);

	/* then print the data of root */
	printf ("%d ", root->data);
}

/* Delete Binary tree */
void delete_tree (struct Node *root)
{
	if (root == NULL)
	{
		return;
	}
	/* using recursion call to delete left subtree */
	delete_tree (root->left);

	/* using recursion call to delete right subtree */
  delete_tree (root->right);
  
  /* then delete the root */
  printf("\nDeleting root: %d", root->data);
  
  free (root);
}

int main (void)
{
	struct Node *root;            // Pointer to Root Node
	root = NULL;                // Set tree as empty

	root = insert_node (root, 50);                
	root = insert_node (root, 56);                
	root = insert_node (root, 46);                
	root = insert_node (root, 6);
	root = insert_node (root, 27);
	root = insert_node (root, 67);
	root = insert_node (root, 65);
	root = insert_node (root, 92);
	root = insert_node (root, 90);
	root = insert_node (root, 27);

	printf ("\nPre-Order: ");
	print_tree_pre_order (root);
	
	printf ("\nIn-Order: ");
	print_tree_in_order (root);
	
	printf ("\nPost-Order: ");
	print_tree_post_order (root);
	
	printf ("\n\n");
	delete_tree (root);
	root = NULL;

	printf ("\nTree deleted!\n");

	return 0;
}