#include "lista2.h"

struct lista2
{
	int info;	
	struct lista2 *ant;
	struct lista2 *prox;
};

// Função que cria uma lista, adicionando [NULL] ao seu valor inicial:
Lista2 *lst2_cria(void)
{
	return NULL;
}

// Função que aloca espaço para uma lista e preenche seus parâmetros:
Lista2 *lst2_insere(Lista2 *l, int v)
{
	Lista2 *novo = (Lista2*)malloc(sizeof(Lista2));
	if (novo == NULL)
	{
		printf("[ERRO] memoria insuficiente!");
		exit(1);
	}
	novo->info = v;
    novo->prox = l;
    novo->ant = NULL;
	
    if (l != NULL)
        l->ant = novo;

	return novo;

	/* Ou para alterar diretamente

	void lst_insere(Lista** t, int v){
	Lista* novo = (Lista*) malloc(sizeof(Lista));
	novo->info = v;
	novo->prox = *t;
	*t = novo; */
}

// // Função que verifica se a lista está vazia:
// int lst_vazia(Lista *l)
// {
// 	return (l == NULL); // retorna 1 se estiver vazia, e 0, caso contrário
// }

// Função que imprime os elementos da lista:
void lst2_imprime(Lista2 *l)
{
	Lista2 *p;								// cria um ponteiro auxiliar para uma lista auxiliar "p"
	for (p = l; p != NULL; p = p->prox)		// p é inicializada com o endereço associado ao ponteiro "l", e o laço de repetição para somente
	{										// quando p == NULL
		
		printf("\tInfo = %d \n", p->info);	// imprime o valor info do elemento da lista
	}
}

// Função que realiza a busca de um elemento específico da lista:
Lista2 *lst2_busca(Lista2 *l, int v)
{
	Lista2 *p;
	for (p = l; p != NULL; p = p->prox)
	{
		
		if (p->info == v)
			return p;
	}

	return NULL;
}

Lista2 *lst2_retira(Lista2 *l, int v)
{
	Lista2 *p = lst2_busca(l, v);

    if (p == NULL)
        return l; /* não achou elemento */

    /* retira elemento do encadeamento */
    if (p == l) /* teste se é o primeiro elemento */
        l = p->prox; 
    else
        p->ant->prox = p->prox;

	if (p->prox != NULL)
        p->prox->ant = p->ant;

	free(p);
	
    return l;
}

// Função que libera memória alocada para a Lista:
void lst2_libera(Lista2 *l)
{
	Lista2 *p = l;
	Lista2 *t;
	while (p != NULL)
	{
		t = p->prox;
		free(p);		// libera memória de "p"
		p = t;			// adiciona o endereço do próximo valor no ponteiro "p"
	}
}

// // Função que insere um novo valor, de forma ordenada
// Lista *lst_insere_ordenada(Lista *l, int v)
// {
// 	Lista *novo;								// cria um ponteiro auxiliar "novo"
// 	Lista *ant = NULL;							// cria um ponteiro auxiliar "ant", para apontar para o elemento anterior da lista, e inicializa com [NULL]
// 	Lista *p = l;								// cria um ponteiro auxiliar "p", inicializada com a lista "l"
// 	while (p != NULL && p->info < v)			// O laço de repetição irá percorrer os valores da lista até chegar no fim da lista, ou encontrar um valor menor
// 	{
// 		ant = p;		// "ant" aponta para o valor atual de "p"
// 		p = p->prox;	// "p" passa a apontar para o próximo valor
// 	}
// 	novo = (Lista *)malloc(sizeof(Lista));		// "novo" é inicializado com um novo espaço de memória alocado
// 	novo->info = v;								// o novo elemento tem seu valor info preenchido
	
// 	// o novo elemento será adicionado no encadeamento
// 	if (ant == NULL)		// a lista está vazia, ou não foi encontrado valores menores na lista
// 	{							// novo é adicionado no início da lista
// 		novo->prox = l;			// parâmetro "prox" do novo valor aponta para o endereço do primeiro elemento
// 		l = novo;				// o valor de "novo" é adicionado no início da lista
// 	}
// 	else					// a varredura do laço while foi usada, modificando o valor de "ant"
// 	{								
// 		novo->prox = ant->prox;		// o parâmetro "prox" do novo elemento apontará para o mesmo valor apontado pelo elemento "ant"
// 		ant->prox = novo;			// elemento "ant" apontará para o novo elemento
// 	}
// 	return l;	// retorna o endereço do valor inicial da lista encadeada
// }

// // Função que abre um arquivo e lê os valores armazenados:
// Lista *lst_ler_arquivo(char *nome_arquivo)
// {
// 	FILE *arquivo;							// declara um ponteiro para uma variável do tipo FILE
// 	int valor;								// declara uma variável do tipo inteiro
// 	Lista *l = lst_cria();					// inicializa uma lista
// 	arquivo = fopen(nome_arquivo, "r");		// abre o arquivo com o nome inserido
// 	if (arquivo == NULL)					// verifica se a abertura ocorreu com sucesso
// 	{					
// 		printf("Erro ao abrir o arquivo!\n");	// caso verdadeiro, imprime uma mensagem de erro e encerra o programa.
// 		exit(1);
// 	}
// 	while (fscanf(arquivo, "%d", &valor) != EOF)
// 	{
// 		l = lst_insere(l, valor);
// 	}
// 	fclose(arquivo);
// 	return l;
// }

// void lcirc_imprime(Lista* l) {
// 	Lista *p = l; /* faz p apontar para o nó inicial */
// 	/* testa se lista não é vazia e então percorre com do-while */
// 	if (p) do {
// 		printf("%d\n", p->info); /* imprime informação do nó*/
// 		p = p->prox; /**/
// 	} while (p != l);
// } 