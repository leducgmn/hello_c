#include <stdio.h>
#include <stdbool.h>

int check_sq_row(int n, int square[100][100]) {
    int sum = 0;
    for (int row = 0; row < n; row++) {
        int row_sum = 0;
        for (int col = 0; col < n; col++) {
            row_sum += square[row][col];
        }
        if (row == 0) {
            sum = row_sum;
        } else if (sum != row_sum) {
            printf("row Magic Square k hop le\n");
            return 0;
        }
    }
    return sum;
}

int check_sq_col(int n, int square[100][100]) {
    int sum = 0;
    for (int col= 0; col < n; col++) {
        int col_sum = 0;
        for (int row = 0; row < n; row++) {
            col_sum += square[row][col];
        }
        if (col == 0) {
            sum = col_sum;
        } else if (sum != col_sum) {
            printf("col Magic Square k hop le\n");
            return 0;
        }
    }
    return sum;
}

void check_sq_diagonal(int n, int square[100][100]) {

}

int check_sq(int n, int square[100][100]) {
    int row_sum = check_sq_row(n, square);
    if (row_sum == 0) {
        return 0;
    }
    int col_sum = check_sq_col(n, square);
    if (col_sum == 0) {
        return 0;
    }
    return col_sum == row_sum;
}

void ms_2k_1(int n, int square[100][100]) {
 
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
    }
} 

void ms_4k(int n, int square[100][100]) {
    for (int row = 0; row < n; row++ ) {
        for (int col = 0; col < n; col++) {
            int value = n*row + col + 1;
            if ( (row % 4 == col % 4) || (row % 4 + col % 4 == 3) ) {
                square[row][col] = value;
            } else {
                square[row][col] = (n*n+1) - value;
            }
        }
    }
}

int go_L(int square[100][100], int row, int col, int value) {
    square[row][col] = value + 1;
    square[row + 1][col - 1] = value + 2;
    square[row + 1][col] = value + 3;
    square[row][col - 1] = value + 4;
}

int go_U(int square[100][100], int row, int col, int value) {
    square[row][col] = value + 1;
    square[row + 1][col] = value + 2;
    square[row + 1][col + 1] = value + 3;
    square[row][col + 1] = value + 4;
}

int go_X(int square[100][100], int row, int col, int value) {
    square[row][col] = value + 1;
    square[row + 1][col + 1] = value + 2;
    square[row + 1][col] = value + 3;
    square[row][col + 1] = value + 4;
}

void ms_4k_2(int n, int square[100][100]) {
    int m = n/2;
    int k = (n - 2) / 4;
    int row = 0;
    int col = m / 2;
    for (int value = 1; value <= m*m; value++) {
        if ((row == k + 1 && col == k) || row < k + 1) {
            go_L(square, row, col, value );
        } else if ((row == k && col == k) || row == k + 1) {
            go_U(square, row, col, value);
        } else {
            go_X(square, row, col, value);
        }
        
        int new_row = row == 0 ? m-1 : row - 1;
        int new_col = col == m - 1 ? 0 : col + 1;
        if (square[new_row][new_col] != 0) {
            new_row = (row + 1) % m;
            new_col = col;
        }
        row = new_row;
        col = new_col;
        // square[row][col] = value;
    }
    printf("%d\n", n);
}

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
    // input
    int n = 6;
    
    // process
    int square[100][100] = {0};
    if (n % 2 != 0) {
        ms_2k_1(n, square);
    } else if (n % 4 == 2) {
        ms_4k_2(n, square);
    } else {
        ms_4k(n, square);
    }
    // square[2][1] = 0;
    print_square(square, n);
    if (check_sq(n, square)) {
        printf("-Magic Square hop le\n");
    } else {
        printf("Magic Square k hop le\n");
    }
}