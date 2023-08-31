#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 *
 * @tree: Pointer to the root node of the tree to measure
 *
 * Return: The height of the tree, 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    if (tree) /*If tree is not NULL*/
    {
        size_t l = 0, r = 0; /*Declare variables to store left and right heights*/

        /*Calculate the height of the left subtree*/
        l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
        
        /* Calculate the height of the right subtree*/
        r = tree->right ? 1 + binary_tree_height(tree->right) : 0;
        
        /*Return the maximum of the two heights plus 1 (to count the current node)*/
        return ((l > r) ? l : r);
    }
    
    return (0); /*If tree is NULL, return 0*/
}
