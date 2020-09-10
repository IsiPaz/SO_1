#ifndef GAME_H_
#define GAME_H_

/*
TDA Juego:
Miembros:
	nombre: Nombre del juego.
	categs: Arreglo de posibles categorias.
	empresa: Nombre de la empresa autora.
	resumen: Corto resumen del juego.
	n_cant: Contador de canidad de categorias.

Metodos:
	Read_Game: Recibe un puntero a game y un string.
		Dicho string es el nombre del juego o archivo txt.
		La funcion extrae los datos del archivo txt y los guarda en el struct.
		(Se debe pedir memoria con anterioridad)

	Write_Game: Recibe un puntero a game ya existente.
		Escribe los datos del struct en el directorio correspondiente.
		(Se debe liberar la memoria luego)

	Cmp_Game: Recibe dos punteros de game.
		Compara la cantidad de categorias de cada juego.
		Retorno:
		-1 si el primer juego tiene mas.
		0 si es la misma cantidad en ambos.
		1 si el segundo juego tiene mas.
*/

typedef struct Game {
	char nombre[20];
	char categs[5][20];
	char empresa[20];
	char resumen[150];
	int n_cat;
} game;

void Read_Game(game *, char *);
void Write_Game(game *);
int Cmp_Game(game *, game *);

#endif