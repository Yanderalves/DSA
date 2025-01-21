#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Métodos do Heap
void subir(long i, long *array);
void construir(long *array, long n);
void descer(long i, long n, long *array);
void inserir(int novo, long *array);
void remover(long *array);

// ALgoritmos de ordenação
void heap_sort(long *array, long n);
void insertion_sort(long *array, int n);

// Funções auxiliares
void print(long *array, int n);
long *gerar_array_vindo_do_arquivo(char *nome_arquivo);
long buscar_tamanho_array(char *nome_arquivo);

// Testes Insertion sort
void teste_insertion_sort_1K();
void teste_insertion_sort_100K();
void teste_insertion_sort_1M();
void teste_insertion_sort_5M();
void teste_insertion_sort_10M();
void teste_insertion_sort_100M();
void teste_insertion_sort_1B();

// Testes Heap sort
void teste_heap_sort_1K();
void teste_heap_sort_100K();
void teste_heap_sort_1M();
void teste_heap_sort_5M();
void teste_heap_sort_10M();
void teste_heap_sort_100M();
void teste_heap_sort_1BI();
