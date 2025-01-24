#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

Queue *init_queue()
{
    Queue *queue = calloc(1, sizeof(Queue));
    return queue;
}

Node *init_node(int value)
{
    Node *node = calloc(1, sizeof(Node));
    node->value = value;
    node->next = NULL;

    return node;
}

void enqueue(Queue **queue, int value)
{
    Node *node = init_node(value);
    if ((*queue)->head == NULL)
    {

        (*queue)->head = node;
        (*queue)->last = node;
    }
    else
    {
        (*queue)->last->next = node;
        (*queue)->last = node;
    }
}

int dequeue(Queue **queue)
{
    if (*queue == NULL)
        return -1;

    if ((*queue)->head->next == NULL)
        (*queue)->last = NULL;

    int value = (*queue)->head->value;

    Node *aux = (*queue)->head;

    (*queue)->head = (*queue)->head->next;

    free(aux);

    return value;
}

void print(Node *node)
{
    if (node != NULL)
    {
        printf("%d\n", node->value);
        print(node->next);
    }
}

bool queue_is_empty(Queue *queue)
{
    if (queue->head == NULL)
        return true;
    return false;
}