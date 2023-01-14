#include <conio.h>
#include <stdio.h>

// worse case time complexity : O(n + 2) or O(n)
// has better time complexity than linear search
int sentinelSearch(int[], int, int);

void main()
{
    int arr[20], num, i, element, findIndex = -1;
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

    findIndex = sentinelSearch(arr, element, num);

    if (findIndex != -1)
    {
        printf("\n\nElement found at position %d (index %d)", findIndex + 1, findIndex);
    }

    // getch();
}

int sentinelSearch(int arr[], int element, int n)
{
    int i = 0;

    // Last element of the array
    int last = arr[n - 1];

    // Element to be searched is placed at the last index
    arr[n - 1] = element;

    while (arr[i] != element)
    {
        i++;
    }

    // Put the last element back
    arr[n - 1] = last;

    if ((i < n - 1) || (arr[n - 1] == element))
    {
        return i;
    }

    printf("\n\nElement not found!");
    return -1;
}
