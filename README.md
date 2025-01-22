# Heap

- [x]  Subir
- [x]  Descer
- [x]  Construir
- [x]  Inserir
- [x]  Remover

# Algorítmos de ordenação
- [x]  Heap sort
- [x]  Insertion sort
- [x]  Implementar testes
    - [x]  Heap sort - 1K
        - 0.00 milissegundos
    - [x]  Heap sort - 100K
        - 0.00 milissegundos
    - [x]  Heap sort - 1M
        - 0.00 milissegundos
    - [x]  Heap sort - 10M
        - 3.000 milissegundos
    - [x]  Heap sort - 100M
        - 40.000 milissegundos
    - [x]  Heap sort - 1BI
        - Sem memória suficiente pra alocar
    - [x]  Insertion sort - 1K
        - 0.000 segundos
    - [x]  Insertion sort - 100K
        - 0.000 segundos
    - [x]  Insertion sort - 1M
        - 360.000 milssegundos
    - [ ]  Insertion sort - 5M
        - Ainda falta testar denovo
    - [x]  Insertion sort - 10M
        - Rodou por horas e não executou
    - [x]  Insertion sort - 1BI
        - Sem memória o suficiente pra alocar
- [x]  Relatório
    * https://docs.google.com/document/d/1u8uRsM9ONEogGW0Qc_iCaKbY-YM-MfgPSvf7qiiHUnU/edit#heading=h.u084as8stz7i

## Como executar o código?

1. Tu vai ter de instalar o compilador do C na tua máquina, qualquer coisa ver esse vídeo. https://www.youtube.com/watch?v=eDzQ6HkmGa4
2. Na pasta onde tá o projeto, abra um terminal e digite: 

```bash
 gcc main.c lib.c -o main   
```

3. Isso aí vai compilar o código. Agora é só executar o arquivo executável criado com: 

```bash
.\main.exe
```

4. Feito. O código vai executar. Mas lembra de de descomentar o teste que tu quer executar. (Executar um teste de cada vez, pois pode ocorrer de o segundo algoritmo não conseguir buscar o array que acabara de ser gravado no arquivo, e ele vir com o array todo preenchido por 0)

![image.png](/.github/image.png)

# Árvore Binária

## Funcionalidades

- **Operações com Nós**:
  - Criar um novo nó com um valor especificado.
  - Inserir um nó na árvore binária.
  - Remover um nó da árvore binária.
  - Buscar um nó com um valor específico.
- **Travessias da Árvore**:
  - Travessia em ordem.
  - Travessia em pré-ordem.
  - Travessia em pós-ordem.
- **Métricas da Árvore**:
  - Calcular a altura da árvore.
  - Contar o número total de nós.

## Descrição das Funções

### Estrutura do Nó
O struct `No` representa um nó na árvore binária:
```c
typedef struct No {
    int key;
    struct No *left;
    struct No *rigth;
} No;
```

### Principais Funções

#### Criação de Nó
```c
No *create_node(int value);
```
Cria um novo nó com o valor especificado.

#### Inserção
```c
void insert_node(No **node, int value);
```
Insere um novo nó com o valor especificado na árvore binária.

#### Remoção
```c
void remove_node(int value, No **node);
```
Remove o nó com o valor especificado da árvore.

#### Busca
```c
No *search(No **node, int value);
```
Busca por um nó com o valor especificado.

#### Travessias
- **Em ordem**: `void in_order(No *no);`
- **Pré-ordem**: `void pre_order(No *no);`
- **Pós-ordem**: `void post_order(No *no);`

#### Altura da Árvore
```c
int heigth(No *no);
```
Calcula a altura da árvore.

#### Funções Utilitárias
- `int max_number(int a, int b)` - Retorna o maior entre dois números.
- `void fill_vector(int *vector, int n)` - Preenche um vetor com valores
- `void count_nodes(No **node, int *nodes)` - Conta o número total de nós na árvore.

## Como Usar

1. **Clone o repositório**:
```bash
git clone https://github.com/Yanderalves/Arvore-e-Heap
cd Arvore-e-Heap/Arvore
```

2. **Compile o código**:
```bash
gcc lib.c main.c -o main
```

3. **Execute o programa**:
```bash
./main.exe
```


# Fila com Encadeamento

### Estrutura `Node`
Representa um nó da fila, contendo um valor e um ponteiro para o próximo nó.

```c
typedef struct Node {
    struct Node *next;
    int value;
} Node;
```

### Estrutura `Queue`
Representa a fila, contendo ponteiros para o primeiro (`head`) e o último (`last`) nós.

```c
typedef struct Queue {
    struct Node *head;
    struct Node *last;
} Queue;
```

---

## Funções

### Inicialização

#### Inicializar Nó
Cria um novo nó com o valor especificado.

```c
Node *init_node(int value);
```

#### Inicializar Fila
Cria e inicializa uma nova fila vazia.

```c
Queue *init_queue();
```

---

### Operações na Fila

#### Enfileirar (`enqueue`)
Adiciona um elemento ao final da fila.

```c
void enqueue(Queue **queue, int value);
```

#### Desenfileirar (`dequeue`)
Remove e retorna o elemento no início da fila. 

```c
int dequeue(Queue **queue);
```

---

### Exibição

#### Imprimir Fila
Percorre e imprime todos os valores da fila a partir do nó especificado.

```c
void print(Node *node);
```

---

## Como Compilar e Executar

1. Clone o repositório e navegue até a pasta do projeto:
    ```bash
    git clone https://github.com/Yanderalves/DSA
    cd DSA/DS/Queue
    ```

2. Compile o código:
    ```bash
    gcc lib.c main.c -o main
    ```

3. Execute o programa:
    ```bash
    ./main.exe
    ```


## Licença
Este projeto está licenciado sob a Licença MIT. Consulte o arquivo `LICENSE` para mais detalhes.