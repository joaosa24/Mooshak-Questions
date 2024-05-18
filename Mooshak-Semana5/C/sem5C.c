#include <stdio.h>
#include <string.h>

int mais_faltas(int arr[], int size)
{
    int indice_mais_faltas = 0;
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > arr[indice_mais_faltas])
        {
            indice_mais_faltas = i;
        }
    }
    return indice_mais_faltas;
}


int main()
{
    int dias;
    int nomes[40][21], presencas[40] = {0};
    if (scanf("%d", &dias))
    {

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
                    else if (strlen((char *)nomes[k]) == 0)
                    {
                        strcpy((char *)nomes[k], nome);
                        presencas[k]++;
                    }
                }
            }
        }
        int maisfaltas = mais_faltas(presencas, 40);

        printf("%s", (char *)nomes[maisfaltas]);
    }
}