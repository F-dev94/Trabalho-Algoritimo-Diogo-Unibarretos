#ifndef FILA_H
#define FILA_H

typedef struct CelulaFila {
    int dado;
    struct CelulaFila* proximo;
} CelulaFila;

typedef struct {
    CelulaFila* primeiro;
    CelulaFila* ultimo;
} ListaFila;

void inicializarFila(ListaFila* fila);
int estaVazia(ListaFila* fila);
void inserirElemento(ListaFila* fila, int numero);
int retirarElemento(ListaFila* fila);
void mostrarFila(ListaFila* fila);
void destruirFila(ListaFila* fila);

int buscarElementoFila(ListaFila* fila, int numero);
void buscarEEditarFila(ListaFila* fila, int numeroAntigo, int numeroNovo);
int buscarERemoverFila(ListaFila* fila, int numero);
void eliminarDuplicados(ListaFila* fila);
void removerNumerosPares(ListaFila* fila);

#endif
