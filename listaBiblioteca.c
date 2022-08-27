#include <stdlib.h>
#include <stdio.h>
#include "listaBiblioteca.h"
#include "util.h"

void FLVazia(TLista *Lista){
    Lista -> primeiro = (TCelula *) malloc(sizeof(TCelula));
    Lista -> ultimo = Lista -> primeiro;
    Lista -> primeiro -> prox = NULL;
    Lista -> tamanho = 0;
}

int ListaVazia(TLista Lista){
    return (Lista.primeiro == Lista.ultimo);
}

void Inserir(TProduto x, TLista *Lista){
    Lista -> ultimo -> prox = (TCelula *) malloc(sizeof(TCelula));
    Lista -> ultimo = Lista -> ultimo -> prox;
    Lista -> ultimo -> item = x;
    Lista -> ultimo -> prox = NULL;
    Lista -> tamanho++;
}

void Excluir(TLista *Lista, TProduto *Item){
    TCelula *Aux1, *Aux2;
    Aux1 = PesquisarLista(*Lista, *Item);
    if (Aux1 != NULL) {
        Aux2 = Aux1->prox;
        Aux1->prox = Aux2 -> prox;
        *Item = Aux2->item;
        if (Aux1->prox == NULL)
            Lista->ultimo = Aux1;
        free(Aux2);
        Lista->tamanho--;
    }
}

TCelula* PesquisarLista(TLista Lista, TProduto Item){
    TCelula* Aux;
    Aux = Lista.primeiro;
    while(Aux->prox != NULL){
        if(Aux->prox->item.codigo == Item.codigo)
            return Aux;
        Aux = Aux->prox;
    }
    return NULL;
}

void ImprimirLista(TLista Lista){
    TCelula* Aux;
    Aux = Lista.primeiro -> prox;
    while (Aux != NULL){
        ImprimirProduto(Aux->item);
        Aux = Aux -> prox;
    }
}

void AlterarLista(TLista Lista){
    TCelula *Aux;
    TProduto item, x;
    printf("\nITEM A SER ALTERADO: ");
    LerProduto(&item);
    Aux = PesquisarLista(Lista, item);
    if(Aux->prox != NULL){
        printf("\nNOVO VALOR: ");
        LerProduto(&x);
        Aux->prox->item = x;
    }
    else
        printf("\n\nDADO NAO ENCONTRADO!\n\n");    
}

void LiberarLista(TLista *Lista){
    TProduto x;
    while(!ListaVazia(*Lista)){
        Excluir(Lista, &x);   //Excluir(Lista,&Lista->prim->item)
    }
    free(&Lista->primeiro);
}
