#include <stdio.h>

int main () {
    // dem so trong he co so 2
    int n = 20;
    int count = 0;
    if (n == 0) {
        count = 1;
    } else { 
        if (n < 0) {
            n = -n;
        }
        while (n > 0) {
            n = n / 2;
            count++;
        }
        printf("so n co %d chu so trong he co so 2\n", count);
    }
    return 0;
}