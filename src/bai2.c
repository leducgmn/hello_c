#include <stdio.h>

int main () {
    int n = 10;
    int i = 0;
    int dem = 0;
    while (dem < n) {
        if (i % 2 == 0) {
            dem += 1;
            printf("so chan %2d; dem %d\n", i, dem);
        }
        i += 2;
    }


}
