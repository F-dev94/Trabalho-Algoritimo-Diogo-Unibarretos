#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

Celula* criarLista() {
    return NULL;
}

int listaVazia(Celula* sequencia) {
    return (sequencia == NULL);
}

void inserirInicio(Celula** sequencia, int numero) {
    Celula* novoNo = (Celula*)malloc(sizeof(Celula));
    if (novoNo == NULL) return;
    novoNo->dado = numero;
    novoNo->proximo = *sequencia;
    *sequencia = novoNo;
}

void inserirFim(Celula** sequencia, int numero) {
    Celula* novoNo = (Celula*)malloc(sizeof(Celula));
    if (novoNo == NULL) return;
    novoNo->dado = numero;
    novoNo->proximo = NULL;
    if (listaVazia(*sequencia)) {
        *sequencia = novoNo;
        return;
    }
    Celula* auxiliar = *sequencia;
    while (auxiliar->proximo != NULL) {
        auxiliar = auxiliar->proximo;
    }
    auxiliar->proximo = novoNo;
}

void mostrarLista(Celula* sequencia) {
    if (listaVazia(sequencia)) {
        printf("[Lista Vazia]\n");
        return;
    }
    Celula* auxiliar = sequencia;
    while (auxiliar != NULL) {
        printf("%d -> ", auxiliar->dado);
        auxiliar = auxiliar->proximo;
    }
    printf("NULL\n");
}

void liberarLista(Celula** sequencia) {
    Celula* auxiliar = *sequencia;
    while (auxiliar != NULL) {
        Celula* proxNo = auxiliar->proximo;
        free(auxiliar);
        auxiliar = proxNo;
    }
    *sequencia = NULL;
}

int maxLista(Node* lista) {
    if (listaVazia(lista)) return -1;
    int maiorValor = lista->dado;
    Node* auxiliar = lista->proximo;
    while (auxiliar != NULL) {
        if (auxiliar->dado > maiorValor) {
            maiorValor = auxiliar->dado;
        }
        auxiliar = auxiliar->proximo;
    }
    return maiorValor;
}

int minLista(Node* lista) {
    if (listaVazia(lista)) return -1;
    int menorValor = lista->dado;
    Node* auxiliar = lista->proximo;
    while (auxiliar != NULL) {
        if (auxiliar->dado < menorValor) {
            menorValor = auxiliar->dado;
        }
        auxiliar = auxiliar->proximo;
    }
    return menorValor;
}

float mediaLista(Node* lista) {
    if (listaVazia(lista)) return 0.0;
    int acumuladorSoma = 0;
    int contadorItens = 0;
    Node* auxiliar = lista;
    while (auxiliar != NULL) {
        acumuladorSoma += auxiliar->dado;
        contadorItens++;
        auxiliar = auxiliar->proximo;
    }
    return (float)acumuladorSoma / contadorItens;
}

int lenLista(Node* lista) {
    int tamanho = 0;
    Node* auxiliar = lista;
    while (auxiliar != NULL) {
        tamanho++;
        auxiliar = auxiliar->proximo;
    }
    return tamanho;
}

Nodo* appendLista(Nodo* L1, Nodo* L2) {
    if (listaVazia(L1)) return L2;
    Nodo* auxiliar = L1;
    while (auxiliar->proximo != NULL) {
        auxiliar = auxiliar->proximo;
    }
    auxiliar->proximo = L2;
    return L1;
}

Nodo* reverseLista(Nodo* lista) {
    Nodo* anterior = NULL;
    Nodo* atual = lista;
    Nodo* proximoNo = NULL;
    while (atual != NULL) {
        proximoNo = atual->proximo;
        atual->proximo = anterior;
        anterior = atual;
        atual = proximoNo;
    }
    return anterior;
}

int checarSequencia(Nodo* pPrincipal, Nodo* pSub) {
    while (pSub != NULL) {
        if (pPrincipal == NULL || pPrincipal->dado != pSub->dado) {
            return 0;
        }
        pPrincipal = pPrincipal->proximo;
        pSub = pSub->proximo;
    }
    return 1;
}

int isSubLista(Nodo* L1, Nodo* L2) {
    if (listaVazia(L2)) return 1;
    if (listaVazia(L1)) return 0;
    Nodo* auxiliarP = L1;
    while (auxiliarP != NULL) {
        if (auxiliarP->dado == L2->dado) {
            if (checarSequencia(auxiliarP, L2)) {
                return 1;
            }
        }
        auxiliarP = auxiliarP->proximo;
    }
    return 0;
}
