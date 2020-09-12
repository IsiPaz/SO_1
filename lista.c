#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "gametda.h"

void init(lista *a) {
	a -> head = a -> tail = a -> actual = (struct nodo *)malloc(sizeof(struct nodo));
	a -> head -> next = NULL;
	a -> length = 0; 
}

void destroy(lista *a) {
	clear(a);
	free(a -> head);
}

void clear(lista *a) {
	if (a -> length > 0) {
		a -> actual = a -> head -> next;
		struct nodo *aux = a -> actual;

		while (a -> actual -> next != NULL) {
			a -> actual = a -> actual -> next;
			free(aux -> info);
			free(aux);
			aux = a -> actual;
		}
		a -> length = 0;
		free(a -> tail -> info);
		free(a -> tail);
		a -> actual = a -> tail = a -> head;
		a -> head -> next = NULL;
	}
	else if (a -> length == 0) {
		a -> actual = a -> tail = a -> head;
		a -> head -> next = NULL;
	}
}

void insert(lista *a, int i, game *g) {
	struct nodo *aux = (struct nodo *)malloc(sizeof(struct nodo));
	int cont;
	a -> actual = a -> head;

	for (cont = 0; cont < i; cont++) a -> actual = a -> actual -> next; 
	aux -> next = a -> actual -> next;
	a -> actual -> next = aux;
	aux -> info = g;
	(a -> length)++; 
}

void append(lista *a, game *g) {
	while (a -> actual -> next != NULL) a -> actual = a -> actual -> next;
	struct nodo *aux = (struct nodo *)malloc(sizeof(struct nodo));
	aux -> info = g;
	aux -> next = NULL;
	if (a -> length == 0) {
		a -> head -> next = aux;
	}
	a -> actual -> next = aux;
	a -> tail = aux;
	(a -> length)++;
}

void remove_(lista *a, int i) {
	if (i >= length(a)) {
		printf("Indice fuera de rango\n");
		return;
	}

	a -> actual = a -> head;
	int cont;
	for (cont = 0; cont < i; cont++) a -> actual = a -> actual -> next;

	if (a -> actual -> next == a -> tail) {
		free(a -> tail -> info);
		free(a -> tail);
		a -> actual -> next = NULL;
		a -> tail = a-> actual;
	} 
	else {
		struct nodo *aux = (struct nodo *)malloc(sizeof(struct nodo));
		aux -> next = a -> actual -> next;
		a -> actual -> next = a -> actual -> next -> next;
		free(aux -> next -> info);
		free(aux -> next);
		free(aux);
	}
	(a -> length)--;
}

int length(lista *a) {
	return a -> length;
}

game *at(lista *a, int i) {
	if (i >= length(a)) {
		printf("Indice fuera de rango\n");
		return NULL;
	}
	int j;
	a -> actual = a -> head;
	for (j = 0; j < i; j++) a -> actual = a -> actual -> next;
	return a -> actual -> next -> info;
}