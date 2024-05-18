#include <stdio.h>

int main()
{
    int A, N;
    if (scanf("%d %d", &A, &N))
    {
        int mat[24][5000] = {0}; // matriz no formato HORASxAGENTES que vai ser inicializada toda a 0, para quando um agente estiver presente, ter o seu valor incrementado
        int codigo, arrival, departure;
        for (int i = 0; i < N; i++) // loop que vai analisar cada agente
        {
            if (scanf("%d %d %d", &codigo, &arrival, &departure)) // atribuimos o valor ao codigo do agente e à hora de chegada e saída
            {
                for (int j = arrival; j <= departure; j++) // fazemos um loop que vai iterar da hora de chegada até à hora de saída de cada agente
                {
                    mat[j][codigo - 1]++; // adiciona à matriz 1 unidade na linha correspondente à hora (j) e à coluna correspondente ao código (está -1 pois começa em 0)
                }
            }
        }
        for (int hour = 0; hour < 24; hour++) // fase de análise e impressão dos resultados
        {
            int presentes[A], quantos = 0;          // usamos um array que vai guardar o código de cada agente e uma flag para servir como "trigger"
            for (int agent = 0; agent < A; agent++) // tinha colocado N mas para dar certo tem de ser A pois é o número máximo de agentes!
            {
                if (mat[hour][agent] > 0) // se houver um valor diferente de 0, o código do agente será adicionado ao nosso array que guarda os agentes
                {
                    presentes[quantos] = agent + 1; // é adicionado agent+1 pois os códigos dos agentes vão de 1 a N mas J começa a 0
                    quantos++;                      // após ser adicionado o código, quantos vai ser incrementado e assim o proximo codigo será adicionado à posição seguinte
                }
            }
            if (quantos > 1) // se o trigger for maior que 1, ou seja há mais do que um agente presente numa hora, vamos passar para a fase de imprimir os resultados daquela hora
            {
                printf("%d", hour);                          // imprime as horas
                for (int index = 0; index < quantos; index++) // loop para imprimir os codigos dos agentes
                {
                    printf(" %d", presentes[index]); // damos print aos codigos que estavam presentes naquela hora
                }
                printf("\n"); // usamos para os próximos resultados estarem na próxima linha
            }
        }
        return 0;
    }
}