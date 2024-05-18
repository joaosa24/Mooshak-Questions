#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int isvogal(char c){
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y'){
        return 1;
    }
    if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'Y'){
        return 1;
    }
    if (c == ' '){
        return 2;
    }
    if (c == '\n'){
        return 3;
    }
    
    return 0;
}



int main(){
    int casos;
    char string[100];
    int counter = 0;

    if(scanf("%d\n", &casos)){
    
    int res[casos];

    for(int b = 0; b < casos; b++){
        counter = 0;
        if (fgets(string, 100, stdin) == NULL) {
          printf("Erro na leitura da string.\n");
            return 1;
            }
        for(int i = 0; i < (int)strlen(string); i++){
            if(string[i] == '\n'){
                break;
            }
            if(((isvogal(string[i]) == 1) && (isvogal(string[i+1]) == 1) && (string[i+1] != '\0')) || ((isvogal(string[i]) == 0) && (isvogal(string[i+1]) == 0)&& (string[i+1] != '\0'))){
                while(string[i] != ' '){
                    i++;
                    if(string[i] == '\0'){
                        break;
                    }
                }
            }
            else if (string[i + 1] == ' ' || string[i + 1] == '\n'){
                counter++;
            }
        }
        res[b] = counter;
    }
    for(int i = 0; i < casos; i++){
        printf("%d\n", res[i]);
}
    return 0;
}
}

