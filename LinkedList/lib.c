#include <stdio.h>
#include "lib.h"
#include <stdlib.h>

Node *create_node(int value)
{
    Node *node = calloc(1, sizeof(Node));
    node->next = NULL;
    node->prev = NULL;
    node->value = value;

    return node;
}

LinkedList *init_linked_list()
{
    LinkedList *linked_list = calloc(1, sizeof(LinkedList));
    linked_list->init = NULL;

    return linked_list;
}

void insert_at_end(LinkedList *linked_list, int value)
{
    Node *node = create_node(value);

    if (linked_list->init == NULL)
    {
        linked_list->init = node;
        linked_list->end = node;
    }
    else
    {
        Node *aux = linked_list->end;
        aux->next = node;
        linked_list->end = node;
        node->prev = aux;
    }
}

void insert_at_beginning(LinkedList *linked_list, int value)
{
    Node *node = create_node(value);

    if (linked_list->init == NULL)
    {
        linked_list->init = node;
        linked_list->end = node;
    }
    else
    {
        Node *aux = linked_list->init;

        aux->prev = node;
        node->next = aux;
        linked_list->init = node;
    }
}
void print(Node *node)
{
    printf("%d\n", node->value);
    if (node->next != NULL)
        print(node->next);
}

void reverse_print(Node *node)
{
    printf("%d\n", node->value);
    if (node->prev != NULL)
        reverse_print(node->prev);
}

int search(Node *node, int value)
{
    while (node->next != NULL && node->value != value)
        node = node->next;

    if (node->value == value)
        return value;
    else
        return -1;
}