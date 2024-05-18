#include <stdio.h>


int main(){
    int a1,a2,a3;
    if(scanf("%d %d %d",&a1,&a2,&a3) != 3)
        {
            printf("Um dos soldados tem uma altura impossível!\n");
            return 1;
        }
    if(a1>a2)
        {
            int temp = a1;
            a1 = a2;
            a2 = temp;
        }
    if(a2>a3)
        {
            int temp = a2;
            a2 = a3;
            a3 = temp;
        }
    if(a1>a2)
    {
        int temp=a1;
        a1=a2;
        a2=temp;
    }

    printf("%d %d %d\n",a1,a2,a3);
    
    return 0;
}