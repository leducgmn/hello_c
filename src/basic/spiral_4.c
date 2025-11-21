#include <stdio.h>



int main() {
    // input
    int target_row = 1;
    int target_col = -1;

    // process
    int d_row[4] = {0, 1, 0, -1};
    int d_col[4] = {1, 0, -1, 0};
    int direction = 3; // phai -> xuong -> trai -> len -> phai ... 
    int row = 0;
    int col = 0;
    
    int limit[4] = {col, row, col, row }; // neu di theo direction, cac phan tu cua mang thay doi dua vao d_row + d_col
    int i;
    for (i = 2;; i++) {
        // tìm vị trí điền số tiếp theo
        if ((direction % 2 == 0 ? col : row) == limit[direction]) {
            direction = (direction + 1) % 4;
            limit[direction] += d_row[direction] + d_col[direction];
        }
        row += d_row[direction];
        col += d_col[direction];
        if (row == target_row && col == target_col) {
            break;
        }
    }
    printf("so o vi tri hang: %d, cot: %d la: %d\n", target_row, target_col, i);
}
