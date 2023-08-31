#include "binary_trees.h"

/**
* create_bst_node - Creates a new BST node.
* @value: The value to store in the node.
* Return: A pointer to the created node, or NULL on failure.
*/
bst_t *create_bst_node(int value)
{
bst_t *new_node = binary_tree_node(NULL, value);
if (new_node == NULL)
return (NULL);
return (new_node);
}

/**
* insert_recursive - Recursively inserts a value into the BST.
* @parent: The parent node to attach the new node to.
* @value: The value to store in the node.
* Return: A pointer to the created node, or NULL on failure.
*/
bst_t *insert_recursive(bst_t *parent, int value)
{
if (value == parent->n)
return (NULL); /*value already present*/

if (value < parent->n)
{
if (parent->left == NULL)
return (create_bst_node(value));
return (insert_recursive(parent->left, value));
}
else
{
if (parent->right == NULL)
return (create_bst_node(value));
return (insert_recursive(parent->right, value));
}
}

/**
* bst_insert - Inserts a value into a Binary Search Tree (BST).
* @tree: A double pointer to the root node of the BST to insert the value.
* @value: The value to store in the node to be inserted.
* Return: A pointer to the created node, or NULL on failure.
*/
bst_t *bst_insert(bst_t **tree, int value)
{
if (tree == NULL)
return (NULL);

if (*tree == NULL)
{
*tree = create_bst_node(value);
return (*tree);
}

return (insert_recursive(*tree, value));
}

