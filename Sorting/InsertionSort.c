#include <conio.h>
#include <stdio.h>

// worse case time complexity : O(n^2)
void insertionSort(int[], int);

void main()
{
    int arr[20], num, i;
    // clrscr();

    printf("Enter number of elements in array: ");
    scanf("%d", &num);

    for (i = 0; i < num; i++)
    {
        printf("Enter element %d : ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("\nInput array: ");
    for (i = 0; i < num; i++)
    {
        printf("%d ", arr[i]);
    }

    insertionSort(arr, num);

    printf("\nSorted array: ");
    for (i = 0; i < num; i++)
    {
        printf("%d ", arr[i]);
    }

    // getch();
}

void insertionSort(int arr[], int n)
{
    int i, j, temp;

    for (i = 1; i < n; i++) // i starts from 1, i.e. 2nd index
    {
        temp = arr[i]; // storing current index value in temp as it gets overwritten

        // j starts from left of current i
        // arr[j] > temp condition explained - since left part is sorted already, we compare temp with the sorted part, starting from right most element of sorted part (if it is smaller than temp then no need to insert temp, it is already at correct place, hence loop won't run even once)
        for (j = i - 1; j >= 0 && arr[j] > temp; j--)
        {
            arr[j + 1] = arr[j];
        }

        arr[j + 1] = temp; // inserting temp at the correct position in sorted part
    }
}