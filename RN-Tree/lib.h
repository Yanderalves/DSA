typedef enum
{
    RED,
    BLACK

} Color;

typedef struct Node
{
    int value;
    struct Node *dad;
    struct Node *left;
    struct Node *right;
    Color color;
} Node;

Node *outside();

void left_rotate(Node *x, Node **root, Node *outside);
void right_rotate(Node *x, Node **root, Node *outside);
void insert_RB(int value, Node **root, Node *outside);
Node *create_node(int value, Node *outside);
void pre_order(Node *root, Node *outside);