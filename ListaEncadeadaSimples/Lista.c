/*
Listas encadeadas são estruturas de dados que permitem armazenar uma coleção
 de elementos de um mesmo tipo.

Neste arquivo, temos a implementação de uma lista encadeada simples de inteiros.
*/

#include "lista.h"

// struct para manipulação de uma lista de números
struct lista
{
	int info;				// valor numérico
	struct lista *prox;		// endereço do próximo valor da lista
};

// Função que cria uma lista, adicionando [NULL] ao seu valor inicial:
Lista *lst_cria(void)
{
	return NULL;
}

// Função que aloca espaço para uma lista e preenche seus parâmetros:
Lista *lst_insere(Lista *l, int v)
{
	Lista *novo = (Lista *)malloc(sizeof(Lista));	// cria um ponteiro, e o associa a um espaço de memória alocado de forma dinâmica, 
	if (novo == NULL)								// verifica se a alocação foi bem sucedida
	{
		printf("[ERRO] memoria insuficiente!");		// caso verdadeiro, exibe messagem de erro e encerra programa.
		exit(1);
	}
	novo->info = v;		// preenche os valores de "novo"
	novo->prox = l;
	return novo;

	/* Ou para alterar diretamente

	void lst_insere(Lista** t, int v){
	Lista* novo = (Lista*) malloc(sizeof(Lista));
	novo->info = v;
	novo->prox = *t;
	*t = novo; */
}

// Função que verifica se a lista está vazia:
int lst_vazia(Lista *l)
{
	return (l == NULL); // retorna 1 se estiver vazia, e 0, caso contrário
}

// Função que imprime os elementos da lista:
void lst_imprime(Lista *l)
{
	Lista *p;								// cria um ponteiro auxiliar para uma lista auxiliar "p"
	for (p = l; p != NULL; p = p->prox)		// p é inicializada com o endereço associado ao ponteiro "l", e o laço de repetição para somente
	{										// quando p == NULL
		
		printf("\tInfo = %d \n", p->info);	// imprime o valor info do elemento da lista
	}
}

// Função que realiza a busca de um elemento específico da lista:
Lista *lst_busca(int elemento, Lista *l)
{
	Lista *p;								// cria um ponteiro auxiliar para uma lista auxiliar "p"
	for (p = l; p != NULL; p = p->prox)		// p é inicializada com o endereço associado ao ponteiro "l", e o laço de repetição para somente
	{										// quando p == NULL
		
		if (p->info == elemento)			// verifica se o elemento atual é o procurado, através do valor "info"
			return p;						// caso verdadeiro, retorna o elemento atual de "p"
	}

	return NULL;							// caso não for encontrado, retorna elemento [NULL]
}

Lista *lst_retira(Lista *l, int v)
{
	Lista *ant = NULL; /* ponteiro para elemento anterior */
	Lista *p = l;	   /* ponteiro para percorrer a lista*/
	/* procura elemento na lista, guardando anterior */
	while (p->info != v)
	{
		if (p == NULL)
			return l; /* não achou: retorna lista original */
		ant = p;
		p = p->prox;
		/* verifica se achou elemento */
	}
	/* retira elemento */
	if (ant == NULL)
		/* retira elemento do inicio */
		l = p->prox;
	else
		/* retira elemento do meio da lista */
		ant->prox = p->prox;
	free(p);
	return l;
}

// Função que libera memória alocada para a Lista:
void lst_libera(Lista *l)
{
	Lista *p = l;		// cria um ponteiro auxiliar para uma lista auxiliar "p", inicializada com a lista "l"
	Lista *t;			// cria um ponteiro auxiliar para uma lista auxiliar "t"
	while (p != NULL)	// laço de repetição, enquanto valor de "p" não for [NULL]
	{
		t = p->prox;	// armazena o endereço do próximo valor, associado ao valor atual de "p", em "t"
		free(p);		// libera memória de "p"
		p = t;			// adiciona o endereço do próximo valor no ponteiro "p"
	}
}

Lista *lst_insere_ordenada(Lista *l, int v)
{
	Lista *novo;								// cria um ponteiro auxiliar "novo"
	Lista *ant = NULL;							// cria um ponteiro auxiliar "ant", para apontar para o elemento anterior da lista, e inicializa com [NULL]
	Lista *p = l;								// cria um ponteiro auxiliar "p", inicializada com a lista "l"
	while (p != NULL && p->info < v)
	{
		ant = p;
		p = p->prox;
	}
	novo = (Lista *)malloc(sizeof(Lista));
	novo->info = v;
	if (ant == NULL)
	{
		novo->prox = l;
		l = novo;
	}
	else
	{
		novo->prox = ant->prox;
		ant->prox = novo;
	}
	return l;
}

Lista *lst_ler_arquivo(char *nome_arquivo)
{
	FILE *arquivo;
	int valor;
	Lista *l = lst_cria();
	arquivo = fopen(nome_arquivo, "r");
	if (arquivo == NULL)
	{
		printf("Erro ao abrir o arquivo!\n");
		exit(1);
	}
	while (fscanf(arquivo, "%d", &valor) != EOF)
	{
		l = lst_insere(l, valor);
	}
	fclose(arquivo);
	return l;
}
