#include <stdio.h>

int main() {
    int n = 5;
    // int spiral[100][100] = {0};
    int d_row[4] = {0, 1, 0, -1};
    int d_col[4] = {1, 0, -1, 0};
    int direction = 3; // phai -> xuong -> trai -> len -> phai ... 
    int row = 0, col = 0;
    // spiral[row][col] = 1;

    int limit[4] = {col, row, col, row }; // neu di theo direction, cac phan tu cua mang thay doi dua vao d_row + d_col
    for (int i = 2; i <=n; i++) {
        // tìm vị trí điền số tiếp theo
        if ((direction % 2 == 0 && col == limit[direction]) ||
            (direction % 2 != 0 && row == limit[direction]) ) {
                direction = (direction + 1) % 4;
                limit[direction] += d_row[direction] + d_col[direction];
            }
        row += d_row[direction];
        col += d_col[direction];
        // spiral[row][col] = i;
    }
    printf("so %d o vi tri hang: %d, cot: %d\n", n, row, col);
}