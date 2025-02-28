#include <stdlib.h>
#include "lib.h"
#include <stdio.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    int solves_colision = 0;

    int max_limit = 2000000;
    int sizes[] = {50000,
                   100000,
                   150000,
                   200000,
                   250000};

    // for (int i = 0; i < 5; i++)
    // {
    //     printf("N = %d\n", sizes[i]);

    //     int *keys = calloc(sizes[i], sizeof(int));

    //     fill_vector_hash(sizes[i], keys);
    //     division_method_tests(keys, sizes[i], solves_colision);

    //     fill_vector_hash(sizes[i], keys);
    //     multiplication_method_tests(keys, sizes[i], solves_colision);

    int keys[] = {5, 8, 12, 784, 12, 3, 2, 87, 12};
    // fill_vector_hash(1, );
    fold_method_tests(keys, 8);

    //     puts("=======================");
    // }

    return 0;
}