#include <stdio.h>
#include "lib.h"

int main()
{
    Node *outsider = outside();

    Node *root = outsider;

    int vector[] = {10, 15, 20, 5, 6, 18, 16};
    int size = sizeof(vector) / sizeof(int);

    for (int i = 0; i < size; i++)
    {
        insert_RB(vector[i], &root, outsider);
    }

    pre_order(root, outsider);

    return 0;
}
