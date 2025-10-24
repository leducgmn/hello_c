#include <stdio.h>
#include <math.h>
#include <stdbool.h>

// Hãy kiểm tra các chữ số của số nguyên dương n có tăng dần/giảm dần từ trái sang phải hay không

int tang(int n);
int giam(int n);

int main() {
    int n = 433221;
    if (n < 10) {
        printf("n = %d la so khong tang khong giam\n", n);
    } else if (tang(n)) {
        printf("n = %d la so tang dan\n", n);
    } else if (giam(n)) {
        printf("n = %d la so giam dan\n", n);
    } 
    
}

int tang(int n) {
    while(n >= 10) {
        int m = n % 10;
        int j = ((n / 10) % 10);
        if (j > m) {
            return 0;
        }
        n /= 10;
        }
        return 1;
}

int giam(int n) {
    while (n >= 10) {
        int k = n  % 10;
        int j = ((n / 10) % 10);
        if (j < k) {
            return 0;
        }
        n /= 10;
    }
    return 1;
}