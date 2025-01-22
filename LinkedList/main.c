#include "lib.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    LinkedList *linked_list = init_linked_list();

    insert_at_end(linked_list, 15);
    insert_at_end(linked_list, 18);
    insert_at_end(linked_list, 19);

    // int busca = search(linked_list->init, 40);

    insert_at_beginning(linked_list, 12);
    insert_at_beginning(linked_list, 17);
    insert_at_beginning(linked_list, 56);

    if (linked_list->init != NULL)
        print(linked_list->init);

    return 0;
}
