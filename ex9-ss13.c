#include <stdio.h>
#include <math.h>

int isPrime(int num) {
    if (num < 2) return 0;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

void inputMatrix(int arr[][100], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
}

void printMatrix(int arr[][100], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void printCorner(int arr[][100], int n, int m) {
    printf("%d %d %d %d\n", arr[0][0], arr[0][m-1], arr[n-1][0], arr[n-1][m-1]);
}

void printBorder(int arr[][100], int n, int m) {
    for (int i = 0; i < n; i++) {
        printf("%d %d ", arr[i][0], arr[i][m-1]);
    }
    for (int j = 1; j < m - 1; j++) {
        printf("%d %d ", arr[0][j], arr[n-1][j]);
    }
    printf("\n");
}

void printDiagonals(int arr[][100], int n, int m) {
    for (int i = 0; i < n; i++) {
        if (i < m) {
            printf("%d %d ", arr[i][i], arr[i][m-1-i]);
        }
    }
    printf("\n");
}

void printPrimes(int arr[][100], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (isPrime(arr[i][j])) {
                printf("%d ", arr[i][j]);
            }
        }
    }
    printf("\n");
}

int main() {
    int arr[100][100], n, m, choice;

    scanf("%d", &n);
    scanf("%d", &m);

    do {
    	printf("MENU\n"); 
        printf("1 Nhap gia tri cac phan tu cua mang\n");
        printf("2 In gia tri cac phan tu cua mang theo ma tran\n");
        printf("3 In ra cac phan tu o goc theo ma tran\n");
        printf("4 In ra cac phan tu nam tren duong bien theo ma tran\n");
        printf("5 In ra cac phan tu nam tren duong cheo chinh va cheo phu theo ma tran\n");
        printf("6 In ra cac phan tu la so nguyen to theo ma tran\n");
        printf("7 Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                inputMatrix(arr, n, m);
                break;
            case 2:
                printMatrix(arr, n, m);
                break;
            case 3:
                printCorner(arr, n, m);
                break;
            case 4:
                printBorder(arr, n, m);
                break;
            case 5:
                printDiagonals(arr, n, m);
                break;
            case 6:
                printPrimes(arr, n, m);
                break;
            case 7:
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (choice != 7);

    return 0;
}

