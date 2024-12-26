#include <stdio.h>
#include <stdbool.h>

// Hàm thực hiện thuật toán
void bubbleSort(int arr[], int n, bool ascending)
{
    int i, j;
    bool swapped;

    for (i = 0; i < n - 1; i++)
    {
        swapped = false;

        for (j = 0; j < n - i - 1; j++)
        {
            if ((ascending && arr[j] > arr[j + 1]) || (!ascending && arr[j] < arr[j + 1]))
            {
                // Hoán đổi 2 ptu
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }

        // Nếu không có phần tử nào được hoán đổi
        if (!swapped)
            break;
    }
}

int main()
{
    int n, i;
    bool ascending;

    printf("Nhập số lượng phần tử của mảng: ");
    scanf("%d", &n);

    int arr[n];

    printf("Nhập các phần tử của mảng:\n");
    for (i = 0; i < n; i++)
    {
        printf("Phần tử %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Chọn thứ tự sắp xếp (1 - Tăng dần, 0 - Giảm dần): ");
    scanf("%d", &ascending);

    // Gọi hàm sắp xếp
    bubbleSort(arr, n, ascending);

    printf("Mảng sau khi sắp xếp:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
