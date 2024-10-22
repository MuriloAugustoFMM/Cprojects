#include <stdio.h>
#include <stdlib.h>
#define MAX 50
#define INVALIDO -1
typedef int TIPOCHAVE;

typedef struct
{
    TIPOCHAVE chave;
    //outros campos;

}REGISTRO;

typedef struct
{
    REGISTRO reg;
    int prox;

}ELEMENTO;

typedef struct
{
    ELEMENTO A[MAX];
    int inicio;
    int dispo;

}LISTA;

void inicializarLista(LISTA* l){
    int i = 0;
    for(i=0; i < MAX-1; i++)
    {
        l->A[i].prox = i + 1;
    }
    l->A[MAX-1].prox = INVALIDO;
    l->inicio = INVALIDO;
    l->dispo = 0;

    printf("Lista inicializada!\n");

}

int numeroElementos(LISTA* l){
   int i = l->inicio,c = 0;
   while(i != INVALIDO)
   {
       c++;
       i = l->A[i].prox;
   }
   return c;
}

void imprimirElementos(LISTA* l)
{
   int i = l->inicio;
   while(i != INVALIDO)
   {
       printf("%i ",l->A[i].reg.chave);
       i = l->A[i].prox;
   }


}
int obterNo(LISTA* l)
{
    int resultado = l->dispo;
    if(l->dispo != INVALIDO)
        l->dispo = l->A[l->dispo].prox;
    return resultado;
}

int buscarElemento(LISTA* l, TIPOCHAVE ch)
{
    int i = l->inicio;
    while(i != INVALIDO && l->A[i].reg.chave < ch)
    {
        i = l->A[i].prox;
    }
    if(i != INVALIDO && ch == l->A[i].reg.chave) return i;
    else return -1;

}

int inserirElemento(LISTA* l, REGISTRO reg)
{
    // nao é permitido repetição de chaves
    if(l->dispo == INVALIDO) return INVALIDO;

    TIPOCHAVE chave = reg.chave;
    int i =l->inicio;
    int ant = INVALIDO;
    int resultado = obterNo(l);
    while(i != INVALIDO && chave > l->A[i].reg.chave)
    {
       ant = i;
       i=l->A[i].prox;
    }

    if(ant == INVALIDO)
    {
        l->A[resultado].reg = reg;
        l->A[resultado].prox = i;
        l->inicio = resultado;
    }
    if(ant != INVALIDO && chave < l->A[i].reg.chave)
    {
        l->A[resultado].reg = reg;
        l->A[resultado].prox = i;
        l->A[ant].prox = resultado;
    }
    if(i == INVALIDO)
    {
        l->A[resultado].reg = reg;
        l->A[resultado].prox = INVALIDO;
        l->A[ant].prox = resultado;
    }
    return 0;

}

int excluiritem(LISTA* l, TIPOCHAVE ch){
    int i = l->inicio;
    int ant = INVALIDO;
    while(i != INVALIDO && l->A[i].reg.chave < ch)
    {
        ant = i;
        i = l->A[i].prox;
    }
    if(i == INVALIDO || l->A[i].reg.chave != ch) return -1;

    if(ant != INVALIDO)l->A[ant].prox = l->A[i].prox;
    else l->inicio = l->A[i].prox;

    l->A[i].prox = l->dispo;
    l->dispo = i;
    return 0 ;


}

int main()
{
    REGISTRO p1,p2,p3,p4;
    LISTA lista;
    p1.chave = 33;
    p2.chave = 93;
    p3.chave = 2;
    p4.chave = 34;
    LISTA* l = &lista;
    inicializarLista(l);
    inserirElemento(l,p1);
    inserirElemento(l,p2);
    inserirElemento(l,p3);
    inserirElemento(l,p4);
    imprimirElementos(l);
    return 0;
}
