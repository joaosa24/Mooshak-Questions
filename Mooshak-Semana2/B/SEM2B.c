#include <stdio.h>

int main(){
    int ainicial,andares,comandos,mov;

    
    if((scanf("%d",&ainicial)+scanf("%d",&andares)+scanf("%d",&comandos)!= 3)) return 1;
        else{
            for (int i = 0; i < comandos; i++){
                if(scanf("%d",&mov)!= 1) return 1;
                    else{
                        ainicial = ainicial + mov;
                            if(ainicial>andares) ainicial = andares;
                                else
                                    if(ainicial<0) ainicial = 0;
                    }
            }
            printf("%d\n",ainicial);
        }
        return 0;
}