#include <stdio.h>

//size_t fwrite(const void ptr[restrict .size * .nmemb],size_t size, size_t nmemb, FILE *restrict stream);

int main(int argc, char* argv[]){
    if (argc < 2) {
        printf("wzip: file1 [file2 ...]\n");
        return 1;
    }

    int prev = -1;
    int counter = 1;

    for (int f = 1; f < argc; f++) {
        FILE *fp = fopen(argv[f], "r");
        if (fp == NULL) {
            printf("wzip: cannot open file\n");
            return 1;
        }
        
        int c;
        while ((c = fgetc(fp)) != EOF) {
            if (prev == -1) {
                prev = c;
                counter = 1;
            }
            else if (c == prev) {
                counter++;
            } 
            else {
                fwrite(&counter, sizeof(int), 1, stdout);
                fwrite(&prev, sizeof(char), 1, stdout);
                counter = 1;
                prev = c;
            }
        }

        fclose(fp);
    }
    if (counter > 0) {
        fwrite(&counter, sizeof(int), 1, stdout);
        fwrite(&prev, sizeof(char), 1, stdout);
    }

}