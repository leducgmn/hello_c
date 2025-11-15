#include <stdio.h>

int main() {
    int n = 5;
    int spiral[100][100] = {0};
    int d_row[4] = {0, 1, 0, -1};
    int d_col[4] = {1, 0, -1, 0};
    int direction = 0;
    int row = 0, col = 0;

    spiral[row][col] = 1;

    for (int i = 2; i <= n*n; i++) {
        // tìm vị trí điền số tiếp theo
        int new_row = row + d_row[direction];
        int new_col = col + d_col[direction];
        if (spiral[new_row][new_col] != 0 || new_row >= n|| new_col >= n || new_col < 0|| new_row < 0) {
            direction = (direction + 1) % 4;
            new_row = row + d_row[direction];
            new_col = col + d_col[direction];
        }
        row = new_row;
        col = new_col;
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