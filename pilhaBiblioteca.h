#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "util.h"

typedef struct pilha{
    TCelula *fundo;
    TCelula *topo;
    int tamanho;
} TPilha;

void FPVazia(TPilha *Pilha);

int PilhaVazia(TPilha Pilha);

void Empilhar(TProduto x, TPilha *Pilha);

void Desempilhar(TPilha *Pilha, TProduto *item);

int PesquisarPilha(TPilha Pilha, TProduto x);

void ImprimirPilha(TPilha Pilha);

void LiberarPilha(TPilha *Pilha);

#endif //PILHA_H_INCLUDED