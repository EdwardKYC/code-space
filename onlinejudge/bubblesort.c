#include <stdio.h>

void bubbleSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = i; j > 0 ; j--)
        {
            if (arr[j] < arr[j - 1])
            {
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
        }
    }
}

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    { 
        int arr[n];
        for (int i = 0; i < n; i++)
        { 
            scanf("%d", &arr[i]);
        }
        bubbleSort(arr, n);
        for (int i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    return 0;
}