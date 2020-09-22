#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include "funciones.c" 

int main(){

    int a = 0;
    int e = 0;
    int opcion;    
    char ruta[300];
    char folder[100];
    char fichero[100];

    printf("\nBienvenido, ingrese el número de la opción que desea seleccionar \n");
    printf("\n1. Crear juegos.");
    printf("\n2. Explorar directorio.\n");
    printf("\n");
    scanf("%d", &opcion);

    // printf("Opción ingresada:%d\n", opcion);
    while (a == 0){
        if (opcion == 1) { //Crear juegos
            a = 1;
            Generator();
        }

        else if (opcion == 2) { //Explorar el directorio con juegos
            a = 1;

        }

        else {
            printf("\nOpción invalida.\n");
        }
    }

    Navegar(1, "Juegos");

    a = 0;
    getcwd(ruta,sizeof(ruta));   //   Juegos/
    while( a == 0 ){	
        printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
        printf("\n   Menu \n");
        printf("\n   Ruta actual -> %s \n",ruta);
        Navegar(2,ruta);
        printf("\n");
        printf("\n   Escriba el nombre del directorio que desea explorar\n");
        printf("\n   Si desea salir escriba 'Exit' \n");
        printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
        printf("\n");
        scanf("%s", folder);

        if (strcmp(folder,"Exit")!=0){

            if (Abrir_carpeta(folder) != 1){
                printf("\n");
                scanf("%s", fichero);

                if (strcmp(fichero,"Back")!=0){
                    Abrir_txt(fichero);
                }
            }
        }

        else{
            a = 1;
        }
    }
    return 0;
}