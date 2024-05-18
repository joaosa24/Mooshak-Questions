#include <stdio.h>

int main() {
    int biscoitos[5];
    int maior_biscoito = 0;
    int soldado_mais_biscoitos = 1;
    int check;
    

    for (int i = 0; i < 5; i++) {
        check = scanf("%d", &biscoitos[i]);
        if (check <= 0){
            printf("Um dos Soldados tem um número incorreto de biscoitos\n");
            return 0;
        }
        if (biscoitos[i] > maior_biscoito) { 
            maior_biscoito = biscoitos[i];
            soldado_mais_biscoitos = i + 1; 
        }
    }
    
    printf("%d\n", soldado_mais_biscoitos);
    
    return 0;
}
