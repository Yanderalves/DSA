#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

int main()
{
  No *root = NULL;
  int n = 10;
  int nodes = 0;

  int *vector = calloc(n, sizeof(int));

  fill_vector(vector, n);

  puts("========================");
  puts("=========INSERT=========");
  puts("========================");
  puts("");

  for (int i = 0; i < n; i++)
  {
    insert_node(&root, vector[i]);
  }

  count_nodes(&root, &nodes);

  printf("Quantity Nodes: %d\n", nodes);

  puts("=================");
  puts("Print Tree In Pre Order");
  pre_order(root);
  puts("\n");

  puts("=================");
  puts("Print Tree In Order");
  in_order(root);
  puts("\n");

  puts("=================");
  puts("Print Tree In post Order");
  post_order(root);
  puts("\n");

  puts("========================");
  puts("=========REMOVE=========");
  puts("========================");
  puts("");

  for (int i = 0; i < n / 2; i++)
  {
    remove_node(vector[i], &root);
  }

  nodes = 0;
  count_nodes(&root, &nodes);

  printf("Quantity Nodes: %d\n", nodes);

  puts("=================");
  puts("Print Tree In Pre Order");
  pre_order(root);
  puts("\n");

  puts("=================");
  puts("Print Tree In Order");
  in_order(root);
  puts("\n");

  puts("=================");
  puts("Print Tree In post Order");
  post_order(root);
  puts("\n");

  return 0;
}
