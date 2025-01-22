#include "lib.h"
#include <stdlib.h>
#include <stdio.h>

Stack *init_stack()
{
    return NULL;
}

Stack *init_node(int value)
{
    Stack *node = calloc(1, sizeof(Stack));
    node->next = NULL;
    node->value = value;
    return node;
}

void push(Stack **stack, int value)
{
    if (*stack == NULL)
        *stack = init_node(value);
    else
    {
        Stack *node = init_node(value);

        node->next = (*stack);
        (*stack) = node;
    }
}

int pop(Stack **stack)
{
    if (*stack == NULL)
    {
        puts("Stack is Empty. Unable to unstack");
        return -1;
    }
    int value = (*stack)->value;

    Stack *aux = *stack;

    (*stack) = (*stack)->next;

    free(aux);

    return value;
}

void print(Stack *stack)
{
    Stack *aux = stack;

    if (aux != NULL)
    {
        printf("%d\n", aux->value);
        aux = aux->next;
        print(aux);
    }
}
