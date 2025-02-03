typedef enum
{
    RED,
    BLACK

} Color;

#define _1K 1000
#define _10K 10000
#define _100K 100000

typedef struct Node
{
    int value;
    struct Node *dad;
    struct Node *left;
    struct Node *right;
    Color color;
} Node;

Node *create_external();

void left_rotate(Node *x, Node **root, Node *external);
void right_rotate(Node *x, Node **root, Node *external);

void insert_RB(int value, Node **root, Node *external);

Node *create_node(int value, Node *external);
void pre_order(Node *root, Node *external);
int count_nodes(Node *root, Node *external, int *nodes);
void RB_tests();
void fill_vector(int *vector, int size);
void free_RB(Node **root, Node *external);

void move_dad(Node *u, Node *v, Node **root, Node *external);
void remove_node(int value, Node **root, Node *external);
Node *successor(Node *z, Node *external);
Node *search(int value, Node *root, Node *external);

void rotate_remove(Node *x, Node **root, Node *external);

int black_heighth(Node *root, Node *external);
