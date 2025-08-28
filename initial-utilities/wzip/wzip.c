#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    const char *word = argv[1];

    int counter = 0;
    char buffer[1024];

    FILE *mem = fmemopen(buffer, sizeof(buffer), "w");
    if (!mem) {
        perror("fmemopen");
        return 1;
    }

    for(int i = 0; *(word + i) != '\0'; i++){
        if(word[i] == word[i+1]){
            counter++;
        }
        else{
            fwrite(word[i], );
        }
    }
    return 0;
}