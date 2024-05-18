#include <stdio.h>
#include <string.h>

int menor(int arr[], int size)
{
    int menor = arr[0]; // inicialmente, assumimos que o primeiro é o menor
    for (int i = 1; i < size; i++)
    { // começa a iteração do array a partir do segundo elemento
        if (arr[i] < menor)
        {                   // se o elemento atual for menor que o menor até agora
            menor = arr[i]; // atualiza o menor valor
        }
    }
    return menor;
}

int main()
{
    int dias;
    int nomes[40][21], presencas[40] = {0};

    if (scanf("%d", &dias) == 1 && dias > 0)
    {
        // leitura dos nomes
        int i = 0;
        char nome[21];
        while (scanf("%s", nome) == 1 && i < 40) {
            strcpy((char *)nomes[i], nome);
            i++;
        }

        // leitura das presenças diárias
        for (int i = 0; i < dias; i++)
        {
            char nome[21];
            if (scanf("%s", nome))
            {
                for (int k = 0; k < 40; k++)
                {
                    if (strcmp(nome, (char *)nomes[k]) == 0)
                    {
                        presencas[k]++;
                    }
                }
            }
        }

        // encontra o nome com mais faltas
        int maisfaltas = menor(presencas, 40);
        printf("%s", (char *)nomes[maisfaltas]);
    }
    return 0;
}
