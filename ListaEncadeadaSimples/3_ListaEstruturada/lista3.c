#include <stdlib.h>

typedef struct retangulo
{
    float b;
    float h;
} 
Retangulo;

typedef struct lista3
{
    Retangulo info;
    struct lista3 *prox;
}
Lista3;


static Lista3 *aloca(float b, float h)
{
    Lista3* p = (Lista3*)malloc(sizeof(Lista3));
    p->info.b = b;
    p->info.h = h;
    p->prox = NULL;
    return p;
}

