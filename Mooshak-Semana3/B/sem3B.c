#include <stdio.h>
#include <string.h>

char cima = 'C';
char baixo = 'B';
char direita = 'D';
char esquerda= 'E';


int main(){
    int numpad[3][3] = {{7,8,9},{4,5,6},{1,2,3}};
    int col = 1;
    int l = 1;
    int linhas;
    char command[20];
    if(scanf("%d",&linhas)){
    int posf[linhas];
        for(int i=0;i<linhas;i++){
             if(scanf("%s",command)){
            for (int j = 0; j < (int) strlen(command) ; j++)
            {
                if(command[j] == cima && l>0)
                {
                    l--;
                } else if (command[j] == baixo && l<2)
                {
                    l++;
                } else if (command[j] == esquerda && col > 0) {
                    col--;
                } else if (command[j] == direita && col < 2) {
                    col++;
                }
            }
            posf[i]=numpad[l][col];
    }
    }
     for (int k = 0; k < linhas; k++)
    {
        printf("%d",posf[k]);
    }
    printf("\n");

return 0;
}
}