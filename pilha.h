#ifndef PILHA_H
#define PILHA_H

typedef struct CelulaPilha {
    int dado;
    struct CelulaPilha* anterior;
} CelulaPilha;

typedef struct {
    CelulaPilha* topoAtual;
} EstruturaPilha;

void criarPilha(EstruturaPilha* estrutura);
int pilhaVazia(EstruturaPilha* estrutura);
void empilhar(EstruturaPilha* estrutura, int numero);
int desempilhar(EstruturaPilha* estrutura);
void mostrarPilha(EstruturaPilha* estrutura);
void liberarPilha(EstruturaPilha* estrutura);

int buscarElemento(EstruturaPilha* estrutura, int numero);
int buscarERemover(EstruturaPilha* estrutura, int numero);
void removerPares(EstruturaPilha* estrutura);
void removerRepetidos(EstruturaPilha* estrutura);

#endif
