#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "Lista.h"
#include "Pilha.h"
#include "Fila.h"

int main() {
    setlocale(LC_ALL, "");

    Celula* L1 = criarLista();
    inserirFim(&L1, 10);
    inserirFim(&L1, 20);
    inserirFim(&L1, 5);
    inserirFim(&L1, 15);
    mostrarLista(L1);

    maxLista(L1);
    minLista(L1);
    mediaLista(L1);
    lenLista(L1);

    Celula* L2 = criarLista();
    inserirFim(&L2, 20);
    inserirFim(&L2, 5);
    isSubLista(L1, L2);

    L1 = reverseLista(L1);
    mostrarLista(L1);

    L1 = appendLista(L1, L2);
    mostrarLista(L1);

    EstruturaPilha pilha;
    criarPilha(&pilha);
    empilhar(&pilha, 10);
    empilhar(&pilha, 15);
    empilhar(&pilha, 10);
    empilhar(&pilha, 22);
    empilhar(&pilha, 33);
    mostrarPilha(&pilha);

    buscarElemento(&pilha, 15);
    buscarERemover(&pilha, 33);
    removerPares(&pilha);
    removerRepetidos(&pilha);
    mostrarPilha(&pilha);

    ListaFila fila;
    inicializarFila(&fila);
    inserirElemento(&fila, 4);
    inserirElemento(&fila, 7);
    inserirElemento(&fila, 4);
    inserirElemento(&fila, 12);
    inserirElemento(&fila, 9);
    mostrarFila(&fila);

    buscarElementoFila(&fila, 7);
    buscarEEditarFila(&fila, 7, 77);
    buscarERemoverFila(&fila, 12);
    removerNumerosPares(&fila);
    eliminarDuplicados(&fila);
    mostrarFila(&fila);

    liberarLista(&L1);
    liberarPilha(&pilha);
    destruirFila(&fila);

    return 0;
}
