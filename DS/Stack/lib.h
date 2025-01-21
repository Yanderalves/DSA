// Stack

typedef struct Stack
{
    struct Stack *next;
    int value;
} Stack;

void push(Stack **stack, int value);
int pop(Stack **stack);
Stack *init_stack();

// auxiliary functions
void print(Stack *stack);
Stack *init_node(int value);