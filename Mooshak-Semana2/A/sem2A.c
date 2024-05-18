#include <stdio.h>

int main() {
    int jogadas, x = 0, y = 0;
    if ((scanf("%d", &jogadas) == 1)) {
        int jogada;
        for (int i = 0; i < jogadas; i++) {
            if (scanf("%d", &jogada)) {
                int direcao = jogada % 4;
                if (direcao == 0 || direcao == 4) x++; 
                    else if (direcao == 1) y--;
                        else if (direcao == 2) y++;
                            else if (direcao == 3) x--;
            }
        }
    }
    else return 1;
    printf("%d %d\n", x, y);
    return 0;
}   