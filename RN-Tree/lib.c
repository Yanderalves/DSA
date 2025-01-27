#include "lib.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>

void rotate(Node *z, Node **root, Node *outside)
{
    while (z->dad->color == RED)
    {
        if (z->dad == z->dad->dad->left)
        {
            Node *y = z->dad->dad->right;
            if (y->color == RED)
            {
                z->dad->color = BLACK;
                y->color = BLACK;
                z->dad->dad->color = RED;
                z = z->dad->dad;
            }
            else
            {
                if (z == z->dad->right)
                {
                    z = z->dad;
                    left_rotate(z, &(*root), outside);
                }
                z->dad->color = BLACK;
                z->dad->dad->color = RED;
                right_rotate(z->dad->dad, &(*root), outside);
            }
        }
        else
        {
            Node *y = z->dad->dad->left;
            if (y->color == RED)
            {
                z->dad->color = BLACK;
                y->color = BLACK;
                z->dad->dad->color = RED;
                z = z->dad->dad;
            }
            else
            {
                if (z == z->dad->left)
                {
                    z = z->dad;
                    right_rotate(z, &(*root), outside);
                }
                z->dad->dad->color = RED;
                z->dad->color = BLACK;
                left_rotate(z->dad->dad, &(*root), outside);
            }
        }
    }
    (*root)->color = BLACK;
}

void left_rotate(Node *x, Node **root, Node *outside)
{
    Node *y = x->right;
    x->right = y->left;
    if (y->left != outside)
        y->left = x;
    y->dad = x->dad;
    if (x->dad == outside)
        *root = y;
    else if (x == x->dad->left)
        x->dad->left = y;
    else
        x->dad->right = y;
    y->left = x;
    x->dad = y;
}

void right_rotate(Node *x, Node **root, Node *outside)
{
    Node *y = x->left;
    x->left = y->right;
    if (y->right != outside)
        y->right = x;

    y->dad = x->dad;

    if (x->dad == outside)
        *root = y;
    else if (x == x->dad->right)
        x->dad->right = y;
    else
        x->dad->left = y;
    y->right = x;
    x->dad = y;
}

Node *outside()
{
    Node *outside = calloc(1, sizeof(Node));
    outside->color = BLACK;
    outside->dad = NULL;
    outside->left = NULL;
    outside->right = NULL;
    outside->value = 0;

    return outside;
}

Node *create_node(int value, Node *outside)
{
    Node *node = calloc(1, sizeof(Node));
    node->left = outside;
    node->right = outside;
    node->dad = outside;
    node->value = value;
    node->color = RED;

    return node;
}

void insert_RB(int value, Node **root, Node *outside)
{
    Node *y = outside, *x = *root;

    while (x != outside)
    {
        y = x;
        if (value == x->value)
        {
            y = NULL;
            x = outside;
        }
        else if (value < x->value)
            x = x->left;
        else
            x = x->right;
    }
    if (y != NULL)
    {
        Node *z = create_node(value, outside);
        z->dad = y;
        if (y == outside)
            *root = z;
        else if (z->value < y->value)
            y->left = z;
        else
            y->right = z;
        rotate(z, &(*root), outside);
    }
}

void pre_order(Node *root, Node *outside)
{
    if (root != outside)
    {
        if (root->color == RED)
            printf("\033[1;31m%d\033[0m\n", root->value);
        else
            printf("\033[1;30m%d\033[0m\n", root->value);
    }
    if (root->left != outside)
        pre_order(root->left, outside);
    if (root->right != outside)
        pre_order(root->right, outside);
}

int count_nodes(Node *root, Node *outside, int *nodes)
{
    if (root->left != outside)
        count_nodes(root->left, outside, nodes);

    if (root->right != outside)
        count_nodes(root->right, outside, nodes);

    *nodes = *nodes + 1;
}

void fill_vector(int *vector, int size)
{

    int i, j;
    for (i = 0, j = 0; i < _10K; i++, j += (rand() % 100) + 1)
    {
        vector[i] = j;
    }
}

void RB_tests()
{

    for (int i = 0; i < _1K; i++)
    {
        puts("=====================================");
        printf("========== Tree number: %d ==========\n", i + 1);

        int nodes = 0;
        Node *outsider = outside();
        Node *root = outsider;
        int *vector = calloc(_10K, sizeof(int));

        fill_vector(vector, _10K);

        for (int j = 0; j < _10K; j++)
        {
            insert_RB(vector[j], &root, outsider);
        }

        count_nodes(root, outsider, &nodes);

        printf(">>>>>> Number of nodes: %d <<<<<<<\n", nodes);
        puts("=====================================");
        puts("");

        free_RB(&root, outsider);
        free(vector);
    }
}

void free_RB(Node **root, Node *outside)
{
    if ((*root)->left != outside)
        free_RB(&(*root)->left, outside);
    if ((*root)->right != outside)
        free_RB(&(*root)->right, outside);

    free(*root);
}

void shuffle(int *array, int n)
{
    for (int i = n - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}