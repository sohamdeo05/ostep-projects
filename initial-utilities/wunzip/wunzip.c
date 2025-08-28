#include <stdio.h>

//size_t fread(void ptr[restrict .size * .nmemb], size_t size, size_t nmemb, FILE *restrict stream);


int main(int argc, char *argv[]){
    if (argc < 2) {
        printf("wunzip: file1 [file2 ...]\n");
        return 1;
    }

    for (int f = 1; f < argc; f++) {
        FILE *fp = fopen(argv[f], "r");
        if (fp == NULL) {
            printf("wunzip: cannot open file\n");
            return 1;
        }
        
        


    }
    return 0;
}