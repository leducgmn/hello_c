#include <stdio.h>

int main () {
    // dem so chu so cua so n 
    // dem so chu so cua so am 
    // chia so n cho co so (10), dem so lan chia, chia den khi kqua=0 thi dung lai n>0 => n/10 => dem++
    int n = -123456;
    int count = 0;
    if (n == 0) {
        count = 1;
    } else {
        // if (n < 0) {
        //     n= -n;
        // }
        while (n != 0) {
            int d = n % 10;
            n = n / 10;
            count++;
        }        
    }
    printf("so n co %d chu so\n", count);
return 0;
}