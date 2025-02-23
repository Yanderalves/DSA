#include "lib.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void rotate_insert(Node *z, Node **root, Node *external)
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
        y->left->dad = x;
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
        y->right->dad = x;

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
        rotate_insert(z, &(*root), external);
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
    for (i = 0, j = 0; i < size; i++, j += (rand() % 100) + 1)
    {
        vector[i] = j;
    }
}

void RB_tests()
{

    for (int i = 0; i < _1K; i++)
    {
        printf("========== Tree number: %d ==========\n", i + 1);

        int nodes = 0;
        Node *external = create_external();
        Node *root = external;
        int *vector = calloc(_10K, sizeof(int));

        fill_vector(vector, _10K);

        printf("Initial number of nodes: %d\n\n", nodes);

        for (int j = 0; j < _10K; j++)
        {
            insert_RB(vector[j], &root, external);
        }

        count_nodes(root, external, &nodes);
        printf("Total nodes after insertions: %d\n", nodes);
        printf("Is Red-Black Tree after insertions? %s\n\n", is_RB_tree(root, external) ? "Yes" : "No");

        for (int j = 0; j < _1K; j++)
        {
            remove_node(vector[j], &root, external);
        }

        nodes = 0;
        count_nodes(root, external, &nodes);
        printf("Total nodes after deletions: %d\n", nodes);
        printf("Is Red-Black Tree after deletions? %s\n", is_RB_tree(root, external) ? "Yes" : "No");

        puts("\n=====================================\n");

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

void move_dad(Node *u, Node *v, Node **root, Node *external)
{
    if (u->dad == external)
        (*root) = v;
    else
    {
        if (u == u->dad->left)
            u->dad->left = v;
        else
            u->dad->right = v;
    }
    v->dad = u->dad;
}

void remove_node(int value, Node **root, Node *external)
{
    Node *z = search(value, *root, external);
    if (z != external)
    {
        Node *y = z;
        Node *x;
        Color old_color = y->color;
        if (z->left == external)
        {
            x = z->right;
            move_dad(z, z->right, &(*root), external);
        }
        else if (z->right == external)
        {
            x = z->left;
            move_dad(z, z->left, &(*root), external);
        }
        else
        {
            y = successor(z->right, external);
            old_color = y->color;
            x = y->right;

            if (y->dad == z)
                x->dad = y;
            else
            {
                move_dad(y, y->right, &(*root), external);

                y->right = z->right;
                y->right->dad = y;
            }

            move_dad(z, y, &(*root), external);
            y->left = z->left;
            y->left->dad = y;
            y->color = z->color;
        }

        if (old_color == BLACK)
            rotate_remove(x, root, external);

        free(z);
    }
    else
        puts("Value not found");
}

Node *successor(Node *z, Node *external)
{
    Node *aux = z;
    while (aux->left != external)
    {
        aux = aux->left;
    }
    return aux;
}

Node *search(int value, Node *root, Node *external)
{
    while (root != external)
    {
        if (value < root->value)
            root = root->left;
        else if (value > root->value)
            root = root->right;
        else
            return root;
    }
    return external;
}

void rotate_remove(Node *x, Node **root, Node *external)
{
    Node *w = NULL;
    while (x != (*root) && x->color == BLACK)
    {
        if (x->dad->left == x)
        {
            w = x->dad->right;

            if (w->color == RED)
            {
                w->color = BLACK;
                x->dad->color = RED;
                left_rotate(x->dad, &(*root), external);
                w = x->dad->right;
            }
            if (w->left->color == BLACK && w->right->color == BLACK)
            {
                w->color = RED;
                x = x->dad;
            }
            else
            {
                if (w->right->color == BLACK)
                {
                    w->left->color = BLACK;
                    w->color = RED;
                    right_rotate(w, &(*root), external);
                    w = x->dad->right;
                }
                w->color = x->dad->color;
                x->dad->color = BLACK;
                w->right->color = BLACK;
                left_rotate(x->dad, &(*root), external);
                x = (*root);
            }
        }
        else
        {
            w = x->dad->left;

            if (w->color == RED)
            {
                w->color = BLACK;
                x->dad->color = RED;
                right_rotate(x->dad, &(*root), external);
                w = x->dad->left;
            }
            if (w->right->color == BLACK && w->left->color == BLACK)
            {
                w->color = RED;
                x = x->dad;
            }
            else
            {
                if (w->left->color == BLACK)
                {
                    w->right->color = BLACK;
                    w->color = RED;
                    left_rotate(w, &(*root), external);
                    w = x->dad->left;
                }
                w->color = x->dad->color;
                x->dad->color = BLACK;
                w->left->color = BLACK;
                right_rotate(x->dad, &(*root), external);
                x = (*root);
            }
        }
    }
    (*root)->color = BLACK;
}

int black_height(Node *root, Node *external)
{
    if (root == external)
        return 0;

    int hl = black_height(root->left, external);
    int hr = black_height(root->right, external);

    if (root->color == BLACK)
        return (hl > hr ? hl : hr) + 1;
    else
        return hl > hr ? hl : hr;
}

bool is_RB_tree(Node *root, Node *external)
{
    if (root == external)
        return true;

    int black_height_left = black_height(root->left, external);
    int black_height_right = black_height(root->right, external);

    return black_height_left == black_height_right;
}

void small_RB_tests()
{
    int nodes = 0;
    Node *external = create_external();
    Node *root = external;
    int *vector = calloc(_100, sizeof(int));

    fill_vector(vector, _100);

    printf("Initial number of nodes: %d\n\n", nodes);

    for (int j = 0; j < _100; j++)
    {
        insert_RB(vector[j], &root, external);
    }

    count_nodes(root, external, &nodes);
    printf("Total nodes after insertions: %d\n", nodes);
    printf("Is Red-Black Tree after insertions? %s\n\n", is_RB_tree(root, external) ? "Yes" : "No");

    for (int j = 0; j < _10; j++)
    {
        remove_node(vector[j], &root, external);
    }

    nodes = 0;
    count_nodes(root, external, &nodes);
    printf("Total nodes after deletions: %d\n", nodes);
    printf("Is Red-Black Tree after deletions? %s\n", is_RB_tree(root, external) ? "Yes" : "No");

    // puts("Print In Pre Order:");

    // pre_order(root, external);

    puts("\n=====================================\n");

    free_RB(&root, external);
    free(vector);
}
