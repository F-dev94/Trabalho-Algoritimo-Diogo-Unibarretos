#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"

void inicializarFila(ListaFila* fila) {
    fila->primeiro = NULL;
    fila->ultimo = NULL;
}

int estaVazia(ListaFila* fila) {
    return (fila->primeiro == NULL);
}

void inserirElemento(ListaFila* fila, int numero) {
    CelulaFila* novoNo = (CelulaFila*)malloc(sizeof(CelulaFila));
    if (novoNo == NULL) return;
    novoNo->dado = numero;
    novoNo->proximo = NULL;
    if (estaVazia(fila)) {
        fila->primeiro = novoNo;
    } else {
        fila->ultimo->proximo = novoNo;
    }
    fila->ultimo = novoNo;
}

int retirarElemento(ListaFila* fila) {
    if (estaVazia(fila)) return -1;
    CelulaFila* temporario = fila->primeiro;
    int conteudo = temporario->dado;
    fila->primeiro = temporario->proximo;
    if (fila->primeiro == NULL) {
        fila->ultimo = NULL;
    }
    free(temporario);
    return conteudo;
}

void mostrarFila(ListaFila* fila) {
    if (estaVazia(fila)) {
        printf("[Fila Vazia]\n");
        return;
    }
    ListaFila aux;
    inicializarFila(&aux);
    while (!estaVazia(fila)) {
        int v = retirarElemento(fila);
        printf("%d ", v);
        inserirElemento(&aux, v);
    }
    printf("\n");
    while (!estaVazia(&aux)) {
        inserirElemento(fila, retirarElemento(&aux));
    }
}

void destruirFila(ListaFila* fila) {
    while (!estaVazia(fila)) {
        retirarElemento(fila);
    }
}

int buscarElementoFila(ListaFila* fila, int numero) {
    ListaFila aux;
    inicializarFila(&aux);
    int posicao = 1;
    int encontrado = -1;
    while (!estaVazia(fila)) {
        int v = retirarElemento(fila);
        if (v == numero && encontrado == -1) {
            encontrado = posicao;
        }
        inserirElemento(&aux, v);
        posicao++;
    }
    while (!estaVazia(&aux)) {
        inserirElemento(fila, retirarElemento(&aux));
    }
    return encontrado;
}

void buscarEEditarFila(ListaFila* fila, int numeroAntigo, int numeroNovo) {
    ListaFila aux;
    inicializarFila(&aux);
    while (!estaVazia(fila)) {
        int v = retirarElemento(fila);
        if (v == numeroAntigo) {
            v = numeroNovo;
        }
        inserirElemento(&aux, v);
    }
    while (!estaVazia(&aux)) {
        inserirElemento(fila, retirarElemento(&aux));
    }
}

int buscarERemoverFila(ListaFila* fila, int numero) {
    ListaFila aux;
    inicializarFila(&aux);
    int encontrado = 0;
    while (!estaVazia(fila)) {
        int v = retirarElemento(fila);
        if (v == numero && !encontrado) {
            encontrado = 1;
        } else {
            inserirElemento(&aux, v);
        }
    }
    while (!estaVazia(&aux)) {
        inserirElemento(fila, retirarElemento(&aux));
    }
    return encontrado;
}

void eliminarDuplicados(ListaFila* fila) {
    ListaFila auxLimpa;
    inicializarFila(&auxLimpa);
    while (!estaVazia(fila)) {
        int atual = retirarElemento(fila);
        ListaFila tempVerificadora;
        inicializarFila(&tempVerificadora);
        int duplicado = 0;
        while (!estaVazia(&auxLimpa)) {
            int vVerifica = retirarElemento(&auxLimpa);
            if (vVerifica == atual) {
                duplicado = 1;
            }
            inserirElemento(&tempVerificadora, vVerifica);
        }
        while (!estaVazia(&tempVerificadora)) {
            inserirElemento(&auxLimpa, retirarElemento(&tempVerificadora));
        }
        if (!duplicado) {
            inserirElemento(&auxLimpa, atual);
        }
    }
    while (!estaVazia(&auxLimpa)) {
        inserirElemento(fila, retirarElemento(&auxLimpa));
    }
}

void removerNumerosPares(ListaFila* fila) {
    ListaFila aux;
    inicializarFila(&aux);
    while (!estaVazia(fila)) {
        int v = retirarElemento(fila);
        if (v % 2 != 0) {
            inserirElemento(&aux, v);
        }
    }
    while (!estaVazia(&aux)) {
        inserirElemento(fila, retirarElemento(&aux));
    }
}
