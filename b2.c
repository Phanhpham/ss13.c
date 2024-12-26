#include <stdio.h>
#include <stdbool.h>

void selectionSort(int arr[], int n, bool ascending)
{
    int i, j, minOrMaxIdx;

    for (i = 0; i < n - 1; i++)
    {
        // vd phần tử đầu tiên là nhỏ nhất hoặc lớn nhất
        minOrMaxIdx = i;

        for (j = i + 1; j < n; j++)
        {
            if ((ascending && arr[j] < arr[minOrMaxIdx]) || (!ascending && arr[j] > arr[minOrMaxIdx]))
            {
                minOrMaxIdx = j;
            }
        }

        // Hoán đổi nếu cần thiết
        if (minOrMaxIdx != i)
        {
            printf("Hoán đổi: %d <-> %d\n", arr[i], arr[minOrMaxIdx]);
            int temp = arr[i];
            arr[i] = arr[minOrMaxIdx];
            arr[minOrMaxIdx] = temp;
        }

        printf("Mảng sau bước %d: ", i + 1);
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

    printf("Nhập số lượng phần tử của mảng: ");
    scanf("%d", &n);

    int arr[n];

    printf("Nhập các phần tử của mảng: \n");
    for (i = 0; i < n; i++)
    {
        printf("Phần tử %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Mảng ban đầu: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Chọn thứ tự sắp xếp (1 - Tăng dần, 0 - Giảm dần): ");
    scanf("%d", &ascending);

    // Gọi hàm sắp xếp
    selectionSort(arr, n, ascending);

    printf("Mảng sau khi sắp xếp: \n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
