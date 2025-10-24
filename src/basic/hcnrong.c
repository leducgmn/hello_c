#include <stdio.h>

int main() {
    int n = 5;
    int m = 20;
    for (int i = 0; i < n; i++) {         
        for (int j = 0; j < m; j++) {
            if (i == 0 || i == n - 1 ||j == 0 || j == m - 1) {      
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}