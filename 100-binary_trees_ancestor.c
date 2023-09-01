#include "binary_trees.h"

/**
* queue_create - Creates a new queue node.
* @node: The binary tree node to associate with the queue node.
* Return: A pointer to the created queue node.
*/
queue_t *queue_create(binary_tree_t *node)
{
queue_t *new_node = malloc(sizeof(queue_t));
if (new_node == NULL)
return (NULL);
new_node->node = node;
new_node->next = NULL;
return (new_node);
}

/**
* queue_push - Pushes a node into the queue.
* @queue: A double pointer to the queue.
* @node: The binary tree node to push into the queue.
*/
void queue_push(queue_t **queue, binary_tree_t *node)
{
if (queue == NULL || node == NULL)
return;

queue_t *new_node = queue_create(node);
if (new_node == NULL)
return;

new_node->next = *queue;
*queue = new_node;
}

/**
* queue_pop - Pops a node from the queue.
* @queue: A double pointer to the queue.
* Return: The binary tree node popped from the queue.
*/
binary_tree_t *queue_pop(queue_t **queue)
{
if (queue == NULL || *queue == NULL)
return (NULL);

queue_t *current = *queue;
*queue = current->next;
binary_tree_t *node = current->node;
free(current);
return (node);
}

/**
* binary_tree_levelorder - Traverse a binary tree using level-order traversal.
* @tree: A pointer to the root node of the tree to traverse.
* @func: A pointer to a function to call for each node's value.
* If tree or func is NULL, do nothing.
*/
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
if (tree == NULL || func == NULL)
return;

queue_t *queue = queue_create((binary_tree_t *)tree);
binary_tree_t *current;

while (queue != NULL)
{
current = queue_pop(&queue);

func(current->n);

if (current->left != NULL)
queue_push(&queue, current->left);

if (current->right != NULL)
queue_push(&queue, current->right);
}

/* Clean up */
while (queue != NULL)
{
queue_t *temp = queue;
queue = queue->next;
free(temp);
}
}

