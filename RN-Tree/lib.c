#include "lib.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>

void rotate(Node *z, Node **root, Node *external)
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
                    left_rotate(z, &(*root), external);
                }
                z->dad->color = BLACK;
                z->dad->dad->color = RED;
                right_rotate(z->dad->dad, &(*root), external);
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
                    right_rotate(z, &(*root), external);
                }
                z->dad->dad->color = RED;
                z->dad->color = BLACK;
                left_rotate(z->dad->dad, &(*root), external);
            }
        }
    }
    (*root)->color = BLACK;
}

void left_rotate(Node *x, Node **root, Node *external)
{
    Node *y = x->right;
    x->right = y->left;
    if (y->left != external)
        y->left = x;
    y->dad = x->dad;
    if (x->dad == external)
        *root = y;
    else if (x == x->dad->left)
        x->dad->left = y;
    else
        x->dad->right = y;
    y->left = x;
    x->dad = y;
}

void right_rotate(Node *x, Node **root, Node *external)
{
    Node *y = x->left;
    x->left = y->right;
    if (y->right != external)
        y->right = x;

    y->dad = x->dad;

    if (x->dad == external)
        *root = y;
    else if (x == x->dad->right)
        x->dad->right = y;
    else
        x->dad->left = y;
    y->right = x;
    x->dad = y;
}

Node *create_external()
{
    Node *external = calloc(1, sizeof(Node));
    external->color = BLACK;
    external->dad = NULL;
    external->left = NULL;
    external->right = NULL;
    external->value = 0;

    return external;
}

Node *create_node(int value, Node *external)
{
    Node *node = calloc(1, sizeof(Node));
    node->left = external;
    node->right = external;
    node->dad = external;
    node->value = value;
    node->color = RED;

    return node;
}

void insert_RB(int value, Node **root, Node *external)
{
    Node *y = external, *x = *root;

    while (x != external)
    {
        y = x;
        if (value == x->value)
        {
            y = NULL;
            x = external;
        }
        else if (value < x->value)
            x = x->left;
        else
            x = x->right;
    }
    if (y != NULL)
    {
        Node *z = create_node(value, external);
        z->dad = y;
        if (y == external)
            *root = z;
        else if (z->value < y->value)
            y->left = z;
        else
            y->right = z;
        rotate(z, &(*root), external);
    }
}

void pre_order(Node *root, Node *external)
{
    if (root != external)
    {
        if (root->color == RED)
            printf("\033[1;31m%d\033[0m\n", root->value);
        else
            printf("\033[1;30m%d\033[0m\n", root->value);
    }
    if (root->left != external)
        pre_order(root->left, external);
    if (root->right != external)
        pre_order(root->right, external);
}

int count_nodes(Node *root, Node *external, int *nodes)
{
    if (root->left != external)
        count_nodes(root->left, external, nodes);

    if (root->right != external)
        count_nodes(root->right, external, nodes);

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
        Node *external = create_external();
        Node *root = external;
        int *vector = calloc(_10K, sizeof(int));

        fill_vector(vector, _10K);

        for (int j = 0; j < _10K; j++)
        {
            insert_RB(vector[j], &root, external);
        }

        count_nodes(root, external, &nodes);

        printf(">>>>>> Number of nodes: %d <<<<<<<\n", nodes);
        puts("=====================================");
        puts("");

        free_RB(&root, external);
        free(vector);
    }
}

void free_RB(Node **root, Node *external)
{
    if ((*root)->left != external)
        free_RB(&(*root)->left, external);
    if ((*root)->right != external)
        free_RB(&(*root)->right, external);

    free(*root);
}
