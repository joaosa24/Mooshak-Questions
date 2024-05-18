#include <stdio.h>

int main()
{
    int A, N;
    if (scanf("%d %d", &A, &N))
    {
        int mat[24][5000] = {0};
        int codigo, arrival, departure;
        for (int i = 0; i < N; i++)
        {
            if (scanf("%d %d %d", &codigo, &arrival, &departure))
            {
                for (int j = arrival; j <= departure; j++)
                {
                    mat[j][codigo - 1]++; // incrementa o valor na matriz (hora e codigo do agente (está -1 pois a matriz começa em 0!))
                }
            }
        }
        for (int hour = 0; hour < 24; hour++)
        {
            int presentes[A], quantos = 0;
            for (int k = 0; k < N; k++)
            {
                if (mat[hour][k] > 0)
                {
                    presentes[quantos++] = k + 1; // é adicionado k+1 pois os códigos dos agentes vão de 1 a N mas J começa a 0
                    // após ser adicionado o código, quantos vai ser incrementado e assim o proximo codigo será adicionado à posição seguinte
                }
            }
            if (quantos > 1)
            {
                printf("%d ", hour);
                for (int linha = 0; linha < quantos; linha++)
                {
                    printf("%d ", mat[linha]);
                }
                printf("\n");
            }
        }
        return 0;
    }
}