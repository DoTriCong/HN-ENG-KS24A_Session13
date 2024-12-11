#include <stdio.h>

void addItem(int arr[], int* size) {
    printf("Nhap so phan tu can nhap: ");
    scanf("%d", size);
    if (*size > 100) {
        printf("So phan tu khong duoc qua 100\n");
        *size = 100;
    }
    for (int i = 0; i < *size; i++) {
        printf("Nhap vao gia tri phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

void printArray(int arr[], int size) {
    printf("Danh sach cac phan tu:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertItem(int arr[], int* size) {
    int pos, value;
    printf("Nhap vi tri can them (0 to %d): ", *size);
    scanf("%d", &pos);
    if (pos < 0 || pos > *size) {
        printf("Vi tri khong hop le\n");
        return;
    }
    printf("Nhap gia tri phan tu can them: ");
    scanf("%d", &value);
    for (int i = *size; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
    (*size)++;
}

void editItem(int arr[], int size) {
    int pos, value;
    printf("Nhap vi tri phan tu can sua (0 to %d): ", size - 1);
    scanf("%d", &pos);
    if (pos < 0 || pos >= size) {
        printf("Vi tri khong hop le\n");
        return;
    }
    printf("Nhap gia tri moi cho phan tu: ");
    scanf("%d", &value);
    arr[pos] = value;
}

void deleteItem(int arr[], int* size) {
    int pos;
    printf("Nhap vi tri phan tu can xoa (0 to %d): ", *size - 1);
    scanf("%d", &pos);
    if (pos < 0 || pos >= *size) {
        printf("Vi tri khong hop le\n");
        return;
    }
    for (int i = pos; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
}

void sortArray(int arr[], int size, int order) {
    int temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if ((order == 1 && arr[i] < arr[j]) || (order == 0 && arr[i] > arr[j])) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int size, int key) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) {
            return mid;
        }
        if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    int arr[100];
    int size = 0;
    int choice;
    do {
        printf("\nMENU\n");
        printf("1. Nhap so phan tu can nhap va gia tri cac phan tu\n");
        printf("2. In ra gia tri cac phan tu dang quan ly\n");
        printf("3. Them mot phan tu vao vi tri chi dinh\n");
        printf("4. Sua mot phan tu o vi tri chi dinh\n");
        printf("5. Xoa mot phan tu o vi tri chi dinh\n");
        printf("6. Sap xep cac phan tu\n");
        printf("   a. Giam dan\n");
        printf("   b. Tang dan\n");
        printf("7. Tim kiem phan tu nhap vao\n");
        printf("   a. Tim kiem tuyen tinh\n");
        printf("   b. Tim kiem nhi phan\n");
        printf("8. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addItem(arr, &size);
                break;
            case 2:
                printArray(arr, size);
                break;
            case 3:
                insertItem(arr, &size);
                break;
            case 4:
                editItem(arr, size);
                break;
            case 5:
                deleteItem(arr, &size);
                break;
            case 6: {
                char order;
                printf("Lua chon sap xep:\n");
                printf("a. Giam dan\n");
                printf("b. Tang dan\n");
                scanf(" %c", &order);
                if (order == 'a') {
                    sortArray(arr, size, 1);
                } else {
                    sortArray(arr, size, 0);
                }
                break;
            }
            case 7: {
                int key, result;
                char searchChoice;
                printf("Lua chon tim kiem:\n");
                printf("a. Tim kiem tuyen tinh\n");
                printf("b. Tim kiem nhi phan\n");
                scanf(" %c", &searchChoice);
                printf("Nhap gia tri can tim: ");
                scanf("%d", &key);
                if (searchChoice == 'a') {
                    result = linearSearch(arr, size, key);
                } else {
                    result = binarySearch(arr, size, key);
                }
                if (result == -1) {
                    printf("Khong tim thay phan tu\n");
                } else {
                    printf("Phan tu %d duoc tim thay tai vi tri %d\n", key, result);
                }
                break;
            }
            case 8:
                printf("Thoat chuong trinh\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (choice != 8);
    return 0;
}

