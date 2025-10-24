#define length(x) (sizeof(x) / sizeof(x[0]))

#include <stdio.h>

int find_sum(int nums[], int target, int numsSize) {
    for (int i = 0; i < (numsSize - 1); i++) {
        for (int j = i + 1; j < numsSize; j++) {
            printf("arr[%d] = %d, arr[%d] = %d\n", i, nums[i], j, nums[j]);
            if (nums[i] + nums[j] == target) {
                printf("hai so co tong bang %d la: %d va %d\n", target, nums[i], nums[j]);
                return 1;
            }
        }
    }
    return 0;
}

// 2 so trong arr co tong = target
int main() {
    int arr[] = {2, 4, 6};
    int target = 8;
    int len = length(arr);
    int found = find_sum(arr, target, len);
    if (found == 0) {
        printf("khong co cap so nao co tong bang %d\n", target);
    }
}