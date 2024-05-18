#include <stdio.h>
#include <string.h>
#include <ctype.h>

int anagrama(char *s1, char *s2)
{
    int frequencys1[26] = {0}; // devido à tabela ASCII
    int frequencys2[26] = {0};
    for (int i = 0; s1[i] != '\0'; i++)
    {
        if (isalpha(s1[i]))
            frequencys1[s1[i] - 'A']++;
    }
    for (int k = 0; s2[k] != '\0'; k++)
    {
        if (isalpha(s2[k]))
            frequencys2[s2[k] - 'A']++;
    }
    for (int j = 0; j < 26; j++)
    {
        if (frequencys1[j] != frequencys2[j])
        {
            return 0; // não sao anagramas
        }
    }
    return 1; // são anagramas
}

int main()
{
    int n; // numero de casos
    if (scanf("%d", &n) != 1)
    {
        return 1;
    }
    for (int i = 0; i < n; i++) // ciclo que vai iterar o número de casos
    {
        int num;
        char vilao[102], candidatos[1000][102];
        if (scanf("%d\n", &num) != 1)
        {
            return 1;
        }
        if (fgets(vilao, 101, stdin) == NULL)
        {
            return 1;
        }
        for (int j = 0; j < num; j++)
        {
            if (fgets(candidatos[j], 101, stdin) == NULL)
            {

                return 1;
            }
        }
        int flag = 0;
        for (int p = 0; p < num; p++)
        {
            if (anagrama(vilao, candidatos[p]))
            {
                if (flag != 1)
                {
                    printf("%d", p+1);
                    flag = 1;
                }
                else
                {
                    printf(" %d", p+1);
                }
            }
        }
        if (flag != 1)
        {
            printf("-1\n");
        }
        else
            printf("\n");
    }

    return 0;
}
