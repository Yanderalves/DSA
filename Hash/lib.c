#include "lib.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "..\AVL\lib.h"

typedef struct HashNode
{
    int value;
    struct Node *avl_tree;
} HashNode;

const double A = 0.6180339887;

int division_method(int val, int size_table)
{
    return val % size_table;
}

int multiplication_method(double val, int size_table)
{
    double prod = val * A;
    double decimal = prod - (int)prod;

    return (int)(decimal * size_table);
}

int fold_method(int val, int n)
{
    int index = 0, size = 0;

    int *vec;
    size = count_digits(val);

    if (size % 2 != 0)
        size += 1;

    vec = (int *)malloc(sizeof(int) * size);

    add_vector(vec, val, size);

    index = fold(vec, size);

    free(vec);

    return index;
}

int count_digits(int value)
{
    int count = 0;
    while (value != 0)
    {
        value = value / 10;
        count++;
    }

    return count;
}

int sum_digits(int a, int b)
{
    int sum = a + b;
    if (sum > 9)
    {
        return sum % 10;
    }
    return sum;
}

int fold(int *vector, int size)
{
    int i, k;
    for (i = 0; i < size - 2; i++)
    {
        k = i % 2 == 0 ? 3 : 1;
        vector[i + k] = sum_digits(vector[i], vector[i + k]);
    }

    return vector[size - 2] * 10 + vector[size - 1];
}

void add_vector(int *vec, int key, int size)
{
    int i;
    for (i = size; i > -1; i--)
    {
        vec[i - 1] = key % 10;
        key /= 10;
    }
}

void division_method_tests(int *keys, int n, int solves_collision)
{
    HashNode *table = calloc(n, sizeof(HashNode));

    int collisions = 0;
    puts("Division method");

    for (int i = 0; i < n; i++)
    {
        int index = division_method(keys[i], n);

        if (solves_collision == 1)
        {

            if (table[index].value != 0)
            {
                collisions++;

                char is_modified_heigth = 'F';

                insert_AVL(keys[i], &table[index].avl_tree, &is_modified_heigth);
            }
            else
            {
                table[index].value = keys[i];
                table[index].avl_tree = create_node(keys[i]);
            }
        }
        else
        {
            if (table[index].value != 0)
                collisions++;
            else
                table[index].value = keys[i];
        }
    }

    printf("Collisions: %d\n\n", collisions);

    for (int i = 0; i < n; i++)
    {
        if (table[i].avl_tree != NULL)
        {
            clear_AVL(table[i].avl_tree);
        }
    }
    free(table);
}

void multiplication_method_tests(int *keys, int n, int solves_collision)
{
    HashNode *table = calloc(n, sizeof(HashNode));

    int collisions = 0;
    puts("Multiplication method");

    for (int i = 0; i < n; i++)
    {
        int index = multiplication_method(keys[i], n);

        if (solves_collision == 1)
        {
            if (table[index].value != 0)
            {
                collisions++;

                char is_modified_heigth = 'F';

                insert_AVL(keys[i], &table[index].avl_tree, &is_modified_heigth);
            }
            else
            {
                table[index].value = keys[i];
                table[index].avl_tree = create_node(keys[i]);
            }
        }
        else
        {
            if (table[index].value != 0)
            {
                collisions++;
            }
            else
            {
                table[index].value = keys[i];
            }
        }
    }

    printf("Collisions: %d\n\n", collisions);
    collisions = 0;
}

void fold_method_tests(int *keys, int n)
{
    int *table = calloc(n, sizeof(int));

    int collisions = 0;
    puts("fold method");

    for (int i = 0; i < n; i++)
    {
        int index = fold_method(keys[i], n);
        printf("Index: %d\n valor: %d\n", index, keys[i]);
        // if (table[index] != 0)
        // {
        //     collisions++;
        // }
        // else
        // {
        //     table[index] = keys[i];
        // }
    }

    printf("Collisions: %d\n\n", collisions);
    collisions = 0;
}

void fill_vector_hash(int n, int *vector)
{
    int max_limit = 2000000;

    for (int i = 0; i < n; i++)
    {
        vector[i] = rand() % max_limit;
    }
}