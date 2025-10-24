#include <stdio.h>

int main() {
    int arr[5] = {2, 4, 8, 12, 16};
    for (int i = 0; i < 5; i++) {
        printf("a[%d]=%d\n", i, arr[i]);
    }
    int array_size = sizeof(arr);
    int element_size = sizeof(arr[0]);
    int size = array_size / element_size;
    printf("%d/%d=%d\n", array_size, element_size, size);
    return 0;
}