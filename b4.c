#include <stdio.h>
#include <stdbool.h>

// Hàm thực hiện thuật toán Sắp xếp chèn
void insertionSort(int arr[], int n, bool ascending)
{
    int i, j, key;

    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        // Di chuyển các phần tử lớn hơn (hoặc nhỏ hơn) key sang bên phải
        while (j >= 0 && ((ascending && arr[j] > key) || (!ascending && arr[j] < key)))
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;

        // In trạng thái mảng sau mỗi bước chèn
        printf("Mảng sau bước %d: ", i);
        for (int k = 0; k < n; k++)
        {
            printf("%d ", arr[k]);
        }
        printf("\n");
    }
}

int main()
{
    int n, i;
    bool ascending;

    // Nhập số lượng phần tử của mảng
    printf("Nhập số lượng phần tử của mảng: ");
    scanf("%d", &n);

    int arr[n];

    // Nhập các phần tử của mảng
    printf("Nhập các phần tử của mảng: \n");
    for (i = 0; i < n; i++)
    {
        printf("Phần tử %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // In mảng ban đầu
    printf("Mảng ban đầu: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Lựa chọn thứ tự sắp xếp
    printf("Chọn thứ tự sắp xếp (1 - Tăng dần, 0 - Giảm dần): ");
    scanf("%d", &ascending);

    // Gọi hàm sắp xếp
    insertionSort(arr, n, ascending);

    // In kết quả sau khi sắp xếp
    printf("Mảng sau khi sắp xếp: \n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
