#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "gametda.c"



int Navegar(int flag){
    DIR *folder;
    //La variable de estructura dirent es un puntero que contiene 
    //información sobre una entrada específica leída desde un directorio, 
    //referenciada por el puntero DIR usado en la función readdir (). 
    //Esta función se llama repetidamente hasta que se devuelve NULL, 
    //lo que indica que no hay más entradas disponibles en el directorio.
    struct dirent *entry;  
    int files = 0;
    folder = opendir("Juegos");

    if(folder == NULL) {
        printf("No es posible abrir el directorio");
        return(1);
    }

    if ( flag == 1){
        printf("Creando carpetas de categorias\n");
        char categorias[5][20];
        int contador_cat = 0;



        while((entry = readdir(folder))) {
            if (!strcmp(entry->d_name, ".") || !strcmp(entry->d_name, "..")){
                continue;	
            }
            else {
                FILE *fp;
                char temp1[25];                   //Nombre
	            char temp2[100] = "Juegos/";      //Fin

                char buff1[100];                  //nombre de cada juego
                char buff[160];                   //string del txt con las categorias 

                char *cat_juegox[5];              //categorias de cada juego revisado

                int a,e; //contadores
                int f = 0; //flag

                strcpy(temp1, entry->d_name);     //Nombre.txt
                strcat(temp2,temp1);              //Peliculas/Nombre.txt

                fp = fopen(temp2, "r");           //Abro cada pelicula

                //Nombre
	            fscanf(fp, "%s\n", buff1);
                //printf( "nombre: %s\n", buff1 );           //borrar

                if( fgets (buff, 160, fp)!=NULL ) {
                    //printf("categorias: %s\n", buff);      //borrar
                    
                    int cont = 0;
                    char delimitador[] = ", \n";
                    char *token = strtok(buff, delimitador);
                    if(token != NULL){
                        int x = 0;
                        while(token != NULL){
                            // Sólo en la primera pasamos la cadena; en las siguientes pasamos NULL
                            //printf("Token: %s\n", token);
                            cat_juegox[x++] = token;
                            cont = cont + 1;
                            token = strtok(NULL, delimitador);

                        }
                    }

/*                     int a;
                    printf("contador:%d\n", cont);
                    for (a = 0; a < cont; ++a){ 
                        printf("%s\n", cat_juegox[a]);
                    } */

                    if(contador_cat <5){
                    
                        if (sizeof(categorias) != 0){  // aqui tendria que revisar si la categoria del arreglo buff se encuentra ya en el arreglo de categorias
                            for (a = 0; a < cont; a++){  
                                if (contador_cat<5){  // esto me comprueba que aun no estan llenas las 5 categorias
                                    for (e = 0; e<contador_cat; e++){
                                        if(strcmp(cat_juegox[a], categorias[e]) == 0 ){  
                                            f = 1;  //ya esta en categorias
                                            break;
                                        }
                                    }

                                    if (f == 0){ //no esta, entonces lo agregare a categorias
                                        strcpy(categorias[contador_cat],cat_juegox[a]);
                                        printf("categoria añadida %s\n", categorias[contador_cat]);
                                        
                                        contador_cat++;
                                    }
                                }

                                else{
                                    break;
                                }
                                            
                            }
                        }

                        else if (sizeof(categorias) == 0){       // si no hay ninguna categoria en el arreglo de categorias
                            for (a = 0; a < cont; a++){  
                                strcpy(categorias[contador_cat],cat_juegox[a]);
                                printf("categoria añadida: %s\n",categorias[contador_cat]);
                                contador_cat++;  
                                        
                            }
                        }
                    }

                }

                fclose(fp); 
            }

        }
        int u;
        char ruta[150];
        for (u = 0; u<5; u++){           // Creo cada carpeta
            //printf("categorias:%s\n", categorias[u]);
            strcpy(ruta,"Juegos/");
            strcat(ruta,categorias[u]);
            mkdir(ruta,0777);
        }
    }
    
    else if ( flag == 2){
        while((entry = readdir(folder))) {
            files++;
            if (!strcmp(entry->d_name, ".") || !strcmp(entry->d_name, "..")){
                continue;	
            }
            else {
                printf("File %d: %s\n", files, entry->d_name);
            }

        }
    }

    closedir(folder);

    return(0);
}
