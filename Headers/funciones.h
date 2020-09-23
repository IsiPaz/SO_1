#ifndef FUNCIONES_H_
#define FUNCIONES_H_
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "gametda.h"

int isDirectoryEmpty(char *);
void Ordenar_juegos();
int Navegar(int, char *);
int Abrir_txt(char *);
void Explorar(char *);

#endif