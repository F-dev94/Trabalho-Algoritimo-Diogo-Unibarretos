#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"

void criarPilha(EstruturaPilha* estrutura) {
    estrutura->topoAtual = NULL;
}

int pilhaVazia(EstruturaPilha* estrutura) {
    return (estrutura->topoAtual == NULL);
}

void empilhar(EstruturaPilha* estrutura, int numero) {
    CelulaPilha* novoNo = (CelulaPilha*)malloc(sizeof(CelulaPilha));
    if (novoNo == NULL) return;
    novoNo->dado = numero;
    novoNo->anterior = estrutura->topoAtual;
    estrutura->topoAtual = novoNo;
}

int desempilhar(EstruturaPilha* estrutura) {
    if (pilhaVazia(estrutura)) return -1;
    CelulaPilha* auxiliar = estrutura->topoAtual;
    int valor = auxiliar->dado;
    estrutura->topoAtual = auxiliar->anterior;
    free(auxiliar);
    return valor;
}

void mostrarPilha(EstruturaPilha* estrutura) {
    if (pilhaVazia(estrutura)) {
        printf("[Pilha Vazia]\n");
        return;
    }
    EstruturaPilha temp;
    criarPilha(&temp);
    while (!pilhaVazia(estrutura)) {
        int v = desempilhar(estrutura);
        printf("%d\n", v);
        empilhar(&temp, v);
    }
    while (!pilhaVazia(&temp)) {
        empilhar(estrutura, desempilhar(&temp));
    }
}

void liberarPilha(EstruturaPilha* estrutura) {
    while (!pilhaVazia(estrutura)) {
        desempilhar(estrutura);
    }
}

int buscarElemento(EstruturaPilha* estrutura, int numero) {
    EstruturaPilha temp;
    criarPilha(&temp);
    int posicao = 1;
    int encontrado = -1;
    while (!pilhaVazia(estrutura)) {
        int v = desempilhar(estrutura);
        if (v == numero && encontrado == -1) {
            encontrado = posicao;
        }
        empilhar(&temp, v);
        posicao++;
    }
    while (!pilhaVazia(&temp)) {
        empilhar(estrutura, desempilhar(&temp));
    }
    return encontrado;
}

int buscarERemover(EstruturaPilha* estrutura, int numero) {
    EstruturaPilha temp;
    criarPilha(&temp);
    int encontrado = 0;
    while (!pilhaVazia(estrutura)) {
        int v = desempilhar(estrutura);
        if (v == numero && !encontrado) {
            encontrado = 1;
        } else {
            empilhar(&temp, v);
        }
    }
    while (!pilhaVazia(&temp)) {
        empilhar(estrutura, desempilhar(&temp));
    }
    return encontrado;
}

void removerPares(EstruturaPilha* estrutura) {
    EstruturaPilha temp;
    criarPilha(&temp);
    while (!pilhaVazia(estrutura)) {
        int v = desempilhar(estrutura);
        if (v % 2 != 0) {
            empilhar(&temp, v);
        }
    }
    while (!pilhaVazia(&temp)) {
        empilhar(estrutura, desempilhar(&temp));
    }
}

void removerRepetidos(EstruturaPilha* estrutura) {
    EstruturaPilha tempLimpa;
    EstruturaPilha tempVerificadora;
    criarPilha(&tempLimpa);
    criarPilha(&tempVerificadora);
    while (!pilhaVazia(estrutura)) {
        int atual = desempilhar(estrutura);
        int duplicado = 0;
        while (!pilhaVazia(&tempLimpa)) {
            int vVerifica = desempilhar(&tempLimpa);
            if (vVerifica == atual) {
                duplicado = 1;
            }
            empilhar(&tempVerificadora, vVerifica);
        }
        while (!pilhaVazia(&tempVerificadora)) {
            empilhar(&tempLimpa, desempilhar(&tempVerificadora));
        }
        if (!duplicado) {
            empilhar(&tempLimpa, atual);
        }
    }
    while (!pilhaVazia(&tempLimpa)) {
        empilhar(estrutura, desempilhar(&tempLimpa));
    }
}
