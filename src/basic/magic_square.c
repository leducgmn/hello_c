#include <stdio.h>

void print_square(int square[100][100], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%3d ", square[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int n = 5;

    int square[100][100] = {0};
    int row = 0;
    int col = n / 2;
    square[row][col] = 1;

    for (int value = 2; value <= n*n; value++) {
        int new_row = row == 0 ? n-1 : row - 1;
        int new_col = col == n - 1 ? 0 : col + 1;
        if (square[new_row][new_col] != 0) {
            new_row = (row + 1) % n;
            new_col = col;
        }
        row = new_row;
        col = new_col;
        square[row][col] = value;
        print_square(square, n);
    }

    return 0;
}