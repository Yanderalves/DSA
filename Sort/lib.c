#include "lib.h"

void insertion_sort(int vector[], int n)
{
    for (int j = 1; j < n; j++)
    {
        int i = j - 1;
        int value = vector[j];
        while (i >= 0 && vector[i] < value)
        {
            vector[i + 1] = vector[i];
            i--;
        }
        vector[i + 1] = value;
    }
}
