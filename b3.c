#include <stdio.h>
#include <stdbool.h>

// Hàm thực hiện thuật toán Sắp xếp chọn
void selectionSort(int arr[], int n, bool ascending) {
    int i, j, minOrMaxIdx;

    for (i = 0; i < n - 1; i++) {
        // Giả sử phần tử đầu tiên là nhỏ nhất hoặc lớn nhất
        minOrMaxIdx = i;

        for (j = i + 1; j < n; j++) {
            if ((ascending && arr[j] < arr[minOrMaxIdx]) || (!ascending && arr[j] > arr[minOrMaxIdx])) {
                minOrMaxIdx = j;
            }
        }

        // Hoán đổi nếu cần thiết
        if (minOrMaxIdx != i) {
            int temp = arr[i];
            arr[i] = arr[minOrMaxIdx];
            arr[minOrMaxIdx] = temp;
        }
    }
}

// Hàm thực hiện thuật toán Tìm kiếm nhị phân
int binarySearch(int arr[], int n, int target) {
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid; // Tìm thấy phần tử, trả về vị trí
        } else if (arr[mid] < target) {
            left = mid + 1; // Tìm trong nửa phải
        } else {
            right = mid - 1; // Tìm trong nửa trái
        }
    }

    return -1; // Không tìm thấy
}

int main() {
    int n, i, target;
    bool ascending = true; // Sắp xếp tăng dần để phục vụ tìm kiếm nhị phân

    // Nhập số lượng phần tử của mảng
    printf("Nhập số lượng phần tử của mảng: ");
    scanf("%d", &n);

    int arr[n];

    // Nhập các phần tử của mảng
    printf("Nhập các phần tử của mảng: \n");
    for (i = 0; i < n; i++) {
        printf("Phần tử %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // In mảng ban đầu
    printf("Mảng ban đầu: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Gọi hàm sắp xếp
    selectionSort(arr, n, ascending);

    // In kết quả sau khi sắp xếp
    printf("Mảng sau khi sắp xếp: \n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Nhập phần tử cần tìm
    printf("Nhập phần tử cần tìm: ");
    scanf("%d", &target);

    // Gọi hàm tìm kiếm nhị phân
    int result = binarySearch(arr, n, target);

    // In kết quả tìm kiếm
    if (result != -1) {
        printf("Phần tử %d được tìm thấy tại vị trí %d (chỉ số mảng bắt đầu từ 0).\n", target, result);
    } else {
        printf("Phần tử %d không có trong mảng.\n", target);
    }

    return 0;
}
