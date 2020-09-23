#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include "funciones.c" 

int main(){

    int a = 0;
    int check = 0;
    int opcion;  
    int em;  
    char ruta[300];
    char accion[100];
    char mov[100];

    printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
    printf("\n   Bienvenido, ingrese el número de la opción que desea seleccionar \n");
    printf("\n   1. Crear juegos.");
    printf("\n   2. Explorar directorio.\n");
    printf("\n");
    printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
    printf("\n");
    scanf("%d", &opcion);

    // printf("Opción ingresada:%d\n", opcion);
    while (a == 0){
        if (opcion == 1) { //Crear juegos
            a = 1;
            Generator();
        }

        else if (opcion == 2) { //Explorar el directorio con juegos
            em = isDirectoryEmpty("Juegos");
            if ( em == 0){  // si no esta vacio 
                check = 1;
                a = 1;
            }

            else{
                //printf("entro\n");
                check = 0;
                a = 1;
            }
            

        }

        else {
            printf("\nOpción invalida.\n");
        }
    }

    if (check == 0){
        Navegar(1, "Juegos");
    }

    else{
        strcpy(mov,"Juegos/");
        chdir(mov);
        
    }
    

    a = 0;
    getcwd(ruta,sizeof(ruta));   //   Juegos/
    while( a == 0 ){	
        printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
        printf("\n   Menu de navegación \n");
        printf("\n   Ruta actual -> %s \n",ruta);
        Navegar(2,ruta);
        printf("\n");
        printf("\n   Escriba el nombre del directorio o archivo que desea explorar\n");
        printf("\n   Si desea salir escriba 'Exit' \n");
        printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
        printf("\n");
        scanf("%s", accion);

        if (strcmp(accion,"Exit")!=0){
            Explorar(accion);
        }

        else{
            a = 1;
        }
    }
    return 0;
}