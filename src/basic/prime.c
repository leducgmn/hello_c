#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int is_prime(int n);

// in ra n so nguyen to dau tien 
int main() {
    int n = 10;
    if (is_prime(n)) {
        printf("n = %d la so nguyen to\n", n);
    } else {
        printf("n = %d khong la so nguyen to\n", n);
    }
    count_prime(n);
}

int is_prime(int n) {
    int is_prime = 1;
    if (n < 2) {
        return 0;
    }
    double m = sqrt(n); 
    for (int i = 2; i <= m; i++ ) {
        if (n % i == 0) {
            return 0;
        }
    }
    return n;
}

int count_prime(int n) {
    int count = 0;
    int j = 2; 
    while (count < n) {
        if (is_prime(j)) { 
            count++;
            printf("n so nguyen to dau tien la: %d\n", j);
        }
        j++;
    }
}
