#include <conio.h>
#include <stdio.h>

// worse case time complexity : O(log n)
// has better time complexity than linear search
void bubbleSort(int[], int);
int binarySearch(int[], int, int);

void main()
{
    int arr[20], num, element, i, findIndex = -1;
    // clrscr();

    printf("Enter number of elements in array: ");
    scanf("%d", &num);

    for (i = 0; i < num; i++)
    {
        printf("Enter element %d : ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("\nEnter element to be searched: ");
    scanf("%d", &element);

    printf("\nInput array: ");
    for (i = 0; i < num; i++)
    {
        printf("%d ", arr[i]);
    }

    bubbleSort(arr, num);

    printf("\nSorted array: ");
    for (i = 0; i < num; i++)
    {
        printf("%d ", arr[i]);
    }

    findIndex = binarySearch(arr, element, num);

    if (findIndex != -1)
    {
        printf("\n\nElement found!");
    }

    // getch();
}

void bubbleSort(int arr[], int n)
{
    int i, j, temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int binarySearch(int arr[], int element, int n)
{
    int lower = 0, higher = n - 1, middle, i;

    for (i = 0; higher >= lower; i++)
    {
        middle = (lower + higher) / 2;

        if (arr[middle] == element)
            return middle;
        else if (arr[middle] < element)
        {
            lower = middle + 1;
        }
        else
            higher = middle - 1;
    }

    printf("\n\nElement not found");
    return -1;
}