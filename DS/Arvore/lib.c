#include "lib.h"
#include <time.h>

struct _no
{
  int key;
  No *left;
  No *rigth;
};

void pre_order(No *no)
{
  printf("%d -> ", no->key);
  if (no->left != NULL)
  {
    pre_order(no->left);
  }

  if (no->rigth != NULL)
  {
    pre_order(no->rigth);
  }
}

void post_order(No *no)
{
  if (no->left != NULL)
  {
    post_order(no->left);
  }
  if (no->rigth != NULL)
  {
    post_order(no->rigth);
  }
  printf("%d -> ", no->key);
}

void in_order(No *no)
{
  if (no->left != NULL)
  {
    in_order(no->left);
  }
  printf("%d -> ", no->key);
  if (no->rigth != NULL)
  {
    in_order(no->rigth);
  }
}

int heigth(No *no)
{
  int hl = 0, hr = 0;
  if (no == NULL)
    return -1;
  else if (no->left == NULL && no->rigth == NULL)
    return 0;
  else
  {
    if (no->left != NULL)
      hl = heigth(no->left);
    if (no->rigth != NULL)
      hr = heigth(no->rigth);
  }

  return 1 + max_number(hl, hr);
}

int max_number(int a, int b)
{
  return a > b ? a : b;
}

No *create_node(int value)
{
  No *node = calloc(1, sizeof(No));
  node->key = value;
  node->left = NULL;
  node->rigth = NULL;

  return node;
}

void insert_node(No **node, int value)
{
  if (*node == NULL)
  {
    *node = create_node(value);
  }
  else
  {
    if ((*node)->key == value)
      return;
    else if (value < (*node)->key)
    {
      insert_node(&(*node)->left, value);
    }
    else
    {
      insert_node(&(*node)->rigth, value);
    }
  }
}

No *search(No **node, int value)
{
  if (*node == NULL)
    return NULL;
  else
  {
    if ((*node)->key == value)
      return *node;
    else if (value < (*node)->key)
    {
      return search(&(*node)->left, value);
    }
    else
    {
      return search(&(*node)->rigth, value);
    }
  }
}

void fill_vector(int *vector, int n)
{
  srand(time(NULL));

  for (int i = 0; i < n; i++)
  {
    vector[i] = rand() % 10000;
  }
}
void remove_node(int value, No **node)
{
  if (*node == NULL)
    puts("Tree is Empty");
  else
  {
    if ((*node)->key > value)
      remove_node(value, &(*node)->left);
    else if ((*node)->key < value)
      remove_node(value, &(*node)->rigth);
    else
    {
      No *aux = *node;
      if ((*node)->left == NULL && (*node)->rigth == NULL)
      {
        free(aux);
        *node = NULL;
      }
      else if ((*node)->left == NULL)
      {
        (*node) = (*node)->rigth;
        free(aux);
      }
      else if ((*node)->rigth == NULL)
      {
        (*node) = (*node)->left;
        free(aux);
      }
      else
      {
        aux = (*node)->rigth;
        while (aux->left != NULL)
        {
          aux = aux->left;
        }
        (*node)->key = aux->key;
        remove_node(aux->key, &(*node)->rigth);
      }
    }
  }
}

void count_nodes(No **node, int *nodes)
{
  if ((*node)->left != NULL)
    count_nodes(&(*node)->left, nodes);

  if ((*node)->rigth != NULL)
    count_nodes(&(*node)->rigth, nodes);

  *nodes = *nodes + 1;
}