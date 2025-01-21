#include "lib.h"
#include <stdio.h>

int main()
{
    int vector[] = {5, 2, 4, 6, 1, 3};
    int n = 6;
    insertion_sort(vector, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", vector[i]);
    }
    return 0;
}