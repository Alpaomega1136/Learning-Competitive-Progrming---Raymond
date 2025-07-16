// link : https://codeforces.com/problemset/problem/263/A
#include <stdio.h>
#include <math.h>

int main() { 
    short int matrix[5][5];
    int i, j, row, col;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            scanf("%hd", &matrix[i][j]);
            if (matrix[i][j] == 1) {
                row = i;
                col = j;
            }
        }
    }
    printf("%d\n", abs(row - 2) + abs(col - 2));
    return 0;
}