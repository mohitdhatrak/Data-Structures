#include <conio.h>
#include <stdio.h>

// worse case time complexity : O(n^2)
void quickSort(int[], int, int);
int partitionArray(int[], int, int);

void main()
{
    int arr[20], num, i, first, last;
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

    first = 0;
    last = num - 1;

    quickSort(arr, first, last);

    printf("\nSorted array: ");
    for (i = 0; i < num; i++)
    {
        printf("%d ", arr[i]);
    }

    // getch();
}

void quickSort(int arr[], int first, int last)
{
    int end;

    // process of sorting ends when first is less than last
    if (first < last)
    {
        end = partitionArray(arr, first, last);

        // now sort the sub-array before pivot element
        quickSort(arr, first, end - 1);

        // now sort the sub-array after pivot element
        quickSort(arr, end + 1, last);
    }
}

int partitionArray(int arr[], int first, int last)
{
    int i, j, pivot, temp;

    pivot = first;
    i = first;
    j = last;

    // repeat whole process only till start is placed before end
    while (i < j)
    {
        // increment i only if arr[i] is NOT greater than pivot element
        while (arr[i] <= arr[pivot] && i < last)
        {
            i++;
        }

        // decrement j only if arr[i] is greater than pivot element
        while (arr[j] > arr[pivot])
        {
            j--;
        }

        // if start has not crossed end, then swap those elements
        if (i < j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // as soon as i >= j, we swap end element with pivot element
    temp = arr[pivot];
    arr[pivot] = arr[j];
    arr[j] = temp;

    // now the pivot element is placed at its final sorted position

    // return the position of the end counter i.e. j
    return j;
}