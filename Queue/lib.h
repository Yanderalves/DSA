#include <stdbool.h>
typedef struct Queue
{
    struct Node *head;
    struct Node *last;

} Queue;

typedef struct Node
{
    struct Node *next;
    int value;
} Node;

void enqueue(Queue **queue, int value);
int dequeue(Queue **queue);
void print(Node *node);

Queue *init_queue();
Node *init_node(int value);

bool queue_is_empty(Queue *queue);