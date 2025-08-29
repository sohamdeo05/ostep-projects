#include <stdio.h>

//size_t fwrite(const void ptr[restrict .size * .nmemb],size_t size, size_t nmemb, FILE *restrict stream);
//size_t fread(void ptr[restrict .size * .nmemb], size_t size, size_t nmemb, FILE *restrict stream);

int main(int argc, char *argv[]){
    if (argc < 2) {
        printf("wunzip: file1 [file2 ...]\n");
        return 1;
    }

    for (int f = 1; f < argc; f++) {
        FILE *fptr = fopen(argv[f], "r");
        if (fptr == NULL) {
            printf("wunzip: cannot open file\n");
            return 1;
        }
        
        int count;
        char ch;
        while(fread(&count, sizeof(int), 1, fptr) == 1 && fread(&ch, sizeof(char), 1, fptr) == 1) {
            for(int j = 0; j < count; j++) {
                printf("%c", ch);
            }
        }
    }
    return 0;
}