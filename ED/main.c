#include <stdio.h>
#include <stdlib.h>
#define MAX 50

typedef int TIPOCHAVE;

typedef struct
{
    TIPOCHAVE chave;
    //outros campos

} REGISTRO;


typedef struct
{
    REGISTRO A[MAX];
    int nroElem;

} LISTA;

void inicializarLista(LISTA * l)
{
    l->nroElem = 0;
}

int retornarElementosValidos(LISTA* l)
{
    return l->nroElem;
}

void imprimirElementos(LISTA* l)
{
    for(int i =0; i < l->nroElem; i++)
        printf("%i.", l->A[i].chave);
        printf("\n");
}

int buscarElemento(LISTA* l, int ch)
{
    int i = 0;
    while(i < l->nroElem)
    {
        if(ch == l->A[i].chave) return i;
        else i ++;
    }
    return -1;
}

void buscaSentinela(LISTA* l, TIPOCHAVE ch)
{
    int i =0;
    l->A[l->nroElem].chave = ch;
    while(ch != l->A[i].chave) i++;
    if(i != l->nroElem) return i;
    else return -1;
}

int inserirElemento(LISTA* l, int pos, REGISTRO R)
{
    if(l->nroElem == MAX)
    {
        printf("Lista está cheia");
        return -1;
    }
    if(pos < 0 || pos > l->nroElem)
    {
        printf("Posicao invalida");
        return -1;
    }
    for(int i = l->nroElem ; i > pos; i --) l->A[i] = l->A[i-1];

    l->A[pos] = R;
    l->nroElem++;
    return 0;
}

int inserirElementoOrdenado(LISTA* l, REGISTRO R)
{
    if(l->nroElem >= MAX) return -1;
    int pos = l->nroElem;
    while(pos > 0 && l->A[pos-1].chave > R.chave)
    {
        l->A[pos] = l->A[pos-1];
        pos--;
    }
    l->A[pos] = R;
    l->nroElem++;
}

int excluirElemento(LISTA* l, TIPOCHAVE ch)
{
    int pos = buscarElemento(l,ch);

    if(pos < 0) return -1;
    for(int i = pos; i < l->nroElem; i ++)l->A[i].chave = l->A[i+1].chave;
    l->nroElem--;
    return 0;
}
int buscaBinaria(LISTA* l, TIPOCHAVE ch)
{
    int esq, dir, meio;
    esq = 0;
    dir = l->nroElem-1;
    while(esq <= dir)
    {
        meio = (esq + dir)/2
        if(l->A[meio] == ch) return meio;
        else{
            if(l->A[meio].chave < ch) esq = meio + 1;
            else dir = meio - 1;
        }
    }
    return -1;


}

int main()
{
    REGISTRO p1,p2,p3,p4;
    LISTA lista;
    LISTA* l = &lista;
    inicializarLista(l);
    p1.chave = 21;
    p2.chave = 9;
    p3.chave = 55;
    p4.chave = 94;
    inserirElementoOrdenado(l,p1);
    inserirElementoOrdenado(l,p2);
    inserirElementoOrdenado(l,p3);
    imprimirElementos(l);
    inserirElementoOrdenado(l,p4);
    imprimirElementos(l);
    excluirElemento(l,55);
    imprimirElementos(l);

    return 0;
}
