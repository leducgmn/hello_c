#include <stdio.h>
#include <limits.h>

int main() {
    int arr[] = {0, 100, 600, 600, 1, 1};
    int i = 0;
    int max1 = INT_MIN;
    int max2 = INT_MIN;
    int min1 = INT_MAX;
    int min2 = INT_MAX;
    // i = 2, a[i] = 100, 
    // max1_i = 1, max1 = 600
    // max2_i = 0, max2 = 1
    for (; i < 6; i++) {
        if (arr[i] > max1) {
            max2 = max1;
            max1 = arr[i];
        } else if (arr[i] > max2 && arr[i] != max1) {
            max2 = arr[i];
        }

        if (arr[i] < min1) {
            min2 = min1;
            min1 = arr[i];
        } else if (arr[i] < min2 && arr[i] > min1) {
            min2 = arr[i];
        }
    }
    printf("so lon nhat la %d\n", max1);
    printf("So lon thu nhi la %d\n", max2);
    printf("So nho nhat la %d\n", min1);
    printf("So nho thu nhi la %d\n", min2);


    // for (i = 0; i < 6; i++) {
    //     if (arr[i] != arr[max1_index]) {
    //         if (arr[i] > arr[max2_index]) {
    //             max2_index = i;
    //         }
    //     }
    // }
    // printf("So lon thu nhi la %d, co index la %d\n", arr[max2_index], max2_index);

    // for (i = 0; i < 6; i++) {
    //     if (arr[i] != arr[min1_index]) {
    //         if (arr[i] < arr[min2_index]) {
    //             min2_index = i;
    //         }
    //     }
    // }
    // printf("So nho thu nhi la %d, co index la %d\n", arr[min2_index], min2_index);

    return 0;

}

