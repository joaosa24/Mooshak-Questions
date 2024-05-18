#include <stdio.h>

int soldados_visiveis(int anoes[], int k) {
    int visible = 1; 
    int max_anao = anoes[0]; 
    for (int i = 1; i < k; i++) { 
        if (anoes[i] > max_anao) { 
            visible++; 
            max_anao = anoes[i]; 
        }
    }
    return visible;
}

int main() {
    int casos;
    if (scanf("%d", &casos) !=1) return 1;
        else {
        int lista_visivel[casos];
        int anoes;
        for (int i = 0; i < casos; i++) {
            if (scanf("%d", &anoes) !=1) return 1;
            else {
                int soldados[anoes];
                for (int j = 0; j < anoes; j++) {
                    if (scanf("%d", &soldados[j])!=1) return 1;
                    else {
                    lista_visivel[i] = soldados_visiveis(soldados, anoes);
                    }
                }
            }
        }
        for (int k = 0; k < casos; k++) {
            printf("%d\n", lista_visivel[k]);
        }
    }
    return 0;
}