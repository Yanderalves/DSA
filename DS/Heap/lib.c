
#include "lib.h"
#include "sizes.h"

long size_1K = 1000;
long size_100K = 100000;
long size_1M = 1000000;
long size_5M = 5000000;
long size_10M = 10000000;
long size_100M = 100000000;
long size_1BI = 1000000000;
long n;

void troca(long i, long j, long *array)
{
  long aux = array[i];
  array[i] = array[j];
  array[j] = aux;
}

void subir(long i, long *array)
{
  long j = (i / 2) - 1;
  if (j >= 0)
  {
    if (array[i] > array[j])
    {
      troca(i, j, array);
      subir(j, array);
    }
  }
}

void descer(long i, long n, long *array)
{
  long j = (2 * i) + 1;
  if (j <= n)
  {
    if (j < n)
    {
      if (array[j + 1] > array[j])
      {
        j = j + 1;
      }
    }
    if (array[i] < array[j])
    {
      troca(i, j, array);
      descer(j, n, array);
    }
  }
}

void construir(long *array, long n)
{
  for (long i = (n / 2) - 1; i >= 0; i--)
  {
    descer(i, n, array);
  }
}

void print(long *array, int n)
{
  puts("");
  for (long i = 0; i < n; i++)
  {
    printf("%d - %lu\n", i, array[i]);
  }
  puts("");
}

void inserir(int novo, long *array)
{
  array[n] = novo;
  subir(n, array);
  n = n + 1;
}

void remover(long *array)
{
  if (n > 0)
  {
    array[0] = array[n - 1];
    n = n - 1;
    array[n] = 0;
    descer(0, n, array);
  }
  else
  {
    puts("Underflow");
  }
}

void heap_sort(long *array, long n)
{
  construir(array, n);

  long m = n - 1;

  while (m > 0)
  {
    troca(0, m, array);
    m--;
    descer(0, m, array);
  }
}

void insertion_sort(long *array, int n)
{
  for (int j = 1; j < n; j++)
  {
    int chave = array[j];
    int i = j - 1;
    while ((array[i] > chave) && i >= 0)
    {
      array[i + 1] = array[i];
      i--;
    }
    array[i + 1] = chave;
  }
}

long buscar_tamanho_array(char *nome_arquivo)
{
  long tam_array = 0;
  if (strcmp(nome_arquivo, "1K.txt") == 0)
  {
    tam_array = size_1K;
  }
  else if (strcmp(nome_arquivo, "100K.txt") == 0)
  {
    tam_array = size_100K;
  }
  else if (strcmp(nome_arquivo, "1M.txt") == 0)
  {
    tam_array = size_1M;
  }
  else if (strcmp(nome_arquivo, "5M.txt") == 0)
  {
    tam_array = size_5M;
  }
  else if (strcmp(nome_arquivo, "10M.txt") == 0)
  {
    tam_array = size_10M;
  }
  else if (strcmp(nome_arquivo, "100M.txt") == 0)
  {
    tam_array = size_100M;
  }
  else if (strcmp(nome_arquivo, "1BI.txt") == 0)
  {
    tam_array = size_1BI;
  }
  else
  {
    exit(0);
  }

  return tam_array;
}

long *gerar_array_vindo_do_arquivo(char *nome_arquivo)
{
  FILE *arquivo = fopen(nome_arquivo, "r");
  int tam_array = buscar_tamanho_array(nome_arquivo);
  long *array = (long *)calloc(sizeof(long), tam_array);

  if (arquivo == NULL)
  {
    arquivo = fopen(nome_arquivo, "w");

    for (int i = 0; i < tam_array; i++)
    {
      array[i] = rand() % size_10M;
      if (i != tam_array - 1)
      {
        fprintf(arquivo, "%lu\n", array[i]);
      }
      else
      {
        fprintf(arquivo, "%lu", array[i]);
      }
    }
  }
  else
  {
    long i = 0;
    char *c;
    i = 0;
    while (fscanf(arquivo, "%lu", &array[i]) == 1)
    {
      i++;
    }
  }

  return array;
}