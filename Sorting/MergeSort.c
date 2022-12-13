#include <conio.h>
#include <stdio.h>

// worse case time complexity : O(n * log(n))
void mergeSort(int[], int, int);
void merge(int[], int, int, int);

void main()
{
    int arr[20], num, i, left, right;
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

    left = 0;
    right = num - 1;

    mergeSort(arr, left, right);

    printf("\nSorted array: ");
    for (i = 0; i < num; i++)
    {
        printf("%d ", arr[i]);
    }

    // getch();
}

void mergeSort(int arr[], int l, int r)
{
    int m;

    if (l < r)
    {
        // Same as (l + r) / 2, but avoids overflow for large l and r
        m = l + (r - l) / 2;

        // here recursion works like, one half gets totally divided till only 1 element is left, then that same half starts to get merged so the first half of the main array is merged and sorted, now same process happens with the second half of the main array
        // after that both the sorted halfs are merged to form the final sorted array

        // sort first half of the array
        mergeSort(arr, l, m);

        // sort second half of the array
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int leftArr[n1], rightArr[n2];

    // entering values in both arrays
    for (i = 0; i < n1; i++)
    {
        leftArr[i] = arr[l + i]; // left array starts with l
    }
    for (j = 0; j < n2; j++)
    {
        rightArr[j] = arr[m + 1 + j]; // right array starts with m + 1
    }

    i = 0; // initial index of first subarray or left arr
    j = 0; // initial index of second subarray or right arr
    k = l; // initial index of merged subarray or arr

    // merging left and right arrays to get complete array
    while (i < n1 && j < n2)
    {
        if (leftArr[i] <= rightArr[j])
        {
            arr[k] = leftArr[i];
            i++;
        }
        else
        {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // we don't reset values of i, j, k here hence they are continued below

    // to copy any remaining elements of leftArr
    while (i < n1)
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // to copy any remaining elements of rightArr
    while (j < n2)
    {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}
