#include <stdio.h>
#include <string.h>

int main() {
    char ord[9];
    char msg[1001];
    int tamanho_bloco,nblocks, i, j, k;
    int tam_msg;
    
    if (scanf("%s", ord)!= 1) printf("Error invalid input\n");
    if (scanf("%s", msg)!= 1) printf("Error invalid input\n");
    
    if (strlen(ord) > 9 || strlen(msg) > 1001) {
    printf("Error input strings are too long\n");
    return 1;
    }

    tam_msg = strlen(msg);   
    tamanho_bloco = strlen(ord);
    nblocks = (strlen(msg) / tamanho_bloco);
    
    for (i = 1; i ; i++) {
        for (j = 0; j < nblocks+1; j++) {
            k = (j * tamanho_bloco) + ord[i] - '1';
           if(k < tam_msg) { 
           printf("%c", msg[k]);
        }
    }
}
    printf("\n");
    
    return 0;
}