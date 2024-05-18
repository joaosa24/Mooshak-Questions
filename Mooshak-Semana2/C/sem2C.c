#include <stdio.h>

char pedra1 = '@';
char pedra2 ='*';
char papel1 = '|';
char papel2 = '-';
char tesoura1 = 'X';
char tesoura2 = '+';

int main(){
    int n,draws=0,wininz=0,wincmd=0;
    if (scanf("%d",&n) == 1){
      
        for(int i = 0; i<n; i++) {
            char inzel,cmd;
            if(scanf(" %c%c",&inzel,&cmd))
            {
                if(inzel == pedra1){
                    if (cmd == pedra2) draws++;
                    if (cmd == papel2) wincmd++;
                    if (cmd == tesoura2) wininz++;
                }
                else if(inzel == papel1){
                    if (cmd == papel2) draws++;
                    if (cmd == tesoura2) wincmd++;
                    if (cmd == pedra2) wininz++;
                }
                else if (inzel == tesoura1){
                    if (cmd == tesoura2) draws++;
                    if (cmd == pedra2) wincmd++;
                    if (cmd == papel2) wininz++;
                }
            }
        }
        printf("%d %d %d\n",wininz,wincmd,draws);
    }
    return 0;
}

