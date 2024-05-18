#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int casos, comp;
    char string[100];
    
    if (scanf("%d\n", &casos)) {
        char result[casos];

        for (int i = 0; i < casos; i++) {
            if (fgets(string, 100, stdin)) {
                comp = strlen(string);
                for (int j = 0; j < comp-1; j++) {
                        for (int k = j+1; k < comp-1; k++) {
                            if (string[j] == string[k]) 
                            {
                                result[i] = string[j];
                            }
                        }
                    }
                }
            }

        for (int k = 0; k < casos; k++) {
            printf("%c", result[k]);
        }
        printf("\n");
    }
}
