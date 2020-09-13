#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include "funciones.c" 

int main(){

    int a = 0;
    int opcion;    

    printf("\nBienvenido, ingrese el número de la opción que desea seleccionar \n");
    printf("\n1. Crear juegos.");
    printf("\n2. Explorar directorio.\n");
    scanf("%d", &opcion);

    // printf("Opción ingresada:%d\n", opcion);
    while (a == 0){
        if (opcion == 1) { //Crear juegos
            a = 1;
            Generator();
        }

        else if (opcion == 2) { //Explorar el directorio con juegos
            a = 1 ;
        }

        else {
            printf("\nOpción invalida.\n");
        }
    }

    Navegar(1);

}