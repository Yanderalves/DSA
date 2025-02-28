#include "lib.h"
#include <stdio.h>
#include <stdlib.h>

void insert_AVL(int value, Node **pt, char *is_modified_heigth)
{
    if (*pt == NULL)
    {
        *pt = create_node(value);
        *is_modified_heigth = 'V';
    }

    else
    {
        if (value == (*pt)->value)
        {
            return;
        }
        else if (value < (*pt)->value)
        {
            insert_AVL(value, &(*pt)->left, is_modified_heigth);
            if (*is_modified_heigth == 'V')
            {
                switch ((*pt)->bal)
                {
                case 1:
                    (*pt)->bal = 0;
                    *is_modified_heigth = 'F';
                    break;
                case 0:
                    (*pt)->bal = -1;
                    break;
                case -1:
                    rotate_left_insert(pt, is_modified_heigth);
                    break;

                default:
                    break;
                }
            }
        }
        else
        {
            insert_AVL(value, &(*pt)->rigth, is_modified_heigth);
            if (*is_modified_heigth == 'V')
            {
                switch ((*pt)->bal)
                {
                case -1:
                    (*pt)->bal = 0;
                    *is_modified_heigth = 'F';
                    break;
                case 0:
                    (*pt)->bal = 1;
                    break;
                case 1:
                    rotate_rigth_insert(pt, is_modified_heigth);
                    break;
                }
            }
        }
    }
}

void removeAVL(int value, Node **pt, char *is_modified_heigth)
{
    if ((*pt) == NULL)
    {
        puts("element does not exists");
        *is_modified_heigth = 'F';
    }
    else
    {
        if (value < (*pt)->value)
        {
            removeAVL(value, &(*pt)->left, is_modified_heigth);
            balance(pt, 'L', is_modified_heigth);
        }
        else
        {
            if (value > (*pt)->value)
            {
                removeAVL(value, &(*pt)->rigth, is_modified_heigth);
                balance(pt, 'R', is_modified_heigth);
            }
            else
            {
                Node *aux = (*pt);

                if ((*pt)->left == NULL)
                {
                    (*pt) = (*pt)->rigth;
                    *is_modified_heigth = 'V';
                }
                else
                {
                    if ((*pt)->rigth == NULL)
                    {
                        (*pt) = (*pt)->left;
                        *is_modified_heigth = 'V';
                    }
                    else
                    {
                        Node *s = (*pt)->rigth;

                        if (s->left == NULL)
                        {
                            s->left = (*pt)->left;
                            s->bal = (*pt)->bal;
                            (*pt) = s;
                            *is_modified_heigth = 'V';
                        }
                        else
                        {
                            Node *fatherS;
                            while (s->left != NULL)
                            {
                                fatherS = s;
                                s = s->left;
                            }
                            swap(pt, &fatherS->left);
                            removeAVL(value, &(*pt)->rigth, is_modified_heigth);
                            balance(pt, 'R', is_modified_heigth);
                        }
                        free(aux);
                    }
                }
            }
        }
    }
}

void balance(Node **pt, char where, char *is_modified_heigth)
{
    if (*is_modified_heigth == 'V')
    {
        if (where == 'R')
        {
            switch ((*pt)->bal)
            {
            case 1:
                (*pt)->bal = 0;
                break;
            case 0:
                (*pt)->bal = -1;
                *is_modified_heigth = 'F';
                break;
            case -1:
                rotate_left_remove(pt, is_modified_heigth);
                break;
            }
        }
        else
        {
            switch ((*pt)->bal)
            {
            case -1:
                (*pt)->bal = 0;
                break;
            case 0:
                (*pt)->bal = 1;
                *is_modified_heigth = 'F';
                break;
            case 1:
                rotate_rigth_remove(pt, is_modified_heigth);
                break;
            }
        }
    }
}

void swap(Node **pt, Node **fatherS)
{
    if (*pt == NULL || *fatherS == NULL)
    {
        return;
    }

    // Troca os nós completos, incluindo seus filhos e fatores de balanceamento
    Node *temp = *pt;
    *pt = *fatherS;
    *fatherS = temp;

    // Ajusta os filhos para manter a estrutura da árvore consistente
    Node *tempLeft = (*pt)->left;
    Node *tempRight = (*pt)->rigth;

    (*pt)->left = (*fatherS)->left;
    (*pt)->rigth = (*fatherS)->rigth;

    (*fatherS)->left = tempLeft;
    (*fatherS)->rigth = tempRight;
}

