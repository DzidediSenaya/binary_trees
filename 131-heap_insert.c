#include "binary_trees.h"

/**
* find_insert_parent - Finds the parent for insertion in Max Binary Heap
*
* @node: Pointer to the root node
* Return: Pointer to the parent node
*/
heap_t *find_insert_parent(heap_t *node)
{
if (!node)
return (NULL);

if (!node->left || !node->right)
return (node);

if (binary_tree_is_perfect(node->left) &&
!binary_tree_is_perfect(node->right))
return (find_insert_parent(node->right));

return (find_insert_parent(node->left));
}

/**
* binary_tree_is_perfect - Checks if a binary tree is perfect
*
* @tree: Pointer to the root node
* Return: 1 if the tree is perfect, 0 otherwise
*/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
if (!tree)
return (0);

return (binary_tree_height(tree->left) == binary_tree_height(tree->right));
}

/**
* binary_tree_height - Calculates the height of a binary tree
*
* @tree: Pointer to the root node
* Return: Height of the tree
*/
size_t binary_tree_height(const binary_tree_t *tree)
{
size_t left_height, right_height;

if (!tree)
return (0);

left_height = binary_tree_height(tree->left);
right_height = binary_tree_height(tree->right);

return ((left_height > right_height) ? left_height + 1 : right_height + 1);
}

/**
* heapify_up - Performs heapify up operation after insertion
*
* @node: Pointer to the inserted node
*/
void heapify_up(heap_t *node)
{
while (node->parent && node->n > node->parent->n)
{
node->n ^= node->parent->n;
node->parent->n ^= node->n;
node->n ^= node->parent->n;

node = node->parent;
}
}

/**
* heap_insert - Inserts a value in Max Binary Heap
*
* @root: Double pointer to the root node of the Heap to insert the value
* @value: The value to store in the node to be inserted
* Return: Pointer to the created node, or NULL on failure
*/
heap_t *heap_insert(heap_t **root, int value)
{
heap_t *new_node, *parent;

if (!root)
return (NULL);

new_node = binary_tree_node(NULL, value);
if (!new_node)
return (NULL);

if (*root == NULL)
{
*root = new_node;
return (*root);
}

parent = find_insert_parent(*root);
new_node->parent = parent;

if (!parent->left)
{
parent->left = new_node;
}
else
{
parent->right = new_node;
}

heapify_up(new_node);

return (new_node);
}

