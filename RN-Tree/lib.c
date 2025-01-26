#include "lib.h"
#include <stdlib.h>
#include <stdio.h>

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