void rotate_left_insert(Node **pt, char *is_modified_heigth)
{
    Node *ptu = (*pt)->left;
    if (ptu->bal == -1)
    {
        (*pt)->left = ptu->rigth;
        ptu->rigth = (*pt);
        (*pt) = ptu;
        (*pt)->rigth->bal = 0;
    }
    else
    {
        Node *ptv = ptu->rigth;
        ptu->rigth = ptv->left;
        ptv->left = ptu;
        (*pt)->left = ptv->rigth;
        ptv->rigth = (*pt);
        if (ptv->bal == 1)
            ptu->bal = -1;
        else if (ptv->bal == -1)
        {
            (*pt)->bal = 1;
            ptu->bal = 0;
        }
        else
            ptu->bal = 0;
        (*pt)->bal = 0;
        (*pt) = ptv;
    }
    (*pt)->bal = 0;
    *is_modified_heigth = 'F';
}

void rotate_rigth_insert(Node **pt, char *is_modified_heigth)
{
    Node *ptu = (*pt)->rigth;

    if (ptu->bal == 1)
    {
        (*pt)->rigth = ptu->left;
        ptu->left = (*pt);
        (*pt) = ptu;
        ptu->left->bal = 0;
    }
    else
    {
        Node *ptv = ptu->left;

        ptu->left = ptv->rigth;
        ptv->rigth = ptu;
        (*pt)->rigth = ptv->left;
        ptv->left = (*pt);

        if (ptv->bal == 1)
        {
            (*pt)->bal = -1;
            ptu->bal = 0;
        }
        else if (ptv->bal == -1)
        {
            ptu->bal = 1;
        }
        else
        {
            ptu->bal = 0;
        }
        (*pt)->bal = 0;
        (*pt) = ptv;
    }
    (*pt)->bal = 0;
    *is_modified_heigth = 'F';
}

Node *create_node(int value)
{
    Node *node = malloc(sizeof(Node));
    node->left = NULL;
    node->rigth = NULL;
    node->value = value;
    node->bal = 0;
    return node;
}

int check_AVL(Node **root)
{
    int hl = 0, hr = 0, flag = 0, diff = 0;

    if ((*root) == NULL)
    {
        puts("Tree is Empty");
    }
    else
    {
        if ((*root)->left != NULL)
            flag = check_AVL(&(*root)->left);
        if ((*root)->rigth != NULL)
            flag = check_AVL(&(*root)->rigth);
    }

    hl = heigth(&(*root)->left);
    hr = heigth(&(*root)->rigth);

    diff = hr - hl;

    if (diff >= -1 && diff <= 1)
        flag = 1;
    else
        flag = 0;

    return flag;
}

int heigth(Node **root)
{

    int hl = 0, hr = 0;
    if (*root == NULL)
    {
        return -1;
    }
    if ((*root)->left == NULL && (*root)->rigth == NULL)
    {
        return 0;
    }
    if ((*root)->left != NULL)
        hl = heigth(&(*root)->left);
    if ((*root)->rigth != NULL)
        hr = heigth(&(*root)->rigth);

    return 1 + max_number(hl, hr);
}

void pre_ordem(Node *root)
{
    printf("%d\n", root->value);
    if (root->left != NULL)
        pre_ordem(root->left);
    if (root->rigth != NULL)
        pre_ordem(root->rigth);
}

void count_nodes(Node *root, int *nodes)
{
    if (root == NULL)
        return;
    if (root->left != NULL)
        count_nodes(root->left, nodes);
    if (root->rigth != NULL)
        count_nodes(root->rigth, nodes);
    *nodes = *nodes + 1;
}

int max_number(int a, int b)
{
    return a > b ? a : b;
}

