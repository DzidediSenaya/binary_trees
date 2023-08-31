#include <stdlib.h>
#include "binary_trees.h"

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 *
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 * Return: Pointer to the root node of the AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
    if (size == 0)
        return NULL;

    size_t middle = size / 2;

    avl_t *root = binary_tree_node(NULL, array[middle]);

    if (!root)
        return NULL;

    root->left = sorted_array_to_avl(array, middle);
    root->right = sorted_array_to_avl(array + middle + 1, size - middle - 1);

    return root;
}

