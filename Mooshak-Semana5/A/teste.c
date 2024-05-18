#include <stdio.h>
#include <string.h>

void imp(int *nums, int tamanho)
{
    int i;

    for (i = 0; i < tamanho; i++)
    {
        printf("%d", nums[i]);
        if (i < tamanho - 1)
        {
            printf(" ");
        }
    }
    printf("\n");
}

void semerro(char *string)
{
    int l = strlen(string);
    printf("%.*s", l - 1, string); // faz com que a funcao imprma ate o comprimento da string-1 de fomra a imprimir o "CICLO INFERNAL" , sem erros
}

int main()
{

    int casos;
    int guincheinicial;
    int i, j;
    int numerodeguinches;
    int visitado[100], prox[100];

    int resultado[100][100], tamresultado[100];

    if (scanf("%d", &casos))
    {

        for (i = 0; i < casos; i++)
        {

            if (scanf("%d", &numerodeguinches))
            {
                if (scanf("%d", &guincheinicial))
                {

                    for (j = 0; j < numerodeguinches; j++)
                    {

                        if (scanf("%d", &prox[j]))
                        {
                        } // guarda os valores na array "prox"
                    }
                }

                memset(visitado, 0, sizeof visitado); // incicializa o vetor "visitado" com zeros. ponteiro para o vetor , valor que sera atribuido a cada posicao (zeros, numa parte inicial)
                // basicamente inicia um array completo com x valor neste caso o 0. devem ser dados o ponteiro que indica pra que array nos estamos a dirigir o valor que queremos e o tamanho em bytes ( atraves da sizeof()) do array
                visitado[guincheinicial - 1] = 1; // define o valor 1 para o elemento da matriz "visitado" correspondente a posiçao (guincheinicial - 1)

                tamresultado[i] = 0; // inicia com zero, tamanho inicial para i = 0   , 0

                resultado[i][tamresultado[i]++] = guincheinicial; // armazena os blocosque foram visitados

                // loop while que verifica se o elemento prox[guincheinicial - 1] e diferente de zero e se o elemento visitado[prox[guincheinicial - 1] - 1] e falso. caso a condiçao for verdadeira o loop ira continuar
                while (prox[guincheinicial - 1] != 0 && !visitado[prox[guincheinicial - 1] - 1])
                {
                    // caso o proximo guinche ainda nao foi visitado entaao o guincheinicial toma o valor do proximo guinche. e o guinche atual e adicionado ao array "resultados" e a posiçao correspondente a "visitado" e definida como visitada (visitado[guincheinicial - 1] = 1)
                    guincheinicial = prox[guincheinicial - 1];        // guinche toma o valor do proximo
                    resultado[i][tamresultado[i]++] = guincheinicial; // valor do guinche armazenado na array
                    visitado[guincheinicial - 1] = 1;                 // guinche e dado como visitado
                }

                if (prox[guincheinicial - 1] != 0 && visitado[prox[guincheinicial - 1] - 1])
                {
                    resultado[i][tamresultado[i]++] = -1;
                }
            }
        }
        for (i = 0; i < casos; i++)
        {
            j = 0;
            while (j < tamresultado[i])
            {
                if (resultado[i][j] == -1)
                {
                    char str[] = "CICLO INFERNAL ";
                    semerro(str);
                }
                else
                {
                    printf("%d", resultado[i][j]);
                    if (j < tamresultado[i] - 1)
                    {
                        printf(" ");
                    }
                }
                j++;
            }
            putchar('\n');
        }

        putchar('\n');
    }
}
