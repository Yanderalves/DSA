#include "lib.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    LinkedList *linked_list = init_linked_list();

    insert(linked_list, 15);
    insert(linked_list, 18);
    insert(linked_list, 19);

    if (linked_list->init != NULL)
        print(linked_list->init);

    puts("");

    if (linked_list->end != NULL)
        reverse_print(linked_list->end);

    return 0;
}
