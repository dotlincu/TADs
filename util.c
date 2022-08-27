#include <stdio.h>
#include <stdlib.h>
#include "util.h"

void ImprimirProduto(TProduto item){
    printf("\nCODIGO DO PRODUTO: %d", item.codigo);
    // printf("\n NOME do produto: %s", item.nome);
    // printf("\n DESCRICAO do produto: %s", item.descricao);
    // printf("\n PRECO do produto: %.2f", item.preco);
    // printf("\n UNIDADE do produto: %d", item.unidade);
}

void LerProduto(TProduto *item){
    printf("\nDIGITE O CODIGO DO PRODUTO: ");
    fflush(stdin);
    scanf("%d", &item->codigo);
    /*
    implementar a leitura dos outros campos
    */
}