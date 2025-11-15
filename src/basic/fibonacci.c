#include <stdio.h>
#include <stdint.h>

int fibonacci_arr(int n) {
    if (n == 1 || n == 2) {
        return 1;
    } 
    uint64_t arr[1000] = {1, 1};
    for (int i = 2; i < n ; i++) {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    return arr[n - 1];
// nhuoc diem la gi
}

int fibonacci_swap(int n) {
    if (n == 1 || n == 2) {
        return 1;
    }
    uint64_t a = 1;
    uint64_t b = 1;
    for (int i = 3; i <= n; i++) {
        b = a + b;
        a = b - a;
    }
    return b;
}

uint64_t fibonacci(int n) {
    if (n == 1 || n == 2) {
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    // 1 1 2 3 5 8 13 21 34 55 89
    // so thu 4 = so thu 3 + so thu 2 = arr[2] + arr[1]
    /* tim chu so fibonacci thu n */
    // yc1: k sdung arr[]
    // yc2: k sdung for
    int n = 1000;
    uint64_t result = fibonacci_arr(n);
    printf("Fibonacci thu %d = %llu\n", n, result);
    /*  */
} 
