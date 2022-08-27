#include <stdlib.h>
#include <stdio.h>
#include "filaBiblioteca.h"
#include "util.h"

void FFVazia(TFila *Fila){
    Fila -> frente = (TCelula *) malloc(sizeof(TCelula));
    Fila -> tras = Fila -> frente;
    Fila -> frente -> prox = NULL;
    Fila -> tamanho = 0;
}

int FilaVazia(TFila Fila){
    return (Fila.frente == Fila.tras);
}

void Enfileirar(TProduto x, TFila *Fila){
    Fila -> tras -> prox = (TCelula *) malloc(sizeof(TCelula));
    Fila -> tras = Fila -> tras -> prox;
    Fila -> tras -> item = x;
    Fila -> tras -> prox = NULL;
    Fila -> tamanho++;
}

void Desenfileirar(TFila *Fila, TProduto *Item){
    TCelula *aux;
    if (!FilaVazia(*Fila)) {
       aux = Fila -> frente -> prox;
        Fila -> frente -> prox = aux -> prox;
        *Item = aux -> item;
        free(aux);
        if (Fila -> frente -> prox == NULL)
            Fila -> tras = Fila -> frente;
        Fila->tamanho--;
    }
    else
        printf("\nERRO: FILA VAZIA!");
}

int PesquisarFila(TFila Fila, TProduto x){
    TFila FAux;
    TProduto item;
    FFVazia(&FAux);
    
    int result = 0;

    while (!FilaVazia(Fila)){
        Desenfileirar(&Fila, &item);
        if(x.codigo == item.codigo){
            result = 1;
        }
        Enfileirar(item, &FAux);
    }

    while (!FilaVazia(FAux)){
        Desenfileirar(&FAux, &item);
        Enfileirar(item, &Fila);
        free(&FAux.frente);
    }
    return result;
}

void ImprimirFila(TFila Fila){
    TFila FAux;
    TProduto x;
    FFVazia(&FAux);

    while (!FilaVazia(Fila)){
        Desenfileirar(&Fila, &x);
        ImprimirProduto(x);
        Enfileirar(x, &FAux);
    }

    while (!FilaVazia(FAux)){
        Desenfileirar(&FAux, &x);
        Enfileirar(x, &Fila);
        free(&FAux.frente);
    }
}

void LiberarFila(TFila *Fila){
    TProduto x;
    while(!FilaVazia(*Fila)){
        Desenfileirar(Fila, &x);
    }
    free(&Fila->frente);
}