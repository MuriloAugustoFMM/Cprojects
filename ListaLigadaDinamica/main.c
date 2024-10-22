#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
typedef int bool;
typedef int TIPOCHAVE;

typedef struct
{
    TIPOCHAVE chave;
    //outros campos;
}REGISTRO;

typedef struct aux
{
    REGISTRO reg;
    struct aux* prox;
}ELEMENTO;

typedef ELEMENTO* PONT;

typedef struct
{
    PONT inicio;
}LISTA;

void inicializarLista(LISTA* l)
{
    l->inicio = NULL;

}

int contarElementos(LISTA* l)
{   int tam = 0;
    PONT end = l->inicio;
    while(end != NULL)
    {
        tam++;
        end = end->prox;
    }
    return tam;

}

void imprimirElementos(LISTA* l)
{
    PONT end = l->inicio;
    while(end != NULL)
    {
        printf("%d ",end->reg.chave);
        end = end->prox;
    }

}

PONT buscarSequencial(LISTA* l,TIPOCHAVE ch)
{
    PONT end = l->inicio;
    while(end != NULL)
    {
        if(ch == end->reg.chave) return end;
        end = end->prox;

    }
    return NULL;

}

PONT buscaOrdenada(LISTA* l, TIPOCHAVE ch)
{
    PONT end = l->inicio;
    while(end != NULL && end->reg.chave < ch)
        end = end->prox;
    if(end != NULL && end->reg.chave == ch) return end;
    return NULL;

}
PONT endAnterior(LISTA *l, TIPOCHAVE ch, PONT* aux)
{
    PONT end = l->inicio;
    *aux = NULL;
    while(end != NULL && end->reg.chave < ch)
    {
       aux = end;
       end = end->prox;
    }

    if(end != NULL && end->reg.chave == ch) return end;
    return NULL;

}

bool inserirOrdenado(LISTA* l,REGISTRO reg)
{
    TIPOCHAVE ch = reg.chave;
    PONT ant,i;
    i = endAnterior(l,ch,&ant);
    if(i != NULL ) return -1;
    i = (PONT) malloc(sizeof(ELEMENTO));
    i->reg = reg;
    if(ant != NULL)
    {
        i->prox = ant->prox;
        ant->prox = i;
    }
    else
    {
        i->prox = l->inicio;
        l->inicio = i;
    }
    return 0;


}

bool excluirElemento(LISTA* l, TIPOCHAVE ch)
{
    PONT ant, i;
    i = endAnterior(l,ch,&ant);
    if(i == NULL) return -1;
    if(ant != NULL)
    {
        ant->prox = i->prox;
        free(i);
    }else
    {
        l->inicio = i->prox;
        free(i);
    }
    return 0;
}
void reinicializarLista(LISTA* l)
{
    PONT aux =l->inicio;
    while(l->inicio != NULL)
    {
        aux = l->inicio;
        l->inicio = l->inicio->prox;
        free(aux);
    }

}

int main()
{
    printf("Hello world!\n");
    return 0;
}
