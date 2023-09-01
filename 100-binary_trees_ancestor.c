#include "binary_trees.h"

/**
* binary_trees_ancestor - Finds the lowest common ancestor of two nodes.
*
* @first: Pointer to the first node.
* @second: Pointer to the second node.
*
* Return: Pointer to the lowest common ancestor node, or NULL if not found.
*/
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
const binary_tree_t *second)
{
if (first == NULL || second == NULL)
return (NULL);

binary_tree_t *ancestor = (binary_tree_t *)first;

while (ancestor != NULL)
{
binary_tree_t *temp = (binary_tree_t *)second;

while (temp != NULL)
{
if (temp == ancestor)
return (ancestor);

temp = temp->parent;
}

ancestor = ancestor->parent;
}

return (NULL);
}

