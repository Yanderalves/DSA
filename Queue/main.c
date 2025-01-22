#include "lib.h"
#include <stdio.h>

int main()
{

    Queue *queue = init_queue();

    enqueue(&queue, 15);
    enqueue(&queue, 18);
    enqueue(&queue, 125);
    enqueue(&queue, 1);

    int value = dequeue(&queue);

    if (queue->head != NULL)
        print(queue->head);

    return 0;
}