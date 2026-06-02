#ifndef LISTA_H
#define LISTA_H

typedef struct Celula {
    int dado;
    struct Celula* proximo;
} Celula;

typedef struct Celula Node;
typedef struct Celula Nodo;

Celula* criarLista();
int listaVazia(Celula* sequencia);
void inserirInicio(Celula** sequencia, int numero);
void inserirFim(Celula** sequencia, int numero);
void mostrarLista(Celula* sequencia);
void liberarLista(Celula** sequencia);

int maxLista(Node* lista);
int minLista(Node* lista);
float mediaLista(Node* lista);
int lenLista(Node* lista);
Nodo* appendLista(Nodo* L1, Nodo* L2);
Nodo* reverseLista(Nodo* lista);
int isSubLista(Nodo* L1, Nodo* L2);

#endif
