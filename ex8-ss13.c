#include <stdio.h>

int u(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int a, b;
    printf("Nhap vao hai so nguyen: ");
    scanf("%d %d", &a, &b);

    int result = u(a, b);
    printf("UCLN cua %d va %d la: %d\n", a, b, result);

    return 0;
}

