#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "util.h"

typedef struct fila{
    TCelula *frente;
    TCelula *tras;
    int tamanho;
} TFila;

void FFVazia(TFila *Fila);

int FilaVazia(TFila Fila);

void Enfileirar(TProduto x, TFila *Fila);

void Desenfileirar(TFila *Fila, TProduto *Item);

int PesquisarFila(TFila Fila, TProduto x);

void ImprimirFila(TFila Fila);

void LiberarFila(TFila* Fila);

#endif // FILA_H_INCLUDED