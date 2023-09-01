#include "binary_trees.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/**
* queue_enqueue_dequeue - Enqueues a node and dequeues
* the front node if needed.
* @queue: A pointer to a pointer to the queue.
* @node: The binary tree node to be enqueued.
*
* Return: The dequeued binary tree node, or NULL if the queue is empty.
*/
binary_tree_t *queue_enqueue_dequeue(queue_t **queue, binary_tree_t *node)
{
binary_tree_t *front_node = NULL;

if (!*queue)
return (NULL);

/* Enqueue the new node */
queue_node_t *new_node = malloc(sizeof(queue_node_t));
if (!new_node)
return (NULL);

new_node->node = node;
new_node->next = NULL;

if ((*queue)->rear)
(*queue)->rear->next = new_node;
else
(*queue)->front = new_node;

(*queue)->rear = new_node;

/* Dequeue the front node if needed */
if ((*queue)->front)
{
front_node = (*queue)->front->node;
queue_node_t *temp = (*queue)->front;
(*queue)->front = (*queue)->front->next;
free(temp);

if (!(*queue)->front)
(*queue)->rear = NULL;
}

return (front_node);
}

/**
* binary_tree_levelorder - Traverses a binary tree using level-order traversal.
*
* @tree: A pointer to the root node of the tree to traverse.
* @func: A pointer to a function to call for each node's value.
*/
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
if (tree == NULL || func == NULL)
return;

/* Create a queue to store nodes */
queue_t *queue = NULL;

/* Enqueue the root node */
queue_enqueue_dequeue(&queue, (binary_tree_t *)tree);

/* Traverse the tree using level-order traversal */
while (queue != NULL)
{
/* Dequeue a node and call the function on its value */
binary_tree_t *node = queue_enqueue_dequeue(&queue, NULL);
func(node->n);

/* Enqueue the left and right children if they exist */
if (node->left)
queue_enqueue_dequeue(&queue, node->left);
if (node->right)
queue_enqueue_dequeue(&queue, node->right);
}
}

