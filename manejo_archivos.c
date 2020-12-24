#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

void error(const char *error){
    perror(error);
    exit(EXIT_FAILURE);
}

void Archivos(char *archivo){
    FILE *file = NULL;
    long ftam;

    file = fopen(archivo, "r");
    if (file){
        fseek(file, 0L, SEEK_END);
        ftam = ftell(file);
        fclose(file);
        printf("%30s (%ld byte)\n", archivo, ftam);
    }else{
        printf("%30s (no found)\n", archivo);
    }
}

int main(void){
    DIR *dir;
    struct dirent *ent;
    dir = opendir(".");

    // FILE *archivo = NULL;
    // archivo = fopen();

    if (dir == NULL){
        error("no se pudo abrir el directorio");
    }

    while ( (ent = readdir(dir)) != NULL ){
        if( (strcmp(ent->d_name, ".")!=0) && (strcmp(ent->d_name, "..")!=0) ){
            Archivos(ent->d_name);
        }
    }
    closedir(dir);
    return EXIT_SUCCESS;
    // return 0;
}