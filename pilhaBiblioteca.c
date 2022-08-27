#include <stdlib.h>
#include <stdio.h>
#include "pilhaBiblioteca.h"
#include "util.c"

void FPVazia(TPilha *Pilha){
    Pilha->topo = (TCelula *)malloc(sizeof(TCelula));
    Pilha->fundo = Pilha->topo;
    Pilha->topo->prox = NULL;
    Pilha->tamanho = 0;
}

int PilhaVazia(TPilha Pilha){
    return (Pilha.topo == Pilha.fundo);
}

void Empilhar(TProduto x, TPilha *Pilha){
    TCelula* Aux;
    Aux = (TCelula*)malloc(sizeof(TCelula));
    Pilha->topo->item = x;
    Aux->prox = Pilha->topo;
    Pilha->topo = Aux;
    Pilha->tamanho++;
}

void Desempilhar(TPilha *Pilha, TProduto *Item){
    TCelula* aux;
    if(PilhaVazia(*Pilha)){
        printf("\nERRO: PILHA VAZIA\n");
        return;
    }
    aux = Pilha->topo;
    Pilha->topo = aux->prox;
    *Item = aux->prox->item;
    free(aux);
    Pilha->tamanho--;
}

int PesquisarPilha(TPilha Pilha, TProduto x){
    TPilha PAux;
    TProduto item;
    FPVazia(&PAux);
    int result = 0;

    while (!PilhaVazia(Pilha)){
        Desempilhar(&Pilha, &item);
        if(x.codigo == item.codigo){
            result = 1;
        }
        Empilhar(item, &PAux);
    }

    while(!PilhaVazia(PAux)){
        Desempilhar(&PAux, &item);
        Empilhar(item, &Pilha);
        free(&PAux.topo);
    }
    return result;
}

void ImprimirPilha(TPilha Pilha){
    TPilha PAux;
    TProduto item;
    FPVazia(&PAux);

    while (!PilhaVazia(Pilha)){
        Desempilhar(&Pilha, &item);
        ImprimirProduto(item);
        Empilhar(item, &PAux);
    }

    while(!PilhaVazia(PAux)){
        Desempilhar(&PAux, &item);
        Empilhar(item, &Pilha);
        free(&PAux.topo);
    }
}

void LiberarPilha(TPilha *Pilha){
    TProduto x;
    while (!PilhaVazia(*Pilha)){
        Desempilhar(Pilha, &x);
    }
    free(&Pilha->topo);
}