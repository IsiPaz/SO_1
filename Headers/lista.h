#ifndef LISTA_H_
#define LISTA_H_
#include "gametda.h"

/*
TDA Lista:
Miembros:
	actual: Puntero al nodo actual.
	head: Puntero a la cabeza "fantasma".
	tail: Puntero al ultimo nodo.
	length: Largo de la lista.

Metodos:
	init: Inicializa un lista vacia.

	destroy: Libera toda la memoria de una lista.

	clear: Libera la memoria de los itemes de la lista,
		pero no la cabeza fantasma.

	insert: Inserta un struct game en una posicion dada.

	append: Inserta un struct game en la cola de la lista.

	remove_: Elimina un nodo en la posicion dada.

	length: Retorna el largo de la lista.

	at: Retorna el struct game de la posicion dada.

	sort: Recibe una lista y retorna esa misma lista ordenada ascedentemente.

Struct Nodo:
Contiene el struct game y un punto al nodo siguiente.
*/

struct nodo{
	game *info;
	struct nodo *next;
};

typedef struct Lista {
	struct nodo *actual;
	struct nodo *head;
	struct nodo *tail;
	int length;
} lista;

void init(lista *);
void destroy(lista *);
void clear(lista *);
void insert(lista *, int, game *);
void append(lista *, game *);
void remove_(lista *, int);
int length(lista *);
game *at(lista *, int);
lista *sort(lista *);

#endif