#include <stdio.h>

int main(int argc, char *argv[]){
    if(argc < 2){
        // printf("Usage: wcat <filename>\n");
        return 0;
    }

    const char *mode = "r";
    char buffer[256];

    for(int i = 1; i < argc; i++ ){
        FILE *fptr = fopen(argv[i], mode);

        if(fptr == NULL){
            printf("wcat: cannot open file\n");
            return 1; 
        }

        while(fgets(buffer, sizeof(buffer), fptr)){
            printf("%s", buffer);
        }
        fclose(fptr);
    }
    // printf("\n");
    return 0;
}