#include <stdio.h>
#include <stdlib.h>
// #include "util.c"
#include "listaBiblioteca.c"
#include "filaBiblioteca.c"
#include "pilhaBiblioteca.c"

void MSG_MENU(){
    printf("\n******************** MENU GERAL ***********************");
    printf("\n\t1. INSERIR");
    printf("\n\t2. ENFILEIRAR");
    printf("\n\t3. EMPILHAR");
    printf("\n\t4. INVERTER PILHA");
    printf("\n\t5. INVERTER FILA");
    printf("\n\t6. INVERTER LISTA");
    printf("\n\t7. EXCLUIR ELEMENTO EM FILA");
    printf("\n\t8. EXCLUIR ELEMENTO EM PILHA");
    printf("\n\t9. IMPRIMIR LISTA");
    printf("\n\t10. IMPRIMIR FILA");
    printf("\n\t11. IMPRIMIR PILHA");
    printf("\n\t12. DIVIDIR PILHA");
    printf("\n\t13. FUNDIR FILA");
    printf("\n\t14. SAIR");
}

int main(){
    TLista lista;
    TFila fila;
    TPilha pilha;
    TProduto item;
    TFila FAux1;
    TFila FAux2;
    TFila FAux3;
    TPilha PAux1;
    TPilha PAux2;
    TProduto aux;

    FLVazia(&lista);
    FFVazia(&fila);
    FPVazia(&pilha);

    int opcao = 0;

    do
    {
        system("cls");
        MSG_MENU();
        printf("\n\nDIGITE UMA OPCAO: ");
        fflush(stdin);
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            system("cls");
            printf("\n\n>>>>>>>>>>>>>>>> MSG: INSIRA UM CODIGO NA LISTA! <<<<<<<<<<<<<<<<\n\n");
            LerProduto(&item);
            Inserir(item, &lista);
            printf("\n\n>>>>>>>>>>>>>>>> MSG: PRODUTO INSERIDO COM SUCESSO! <<<<<<<<<<<<<<<<\n\n");
            system("PAUSE");
            break;
        case 2:
            system("cls");
            printf("\n\n>>>>>>>>>>>>>>>> MSG: ENFILEIRE UM CODIGO NA FILA! <<<<<<<<<<<<<<<<\n\n");
            LerProduto(&item);
            Enfileirar(item, &fila);
            printf("\n\n>>>>>>>>>>>>>>>> MSG: PRODUTO ENFILEIRADO COM SUCESSO! <<<<<<<<<<<<<<<<\n\n");
            system("PAUSE");
            break;
        case 3:
            system("cls");
            printf("\n\n>>>>>>>>>>>>>>>> MSG: EMPILHE UM CODIGO NA PILHA! <<<<<<<<<<<<<<<<\n\n");
            LerProduto(&item);
            Empilhar(item, &pilha);
            printf("\n\n>>>>>>>>>>>>>>>> MSG: PRODUTO EMPILHADO COM SUCESSO! <<<<<<<<<<<<<<<<\n\n");
            system("PAUSE");
            break; 
        case 4:
            system("cls");
            FFVazia(&FAux1);
            if (!PilhaVazia(pilha)){
                printf("\n\nPILHA:\n\n");
                ImprimirPilha(pilha);
                while(!PilhaVazia(pilha)){
                    Desempilhar(&pilha, &item);
                    Enfileirar(item, &FAux1);
                }
                while(!FilaVazia(FAux1)){
                    Desenfileirar(&FAux1, &item);
                    Empilhar(item, &pilha);
                    free(&FAux1.frente);
                }
                printf("\n\nPILHA APOS INVERSAO:\n\n");
                ImprimirPilha(pilha);
                printf("\n\n>>>>>>>>>>>>>>>> MSG: PILHA INVERTIDA COM SUCESSO! <<<<<<<<<<<<<<<<\n\n");
            }
            else
                printf("\n\n>>>>>>>>>>>>>>>> MSG: PILHA VAZIA! FAVOR PREENCHER! <<<<<<<<<<<<<<<<\n\n");
            system("PAUSE");
            break;
        case 5:
            system("cls");
            FPVazia(&PAux1);
            if (!FilaVazia(fila)){
                printf("\n\nFILA: \n\n");
                ImprimirFila(fila);
                while(!FilaVazia(fila)){
                    Desenfileirar(&fila, &item);
                    Empilhar(item, &PAux1);
                }
                while(!PilhaVazia(PAux1)){
                    Desempilhar(&PAux1, &item);
                    Enfileirar(item, &fila);
                    free(&PAux1.topo);
                }
                printf("\n\nFILA APOS INVERSAO: \n\n");
                ImprimirFila(fila);
                printf("\n\n>>>>>>>>>>>>>>>> MSG: FILA INVERTIDA COM SUCESSO! <<<<<<<<<<<<<<<<\n\n");
            }
            else
                printf("\n\n>>>>>>>>>>>>>>>> MSG: FILA VAZIA! FAVOR PREENCHER! <<<<<<<<<<<<<<<<\n\n");
            system("PAUSE");
            break;
        case 6:
            system("cls");

            system("PAUSE");
            break;
        case 7:
            system("cls");
            if(!FilaVazia(fila)){
                FFVazia(&FAux1);
                printf("\n\nFILA: \n");
                ImprimirFila(fila);
                printf("\n\n>>>>>>>>>>>>>>>> MSG: DIGITE UM ITEM DA FILA A SER EXCLUIDO <<<<<<<<<<<<<<<<\n\n");
                LerProduto(&item);
                while (!FilaVazia(fila)){
                    Desenfileirar(&fila, &aux);
                    if(aux.codigo != item.codigo){
                        Enfileirar(aux, &FAux1);
                    }
                }
                while (!FilaVazia(FAux1)){
                    Desenfileirar(&FAux1, &aux);
                    Enfileirar(aux, &fila);
                    free(&FAux1.frente);
                }
                printf("\nFILA: ");
                ImprimirFila(fila);
                printf("\n\n>>>>>>>>>>>>>>>> MSG: ITEM DA FILA EXCLUIDO COM SUCESSO! <<<<<<<<<<<<<<<<\n\n");
            }
            else
                printf("\n\n>>>>>>>>>>>>>>>> MSG: FILA VAZIA! FAVOR PREENCHER! <<<<<<<<<<<<<<<<\n\n");
            system("PAUSE");
            break;
        case 8:
            system("cls");
            if(!PilhaVazia(pilha)){
                FPVazia(&PAux1);
                printf("\n\nPILHA: \n");
                ImprimirPilha(pilha);
                printf("\n\n>>>>>>>>>>>>>>>> MSG: DIGITE O ITEM DA PILHA A SER EXCLUIDO <<<<<<<<<<<<<<<<\n\n");
                LerProduto(&item);
                while (!PilhaVazia(pilha)){
                    Desempilhar(&pilha, &aux);
                    if(aux.codigo != item.codigo){
                        Empilhar(aux, &PAux1);
                    }
                }
                while (!PilhaVazia(PAux1)){
                    Desempilhar(&PAux1, &aux);
                    Empilhar(aux, &pilha);
                    free(&PAux1.topo);
                }
                printf("\nPILHA: ");
                ImprimirPilha(pilha);
                printf("\n\n>>>>>>>>>>>>>>>> MSG: ITEM DA PILHA EXCLUIDO COM SUCESSO! <<<<<<<<<<<<<<<<\n\n");
            }
            else
                printf("\n\n>>>>>>>>>>>>>>>> MSG: PILHA VAZIA! FAVOR PREENCHER! <<<<<<<<<<<<<<<<\n\n");
            system("PAUSE");
            break;
        case 9:
            system("cls");
            if (!ListaVazia(lista)){
                printf("\n\nLISTA:\n");
                ImprimirLista(lista);
                printf("\n\n>>>>>>>>>>>>>>>> MSG: LISTA IMPRESSA! <<<<<<<<<<<<<<<<\n\n");
            }
            else
                printf("\n\n>>>>>>>>>>>>>>>> MSG: LISTA VAZIA! FAVOR PREENCHER! <<<<<<<<<<<<<<<<\n\n");
            system("PAUSE");
            break;
        case 10:
            system("cls");
            if (!FilaVazia(fila)){
                printf("\n\nFILA:\n");
                ImprimirFila(fila);
                printf("\n\n>>>>>>>>>>>>>>>> MSG: FILA IMPRESSA! <<<<<<<<<<<<<<<<\n\n");
            }
            else
                printf("\n\n>>>>>>>>>>>>>>>> MSG: FILA VAZIA! FAVOR PREENCHER! <<<<<<<<<<<<<<<<\n\n");
            system("PAUSE");
            break;
        case 11:
            system("cls");
            if (!PilhaVazia(pilha)){
                printf("\n\nPILHA:\n");
                ImprimirPilha(pilha);
                printf("\n\n>>>>>>>>>>>>>>>> MSG: PILHA IMPRESSA! <<<<<<<<<<<<<<<<\n\n");
            }
            else
                printf("\n\n>>>>>>>>>>>>>>>> MSG: PILHA VAZIA! FAVOR PREENCHER! <<<<<<<<<<<<<<<<\n\n");
            system("PAUSE");
            break;
        case 12:
            system("cls");
            if(!PilhaVazia(pilha)){
                FPVazia(&PAux1);
                FPVazia(&PAux2);
                while(!PilhaVazia(pilha)){
                    Desempilhar(&pilha, &item);
                    Empilhar(item, &PAux2);
                    if(!PilhaVazia(pilha)){
                        Desempilhar(&pilha, &item);
                        Empilhar(item, &PAux1);
                    }
                    free(&pilha.topo);
                }
                printf("\n\nPILHA 1:\n");
                ImprimirPilha(PAux1);
                printf("\n\nPILHA 2:\n");
                ImprimirPilha(PAux2);
                printf("\n\n");
            }
            else
                printf("\n\n>>>>>>>>>>>>>>>> MSG: PILHA VAZIA! FAVOR PREENCHER! <<<<<<<<<<<<<<<<\n\n");    
            system("PAUSE");
            break;
        case 13:
            system("cls");
            FFVazia(&FAux1);
            FFVazia(&FAux2);
            FFVazia(&FAux3);
            int i;
            for (i = 1; i < 6; i++){
                item.codigo = i;
                Enfileirar(item, &FAux1);
            }
            for(i = 6; i < 11; i++){
                item.codigo = i;
                Enfileirar(item, &FAux2);
            }
            printf("\n\nFILA 1:\n");
            ImprimirFila(FAux1);
            printf("\n\nFILA 2:\n");
            ImprimirFila(FAux2);
            while(!FilaVazia(FAux1) && !FilaVazia(FAux2)){
                Desenfileirar(&FAux1,&item);
                Enfileirar(item, &FAux3);
                if(!FilaVazia(FAux2)){
                    Desenfileirar(&FAux2,&item);
                    Enfileirar(item, &FAux3);
                }
            }
            printf("\n\nFILA 3:\n");
            ImprimirFila(FAux3);
            printf("\n\n");
            system("PAUSE");
            break;
        default:
            system("cls");
            printf("\n\n>>>>>>>>>>>>>>>> MSG: OPCAO INVALIDA! DIGITE NOVAMENTE! <<<<<<<<<<<<<<<<\n\n");
            system("PAUSE");
            break;
        }
    } while (opcao != 14);
    
    LiberarLista(&lista);
    LiberarFila(&fila);
    LiberarPilha(&pilha);
    system("PAUSE");
    return 0;
}
