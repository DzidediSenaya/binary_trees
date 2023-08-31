#include "binary_trees.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

binary_tree_t *queue_enqueue_dequeue(queue_t **queue, binary_tree_t *node)

/**
 * queue_enqueue_dequeue - Enqueues a node and dequeues the front node if needed.
 *
 * @queue: A pointer to a pointer to the queue.
 * @node: The binary tree node to be enqueued.
 *
 * Return: The dequeued binary tree node, or NULL if the queue is empty.
 */
binary_tree_t *queue_enqueue_dequeue(queue_t **queue, binary_tree_t *node)
{
    binary_tree_t *front_node = NULL;

    if (!*queue)
        return NULL;

    /*Enqueue the new node*/
    queue_node_t *new_node = malloc(sizeof(queue_node_t));
    if (!new_node)
        return NULL;

    new_node->node = node;
    new_node->next = NULL;

    if ((*queue)->rear)
        (*queue)->rear->next = new_node;
    else
        (*queue)->front = new_node;

    (*queue)->rear = new_node;

    /*Dequeue the front node if needed*/
    if ((*queue)->front) {
        front_node = (*queue)->front->node;
        queue_node_t *temp = (*queue)->front;
        (*queue)->front = (*queue)->front->next;
        free(temp);

        if (!(*queue)->front)
            (*queue)->rear = NULL;
    }

    return front_node;
}

/**
 * queue_is_empty - Checks if the queue is empty.
 *
 * @queue: A pointer to the queue.
 *
 * Return: 1 if the queue is empty, 0 otherwise.
 */
int queue_is_empty(const queue_t *queue)
{
    return queue ? queue->front == NULL : 1;
}

/**
 * queue_destroy - Destroys a queue and frees its memory.
 *
 * @queue: A pointer to the queue to be destroyed.
 */
void queue_destroy(queue_t *queue)
{
    while (queue && queue->front) {
        queue_node_t *temp = queue->front;
        queue->front = queue->front->next;
        free(temp);
    }

    free(queue);
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
enqueue(&queue, (binary_tree_t *)tree);

/* Traverse the tree using level-order traversal */
while (queue != NULL)
{
/* Dequeue a node and call the function on its value */
binary_tree_t *node = dequeue(&queue);
func(node->n);

/* Enqueue the left and right children if they exist */
if (node->left)
enqueue(&queue, node->left);
if (node->right)
enqueue(&queue, node->right);
}
}


