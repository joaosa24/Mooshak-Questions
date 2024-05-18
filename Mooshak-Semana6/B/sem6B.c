#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Cozinheiro
{
    char alcunha[30];
    int peso;
    int altura;
};

int comp_pesos(int peso1, int peso2)
{
    int x, y;
    x = abs(peso1 - 90);
    y = abs(peso2 - 90);
    if (x < y)
    {
        return -1;
    }
    else if (x > y)
    {
        return 2;
    }
    else
        return 3;
}

int comp_alturas(int altura1, int altura2)
{
    if (altura1 < altura2)
    {
        return 1;
    }
    else if (altura1 > altura2)
    {
        return 2;
    }
    else
        return 3;
}

int main()
{
    int num_cozinheiros;
    if (scanf("%d", &num_cozinheiros))
    {
        struct Cozinheiro chef[num_cozinheiros]; // definir um array do novo tipo de dados
        for (int i = 0; i < num_cozinheiros; i++) // ciclo para recolher os dados de cada chef
        {
            if(scanf("%s %d %d", chef[i].alcunha, &chef[i].peso, &chef[i].altura) !=1){}
        }

        int trocou = 1;
        while (trocou) // vai ocorrer o ciclo até que trocou seja "0"
        {
            trocou = 0;
            for (int j = 0; j < num_cozinheiros - 1; j++)
            {
                int ideal = j;
                for (int k = j + 1; k < num_cozinheiros; k++)
                {
                    if (comp_pesos(chef[k].peso, chef[ideal].peso) == -1 // se o primeiro peso estiver mais perto de 90
                    ||(comp_pesos(chef[k].peso, chef[ideal].peso) == 3 && comp_alturas(chef[k].altura, chef[ideal].altura) == 2) // se os pesos forem iguais e se a primeira altura for maior
                    ||(comp_pesos(chef[k].peso, chef[ideal].peso) == 3 && comp_alturas(chef[k].altura, chef[ideal].altura) == 3 && strcmp(chef[k].alcunha, chef[ideal].alcunha) < 0)) // se os pesos forem iguais e se as alturas forem iguais, comparamos se a primeira alcunha vem antes da segunda (ordem alfabética)
                    {
                        ideal = k;
                    }
                }
                if (ideal != j) // se houver alteração, ou seja, se houver um melhor candidato que o primeiro, vamos alterar a ordem, ordenando,assim, os chefs.
                {
                    struct Cozinheiro temp = chef[j];
                    chef[j] = chef[ideal];
                    chef[ideal] = temp;
                    trocou=1;
                }
            }
        }
        for (int p = 0; p < num_cozinheiros; p++)
        {
            printf("%s %d %d\n", chef[p].alcunha, chef[p].peso, chef[p].altura);
        }
    }
    return 0;
}
