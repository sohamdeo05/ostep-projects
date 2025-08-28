#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){

    if(argc == 1){
        printf("wgrep: searchterm [file ...]\n");
        return 1;
    }

    const char *find = argv[1];

    if(argc == 2){
        char *lineptr = NULL;
        size_t buffer = 0;
        while (getline(&lineptr, &buffer, stdin) != -1) {
            if (strstr(lineptr, find) != NULL) {
                printf("%s", lineptr);
            }
        }
        free(lineptr);
        return 0;
    }

    const char *mode = "r";

    for(int i = 2; i < argc; i++){
        FILE *fptr = fopen(argv[i], mode);

        if(fptr == NULL){
            printf("wgrep: cannot open file\n");
            return 1;
        }

        char *lineptr = NULL;
        size_t buffer = 0;

        while(getline(&lineptr, &buffer, fptr) != -1){
            if (strstr(lineptr, find) != NULL) {
                printf("%s", lineptr);
            }
        }
        free(lineptr);

    }
    return 0;
}