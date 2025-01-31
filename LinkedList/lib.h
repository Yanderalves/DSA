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

void insert_at_beginning(LinkedList *linked_list, int value);
void insert_at_end(LinkedList *linked_list, int value);

void remove_from_beginning(LinkedList *linked_list);
void remove_from_end(LinkedList *linked_list);
void remove_from_other_position(LinkedList *linked_list, int value);

Node *create_node(int value);
void print(Node *node);
int search(Node *node, int value);
void reverse_print(Node *node);