#include <stdio.h>
#include <string.h>

int main() {
    int casos;
    if (scanf("%d", &casos)) {
        int resp[casos];
        for (int k = 0; k < casos; k++) {
            int bloco;
            char notas[1001];
            if (scanf("%d %s", &bloco, notas)) {
                int length = strlen(notas);
                int posicao = -1;
                for (int i = 0; i <= length - bloco; i++) {
                    int freq[26] = {0};
                    int unico = 1;
                    for (int j = i; j < i + bloco; j++) {
                        if (freq[notas[j] - 65] == 1) {
                            unico = 0;
                            break;
                        }
                        freq[notas[j] - 65]++;
                    }
                    if (unico) {
                        posicao = i;
                        break;
                    }
                }
                resp[k] = posicao;
            }
        }
        for (int p = 0; p < casos; p++) {
            printf("%d\n", resp[p]);
        }
    }
    return 0;
}
