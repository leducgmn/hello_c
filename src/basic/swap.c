#include <stdio.h>

int swap(int *a, int *b) {
    // 1. cho a, b. dao gtri cua 2 bien
    // coc xanh = nuoc xanh
    // coc do = nuoc do
    // goi 1 coc trang = k co nuoc
    // coc trang = nuoc xanh
    // coc xanh = nuoc do
    // coc do = nuoc xanh
    // int a = 1;
    // int b = 2;
    // int c = 0;
    // printf("a=%d; b=%d\n", a, b);
    // c = a;
    // a = b;
    // b = c;

    // a = a + b;
    // b = a - b;
    // a = a - b;

    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
    // printf("a=%d; b=%d\n", a, b);
}

int main() {
    // 2. cho a, b , c. sap xep a, b, c theo thu tu tang dan sao cho su dung toi da 1 bien phu
    int a = 0;
    int b = -1;
    int c = 1;
    printf("a=%d, b=%d, c=%d\n", a, b, c);

    int d = 0;
    if (a > b) {
        swap(&a, &b);
    }
    if (a > c) {
        swap(&a, &c);
    }
    if ( b > c) {
        swap(&b, &c);
    }
    printf("a=%d, b=%d, c=%d\n", a, b, c);

}