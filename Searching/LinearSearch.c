#include <conio.h>
#include <stdio.h>

// worse case time complexity : O(2n + 1) or O(2n)
int linearSearch(int[], int, int);

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

    findIndex = linearSearch(arr, element, num);

    if (findIndex != -1)
    {
        printf("\nElement found at position %d (index %d)", findIndex + 1, findIndex);
    }

    // getch();
}

int linearSearch(int arr[], int element, int n)
{
    int i = 0;

    for (i = 0; i < n; i++)
    {
        if (element == arr[i])
            return i;
    }

    printf("\nElement not found!");
    return -1;
}
