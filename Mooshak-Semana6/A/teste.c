#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int e_anagrama(char *s1, char *s2)
{
    int freq[26] = {0};
    int comp1 = strlen(s1);
    int comp2 = strlen(s2);

    if (comp1 != comp2)
        return 0;

    for (int i = 0; i < comp1; i++)
    {
        freq[s1[i] - 'A']++;
        freq[s2[i] - 'A']--;
    }
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] != 0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int n;
    int n_candidatos;
    char vilao[101];
    char disfarce[1000][101];

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d\n", &n_candidatos);
        scanf("%s",vilao);
        int encontrado = 0;

        for (int j = 0; j < n_candidatos; j++)
        {
            scanf("%s", disfarce[j]);
            if (e_anagrama(vilao, disfarce[j]))
            {
                printf("%d ", j + 1);
                encontrado = 1;
            }
        }
        if (encontrado == 0)
            printf("-1\n");
    }
    return 0;
}
