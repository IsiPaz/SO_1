#include <stdlib.h>
#include <stdio.h>
#include <string.h>
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
	char temp3[50]; //Fin

	strcpy(temp1, g -> nombre);
	strcat(temp1, ".txt");          //Nombre.txt
	strcpy(temp2, g -> categs[0]);  //Categoria

	strcpy(temp3, temp2); //Fin = Categoria
	strcat(temp3, "\\");  
	strcat(temp3, temp1); //Fin = Categoria\Nombre.txt

	fp = fopen(temp3, "w");
	//Nombre
	fprintf(fp, "%s\n", g -> nombre);
	
	//Categorias
	int i;
	for (i = 0; i < (g -> n_cat); i++) {
		fprintf(fp, "%s", g -> categs[i]);
		if (i != (g -> n_cat) - 1) fprintf(fp, ",");
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
}