#include <stdio.h>
#include <stdlib.h>

typedef struct lista2 Lista2;

// função que cria uma lista vazia (NULL)
Lista2 *lst_cria(void);

// função que insere um elemento no início da lista
Lista2 *lst_insere(Lista2 *l, int v);

// função que verifica se a lista está vazia
int lst_vazia(Lista2 *l);

// função que imprime os elementos da lista
void lst_imprime(Lista2 *l);

// função que busca um elemento na lista
Lista2 *lst_busca(int elemento, Lista2 *l);

// função que retira um elemento da lista
Lista2 *lst_retira(Lista2 *l, int v);

// função que libera a memória alocada para a lista
void lst_libera(Lista2 *l);

// função que insere de forma ordenada um elemento na lista
Lista2 *lst_insere_ordenada(Lista2 *l, int v);

// Função que ler de uma arquivo e armazena na lista encadeada de inteiros
Lista2 *lst_ler_arquivo(char *nome_arquivo);


void lcirc_imprime(Lista2* l);
