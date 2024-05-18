#include <stdio.h>
#include <string.h>

int main(){
    char pos[9];
    char input[1001];
    int j=0;

    if (scanf("%s", pos)!=1) return 1;
    if (scanf("%s", input)!=1) return 1;
    int input_size = strlen(input);
    int pos_size = strlen(pos);
    int blocos=((input_size)/(pos_size));
        for(int i=0; i<pos_size; i++)
        {
            for(int k=0;k<blocos+1;k++)
            {
                j=(k*pos_size) + pos[i] - '1';
                if(j<input_size) printf("%c",input[j]);
            }
        }
    printf("\n");
}