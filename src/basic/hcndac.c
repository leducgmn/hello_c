#include <stdio.h>

int main() {
    int n = 3;
    int m = 15;
    for (int i = 0; i < n; i++) {         
        for (int j = 0; j < m; j++) {      
            printf("*");
        }
        printf("\n");
    }
    return 0;
}