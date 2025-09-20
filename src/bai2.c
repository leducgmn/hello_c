#include <stdio.h>

// dem n so chan dau tien
void demNSoChanDauTien(int n);

int main () {
    int n = 10;
    demNSoChanDauTien(n);
}

void demNSoChanDauTien(int n) {
    int dem = 0;
    int i = 0;

    while (dem < n) {
        if (i % 2 == 0) {
            dem += 1;
            printf("so chan %2d; dem %d\n", i, dem);
        }
        i += 2;
    }
}
