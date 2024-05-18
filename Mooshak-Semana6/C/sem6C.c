#include <stdio.h>
#include <stdlib.h>

void ordenar_por_preco(int n, int numpedido[], char dificuldade[], int custo[])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (custo[i] < custo[j])
            { // se o segundo for mais caro , vamos coloca-lo em primeiro lugar
                int temp = numpedido[i];
                numpedido[i] = numpedido[j];
                numpedido[j] = temp; // trocamos o número dos pedidos

                char diftemp = dificuldade[i];
                dificuldade[i] = dificuldade[j];
                dificuldade[j] = diftemp; // trocamos a dificuldade

                temp = custo[i];
                custo[i] = custo[j];
                custo[j] = temp; // trocamos o custo
            }                    // no final, os pedidos devem estar trocados
        }
    }
}

void ordenar_por_dificuldade(int n, int numpedido[], char dificuldade[], int custo[])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        { // se os preços forem iguais, vamos ordenar do mais facil para o mais dificil
            if (custo[i] == custo[j] && dificuldade[i] > dificuldade[j])
            { // o processo é análogo ao da função anterior
                int temp = numpedido[i];
                numpedido[i] = numpedido[j];
                numpedido[j] = temp;

                char diftemp = dificuldade[i];
                dificuldade[i] = dificuldade[j];
                dificuldade[j] = diftemp;

                temp = custo[i];
                custo[i] = custo[j];
                custo[j] = temp;
            }
        }
    }
}

void ordenar_por_numero(int n, int numpedido[], char dificuldade[], int custo[])
{
    for (int i = 0; i < n; i++)
    { 
        for (int j = i + 1; j < n; j++)
        { // se for possivel (custos iguais e dificuldades iguais) vamos ordenar por ordem de pedidos
            if (custo[i] == custo[j] && dificuldade[i] == dificuldade[j] && numpedido[i] > numpedido[j])
            {
                char diftemp = numpedido[i];
                numpedido[i] = numpedido[j];
                numpedido[j] = diftemp;

                diftemp = dificuldade[i];
                dificuldade[i] = dificuldade[j];
                dificuldade[j] = diftemp;

                diftemp = custo[i];
                custo[i] = custo[j];
                custo[j] = diftemp;
            }
        }
    }
}

int main()
{
    int n;
    if (scanf("%d", &n))
    {
    }
    int numpedido[n];
    char dificuldade[n];
    int custo[n];

    for (int i = 0; i < n; i++)
    { // recolha dos dados
        if (scanf("%d %c %d", &numpedido[i], &dificuldade[i], &custo[i]))
        {
        }
    }

    ordenar_por_preco(n, numpedido, dificuldade, custo);       // primeiro critério é por preços
    ordenar_por_dificuldade(n, numpedido, dificuldade, custo); // segundo critério é por ordem de dificuldade
    ordenar_por_numero(n, numpedido, dificuldade, custo);      // por fim, cumprindo os dois acima, por ordem de pedidos

    for (int j = 0; j < n; j++)
    { // ciclo para imprimir os resultados
        printf("%d %c %d\n", numpedido[j], dificuldade[j], custo[j]);
    }

    return 0;
}
