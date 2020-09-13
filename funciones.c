#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
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
                char temp1[25]; //Nombre
	            char temp2[100] = "Juegos/"; //Fin
                FILE *fp;
                char buff1[100];
                char buff[160];
                int a,e; //contadores
                int f = 0; //flag

                strcpy(temp1, entry->d_name);     //Nombre.txt
                strcat(temp2,temp1);              //Peliculas/Nombre.txt

                fp = fopen(temp2, "r");           //Abro cada pelicula

                //Nombre
	            fscanf(fp, "%s\n", buff1);

                //Categorias
                char c = fgetc(fp);
                buff[0] = '\n';
                //g -> n_cat = 0;
                int i = 0;

                // BENJA SI VES ESTO, LO ESTARE ARREGLANDO <3 
                while (c != '\n') {   // el buff me anota letra por letra y no cadenas de string, ademas tiene un problema con el \0 al inicio de cada cadena
                    if (c != ',') {
                        if (c != ' ') {
                            buff[i] = c;
                            printf("buff[i]: %s\n", &buff[i]);
                            i++;
                        }
                    }
                    else {
                        buff[i] = '\0';
                        i = 0;
                        //strcpy(g -> categs[g -> n_cat], buff);
                        //(g -> n_cat)++;
                        buff[0] = '\0';   // -> esto me lo reseteaaa asique arreglar
                    }
                    c = fgetc(fp);
                    if (c == '\n') {
                        buff[i] = '\0';
                        //strcpy(g -> categs[g -> n_cat], buff);
                        //(g -> n_cat)++;
                    }
                }

                while(contador_cat<5){
                    if (sizeof(categorias)==0){ // si no hay ninguna categoria en el arreglo de categorias
                        for (a = 0; a < sizeof(buff); a++){  //si es que buff guarda todas las categorias?? preguntar a benja como funciona su lector de categorias
                            categorias[contador_cat] = buff[a];
                            printf("categoria añadida%s\n",&categorias[contador_cat]);
                            contador_cat++;  
                                     
                        }
                    }
                    
                    else {  // aqui tendria que revisar si la categoria del arreglo buff se encuentra ya en el arreglo de categorias
                        for (a = 0; a < sizeof(buff); a++){  //si es que buff guarda todas las categorias?? preguntar a benja como funciona su lector de categorias
                            if (contador_cat<5){  // esto me comprueba que aun no estan llenas las 5 categorias
                                for (e = 0; e<contador_cat-1;e++){
                                    if(buff[a] == categorias[e]){
                                        flag = 1;  //ya esta en categorias
                                        break;
                                    }
                                }

                                if (f == 0){ //no esta, entonces lo agregare a categorias
                                    categorias[contador_cat] = buff[a];
                                    printf("categoria añadida%s\n",&categorias[contador_cat]);
                                    contador_cat++;
                                }
                            }

                            else{
                                break;
                            }
                                          
                        }
                    }
                }

                //printf("File %d: %s\n", files, entry->d_name);

                fclose(fp);  //deberia preguntar que pasa con el puntero de lectura de cada archivo.
            }

        }
        int u;
        for (u = 0; u<5; u++){ // aqui recorro el arreglo de categorias y creo las carpetas de cada una, por ahora estoy imprimiendo no mas para ver si funciona
            printf("categorias:%s\n", &categorias[u]);
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