void rotate_left_remove(Node **pt, char *is_modified_heigth)
{
    if (*pt == NULL || (*pt)->left == NULL)
    {
        return;
    }
    Node *ptu = (*pt)->left;

    if (ptu->bal <= 0)
    {
        (*pt)->left = ptu->rigth;
        ptu->rigth = (*pt);
        (*pt) = ptu;
        if (ptu->bal == -1)
        {
            ptu->bal = (*pt)->rigth->bal = 0;
            *is_modified_heigth = 'V';
        }
        else
        {
            ptu->bal = 1;
            (*pt)->rigth->bal = -1;
            *is_modified_heigth = 'F';
        }
    }
    else
    {
        Node *ptv = ptu->rigth;

        ptu->rigth = ptv->left;
        ptv->left = ptu;
        (*pt)->left = ptv->rigth;
        ptv->rigth = (*pt);
        (*pt) = ptv;
        switch (ptv->bal)
        {
        case -1:
            ptu->bal = 0;
            (*pt)->rigth->bal = 1;
            break;
        case 0:
            ptu->bal = 0;
            (*pt)->rigth->bal = 0;
            break;
        case 1:
            ptu->bal = -1;
            (*pt)->rigth->bal = 0;
            break;
        }
        (*pt)->bal = 0;
        *is_modified_heigth = 'V';
    }
}

void rotate_rigth_remove(Node **pt, char *is_modified_heigth)
{
    if (*pt == NULL || (*pt)->rigth == NULL)
    {
        return;
    }

    Node *ptu = (*pt)->rigth;

    if (ptu->bal >= 0)
    {
        (*pt)->rigth = ptu->left;
        ptu->left = (*pt);
        (*pt) = ptu;

        if (ptu->bal == 1)
        {
            (*pt)->left->bal = 0;
            (*pt)->bal = 0;
            *is_modified_heigth = 'V';
        }
        else
        {
            (*pt)->left->bal = 1;
            (*pt)->bal = -1;
            *is_modified_heigth = 'F';
        }
    }
    else
    {
        Node *ptv = ptu->left;

        ptu->left = ptv->rigth;
        ptv->rigth = ptu;
        (*pt)->rigth = ptv->left;
        ptv->left = (*pt);
        (*pt) = ptv;

        switch (ptv->bal)
        {
        case -1:
            (*pt)->left->bal = 0;
            ptu->bal = 1;
            break;
        case 0:
            (*pt)->left->bal = 0;
            ptu->bal = 0;
            break;
        case 1:
            (*pt)->left->bal = -1;
            ptu->bal = 0;
            break;
        }
        (*pt)->bal = 0;
        *is_modified_heigth = 'V';
    }
}

void fill_vector(int n, int *vector)
{
    int *check = (int *)calloc(100000 + 3, sizeof(int));

    for (int i = 0; i < n; i++)
    {
        int randomValue;
        do
        {
            randomValue = rand() % 100000 + 3;
        } while (check[randomValue] != 0);
        check[randomValue] = 1;
        vector[i] = randomValue;
    }
}

void test_AVLs()
{
    int n = 10000;
    Node *root = NULL;
    int nodes = 0;
    char is_modified_heigth = 'F';
    int isAvl = 0;
    for (int i = 0; i < 1000; i++)
    {
        printf("%d AVL\n", i + 1);
        int *vector = (int *)calloc(n, sizeof(int));

        fill_vector(n, vector);
        count_nodes(root, &nodes);

        puts("-------- INITIAL --------");

        printf("Number of nodes : %d\n\n", nodes);

        for (int i = 0; i < n; i++)
        {
            insert_AVL(vector[i], &root, &is_modified_heigth);
        }

        puts("---- AFTER INSERTION ----");

        nodes = 0;

        count_nodes(root, &nodes);

        printf("Number of nodes: %d\n", nodes);

        isAvl = check_AVL(&root);

        printf(isAvl ? "Tree is AVL\n" : "Tree not is AVL\n");

        puts("");

        for (int i = 0; i < 1000; i++)
        {
            removeAVL(vector[i], &root, &is_modified_heigth);
        }

        puts("----- AFTER REMOVING -----");

        nodes = 0;

        count_nodes(root, &nodes);

        printf("Number of nodes: %d\n", nodes);
        nodes = 0;
        isAvl = check_AVL(&root);

        printf(isAvl ? "Tree is AVL\n" : "Tree not is AVL\n");

        puts("");

        clear_AVL(root);
        root = NULL;
    }
}

void clear_AVL(Node *root)
{
    if (root != NULL)
    {
        clear_AVL(root->left);
        clear_AVL(root->rigth);
        free(root);
    }
}