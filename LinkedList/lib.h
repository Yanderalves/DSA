typedef struct Node
{
    int value;
    struct Node *prev, *next;
} Node;

typedef struct LinkedList
{
    struct Node *init, *end;
} LinkedList;

LinkedList *init_linked_list();

void insert(LinkedList *linked_list, int value);
Node *create_node(int value);

void print(Node *node);
void reverse_print(Node *node);