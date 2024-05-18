#include <stdio.h>

int elem(int x, int v[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (x == v[i])
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    int n;
    if (scanf("%d", &n))
    {
        for (int i = 0; i < n; i++)
        {
            int k;
            int current;
            if (scanf("%d %d", &k, &current))
            {
                printf("%d", current);
                int cabines[k], used[k];
                used[0] = current;
                for (int j = 0; j < k; j++)
                {
                    int new;
                    if (scanf("%d", &new))
                    {
                        cabines[j] = new;
                    }
                }
                for (int p = 0; p < k; p++)
                {
                    current = cabines[current - 1];
                    if (current == 0)
                    {
                        printf("\n");
                        break;
                    }

                    else if (elem(current, used, p))
                    {
                        printf(" CICLO INFERNAL");
                        printf("\n");
                        break;
                    }
                    else
                    {
                        printf(" %d", current);
                        used[p + 1] = current;
                    }
                }
            }
        }
        return 0;
    }
}