#include <stdio.h>

int main(int argc, char *argv[]){
    if(argc < 2){
        printf("Usage: wcat <filename>\n");
    }

    const char *mode = "r";
    char buffer[256];
    FILE *fptr = fopen(argv[1], mode);

    if(fptr == NULL){
        printf("File not found.\n");
    }

    while(fgets(buffer, sizeof(buffer), fptr)){
        printf("%s", buffer);
    }
    fclose(fptr);
    printf("\n");
    return 0;
}