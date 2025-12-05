#include <stdio.h>

#define length(x) (sizeof(x) / sizeof(x[0]))

int main() {
    int arr[10] = {1, 3, 4, 5, 7, 8, 10, 20, 50, 100};
    int n = 100;
    
    int len = length(arr);
    int j = len / 2;
    int start = 0;
    int end = len;

    for(int i = 0; i < len; i++) {
        if (arr[j] > n) {
            end = j;
        } else if (arr[j] < n) {
            start = j;
        } else {
            break;
        }
        j = (start + end) / 2;
    }
    printf("index = %d\n", j);
}