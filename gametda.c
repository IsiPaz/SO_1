#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "gametda.h"

void Read_Game(game *g, char *nom) {
	FILE *fp;
	char buff[160];

	fp = fopen(nom, "r");
	
	//Nombre
	fscanf(fp, "%s\n", buff);
	strcpy(g -> nombre, buff);

	//Categorias
	char c = fgetc(fp);
	buff[0] = '\n';
	g -> n_cat = 0;
	int i = 0;
	while (c != '\n') {
		if (c != ',') {
			if (c != ' ') {
				buff[i] = c;
				i++;
			}
		}
		else {
			buff[i] = '\0';
			i = 0;
			strcpy(g -> categs[g -> n_cat], buff);
			(g -> n_cat)++;
			buff[0] = '\0';
		}
		c = fgetc(fp);
		if (c == '\n') {
			buff[i] = '\0';
			strcpy(g -> categs[g -> n_cat], buff);
			(g -> n_cat)++;
		}
	}

	//Empresa
	fscanf(fp, "%s\n", buff);
	strcpy(g -> empresa, buff);

	//Resumen
	c = fgetc(fp);
	buff[0] = '\0';
	int flag = 1;
	i = 0;
	while (flag) {
		if (c != '\n') {
			buff[i] = c;
			i++;
		}
		else {
			buff[i] = '\0';
			strcpy(g -> resumen, buff);
			flag = 0;
		}
		c = fgetc(fp);
	}

	fclose(fp);
}

void Write_Game(game *g) {
	FILE *fp;
	char temp1[25]; //Nombre
	char temp2[25]; //Categoria
	char temp3[100] = "Juegos/"; //Fin

	strcpy(temp1, g -> nombre);
	strcat(temp1, ".txt");          //Nombre.txt
	strcpy(temp2, g -> categs[0]);  //Categoria

	strcat(temp3, temp2); //Fin = Juegos/Categoria
	strcat(temp3, "/");  
	strcat(temp3, temp1); //Fin = Juegos/Categoria/Nombre.txt

	fp = fopen(temp3, "w");
	//Nombre
	fprintf(fp, "%s\n", g -> nombre);
	
	//Categorias
	int i;
	for (i = 0; i < (g -> n_cat); i++) {
		fprintf(fp, "%s", g -> categs[i]);
		if (i != (g -> n_cat) - 1) fprintf(fp, ", ");
	}
	fprintf(fp, "\n");

	//Empresa
	fprintf(fp, "%s\n", g -> empresa);

	//Resumen
	fprintf(fp, "%s\n", g -> resumen);

	fclose(fp);
}

int Cmp_Game(game *g1, game *g2) {
	if (g1 -> n_cat == g2 -> n_cat) return 0;
	if (g1 -> n_cat > g2 -> n_cat) return -1;
	if (g1 -> n_cat < g2 -> n_cat) return 1;
	return 2;
}

void Generator() {
	int i, j, cats, select, cant = 20;
	cant += (rand() % 10);  //[20, 30] cantidad de juegos
	char categs[5][20] = {"Terror", "Multiplayer", "Plataforma", "RPG", "MOBA"};
	//{0 = Terror, 1 = Multiplayer, 2 = Plataforma, 3 = RPG, 4 = MOBA}
	FILE *fp;

	char nom[20];
	char emp[20];
	char res[150];
	char buff[4];
	char route[100];

	int flag = 0; //Flag juegos con mas de una categoria
	int fs[5] = {0, 0, 0, 0, 0}; //Flags juegos en categoria
	
	for (i = 0; i < cant; i++) {
		strcpy(nom, "Juego_");
		strcpy(emp, "Empresa_");
		strcpy(res, "Descripcion_");
		strcpy(route, "Juegos/");
		//itoa(i, buff, 10);
		sprintf(buff, "%i", i);

		strcat(nom, buff);  //Nombre del juego
		strcat(emp, buff);  //Empresa autora
		strcat(res, buff);  //Resumen

		strcat(route, nom);
		strcat(route, ".txt"); //Juegos/Nombre.txt

		fp = fopen(route, "w");

		fprintf(fp, "%s\n", nom); //Escritura del nombre

		cats = (rand() % 5) + 1;
		if (cats >= 2) flag++;

		//Escritura de categorias
		select = rand() % 5;
		for (j = 0; j < (cats - 1); j++) {
			fprintf(fp, "%s", categs[select]);
			fs[select]++;
			select = (select + 1) % 5;
			fprintf(fp, ", ");
		}
		fprintf(fp, "%s\n", categs[select]);

		fprintf(fp, "%s\n", emp); //Escritura de la empresa

		fprintf(fp, "%s\n", res); //Escritura del resumen

		fclose(fp);

		if (i == (cant - 1)) if (flag < 5 || fs[0] < 2 || fs[1] < 2 || fs[2] < 2 || fs[3] < 2 || fs[4] < 2) cant++;
	}
}



//recorrer directorios -> crear funcion
//agregar struct de juego en lista con todos los juegos existententes con el tda read
//