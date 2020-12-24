#include <stdio.h>
#include <stdlib.h>

// void lectura_archivo(FILE **archivo){}


int main(){
    // https://es.wikibooks.org/wiki/Programaci%C3%B3n_en_C/Manejo_de_archivos
    // https://w3.ual.es/~abecerra/ID/archivos.pdf

    char buffer[100] = "TEXTO QUE APARECERA EN EL ARCHIVO DE EJEMPLO";
    FILE *archivo = fopen("ejemplo.txt", "w+"); // -> busco el archivo creando un apuntador de tipo FILE al archivo
	if (archivo==NULL) { // verifico si el archivo existe
        fputs ("File error",stderr); 
        exit (1);
    }
    fprintf(archivo, buffer); // escrivo en el archvio
	fclose ( archivo ); // cierro el archivo
    return 0;
}