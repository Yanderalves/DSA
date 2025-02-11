#include <stdbool.h>

typedef enum
{
    RED,
    BLACK

} Color;

#define _10 10
#define _100 100
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

// ========================== Funções de Inserção ==========================
void insert_RB(int value, Node **root, Node *external);
void rotate_insert(Node *z, Node **root, Node *external);

// ========================== Funções de Remoção ==========================
void remove_node(int value, Node **root, Node *external);
void move_dad(Node *u, Node *v, Node **root, Node *external);
void rotate_remove(Node *x, Node **root, Node *external);

// ========================== Funções de Rotação ==========================
void left_rotate(Node *x, Node **root, Node *external);
void right_rotate(Node *x, Node **root, Node *external);

// ========================== Funções Auxiliares ==========================
Node *successor(Node *z, Node *external);
Node *antecessor(Node *z, Node *external);
Node *search(int value, Node *root, Node *external);
int count_nodes(Node *root, Node *external, int *nodes);
void free_RB(Node **root, Node *external);
void fill_vector(int *vector, int size);
Node *create_external();
Node *create_node(int value, Node *external);

// ========================== Funções de Validação ==========================
int black_height(Node *root, Node *external);
bool is_RB_tree(Node *root, Node *external);

// ========================== Funções de Teste ==========================
void RB_tests();
void small_RB_tests();

// ========================== Função de Impressão ==========================
void pre_order(Node *root, Node *external);
