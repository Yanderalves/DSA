#include <stdbool.h>

typedef struct Node
{
    struct Node *left;
    struct Node *rigth;
    int bal;
    int value;
} Node;

void rotate_left_insert(Node **root, char *is_modified_heigth);
void rotate_rigth_insert(Node **pt, char *is_modified_heigth);

void insert_AVL(int value, Node **root, char *is_modified_heigth);
void removeAVL(int value, Node **pt, char *is_modified_heigth);

Node *create_node(int value);

void pre_ordem(Node *root);

void balance(Node **pt, char where, char *is_modified_heigth);

void rotate_left_remove(Node **pt, char *is_modified_heigth);
void rotate_rigth_remove(Node **pt, char *is_modified_heigth);

void count_nodes(Node *root, int *nodes);
int check_AVL(Node **root);
int heigth(Node **root);
int max_number(int a, int b);
void swap(Node **pt, Node **fatherS);

void fill_vector(int n, int *vector);

void test_AVLs();

void clear_AVL(Node *root);