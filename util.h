#ifndef UTIL_H_INCLUDED
#define UTIL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct produto{
    int codigo;
} TProduto;

typedef struct celular{
    TProduto item;
    struct celular *prox;
} TCelula;

void ImprimirProduto(TProduto item);

void LerProduto(TProduto *item);

#endif //UTIL_H_INCLUDED