#include <stdio.h>

void createMatrix(int m[][100], int r, int c) {
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) {
            printf("Phan tu hang %d cot %d: ", i + 1, j + 1);
            scanf("%d", &m[i][j]);
        }
}

void printMatrix(int m[][100], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) printf("%d ", m[i][j]);
        printf("\n");
    }
}

int main() {
    int r, c;
    int m[100][100];
    printf("Nhap so hang: "); scanf("%d", &r);
    printf("Nhap so cot: "); scanf("%d", &c);
    createMatrix(m, r, c);
    printMatrix(m, r, c);
    return 0;
}

