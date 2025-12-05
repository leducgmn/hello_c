#include <stdio.h>

int main() {
    int n = 5;
    int spiral[100][100] = {0};
    int d_row[4] = {0, 1, 0, -1};
    int d_col[4] = {1, 0, -1, 0};
    int direction = 3; // phai -> xuong -> trai -> len -> phai ... 
    int row = n/2, col = n/2;
    spiral[row][col] = 1;

    int limit[4] = {col, row, col, row }; // neu di theo direction, cac phan tu cua mang thay doi dua vao d_row + d_col
    // col = 2, row = 2 => limit[4] = {2, 2, 2, 2} 
    // direction = 0, d_row = 0, d_col = 1 => limit[4] = {3, 2, 2, 2} 
    // direction = 1, d_row = 1, d_col = 0 => limit[4] = {3, 3, 2, 2}
    // direction = 2, d_row = 0, d_col =-1 => limit[4] = {3, 3, 1, 2}
    // direction = 3, d_row =-1, d-col = 0 => limit[4] = {3, 3, 1, 1}
    
    //khi o hien tai = limit => chuyen huong 
    for (int i = 2; i <=n*n; i++) {
        // tìm vị trí điền số tiếp theo
        if ((direction % 2 == 0 && col == limit[direction]) ||
            (direction % 2 != 0 && row == limit[direction]) ) {
                direction = (direction + 1) % 4;
                limit[direction] += d_row[direction] + d_col[direction];
            }
            row += d_row[direction];
            col += d_col[direction];
        // printf("[%d][%d]=%2d\n", row, col, i);
        spiral[row][col] = i;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%3d ", spiral[i][j]);
        }
        printf("\n");
    }
    return 0;
}