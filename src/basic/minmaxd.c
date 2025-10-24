#include <stdio.h>

int find_min_max_digit(int n, int *min, int *max, int *countmin, int *countmax);

// Tìm chữ số lớn nhất của số nguyên dương n
// Tìm chữ số nhỏ nhất của số nguyên dương n
// dem so lan xuat hien cua min, max
int main () {
    // input
    int n = 112300456;
    
    // solution
    int max = 0;
    int min = 9;
    int countmax = 0;
    int countmin = 0;
    find_min_max_digit(n, &min, &max, &countmin, &countmax);
    printf("chu so lon nhat %d, xuat hien %d lan\n", max, countmax);
    printf("chu so nho nhat %d, xuat hien %d lan\n", min, countmin);
    // printf("so n co %d chu so\n", count);
   
   
}

int find_min_max_digit(int n, int *min, int *max, int *countmin, int *countmax) {
    int count = 0;
    if (n == 0) {
        count = 1;
        *min = 0;
        *max = 0;
        *countmin = 1;
        *countmax = 1;
    } else {
        // if (n < 0) {
        //     n = -n;
        // }
        while (n > 0) {
            int d = n % 10;
             
            if (d > *max) {
                *max = d;
                *countmax = 1;
            } else if (d == *max) {
                (*countmax)++;
            }
            
            if (d < min) {
                *min = d;
                *countmin = 1;
            } else if (d == min) {
                (*countmin)++;
            }
            n = n / 10;
        }           
    }
    printf("> chu so lon nhat %d, xuat hien %d lan\n", *max, *countmax);
    printf("> chu so nho nhat %d, xuat hien %d lan\n", *min, *countmin);
}