#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#include <time.h>

int main()
{
    int vet[] = {5, 9, 3, 2, 1, 4, 7, 8, 13, 17};

    Stack *stack = init_stack();

    push(&stack, 15);
    push(&stack, 16);
    push(&stack, 17);

    print(stack);
}