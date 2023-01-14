#include <conio.h>
#include <stdio.h>

// logic reference video - https://youtu.be/q_AVjuzBxoc

// worse case time complexity : O(log n)
// has better time complexity than linear search (except for small arrays) and sentinel search
void bubbleSort(int[], int); // like binary search we have to sort first
int fibonacci(int, int, int, int[]);
int fibonacciSearch(int[], int, int, int[], int);

void main()
{
    int arr[20], size, i, element, findIndex = -1;
    int fiboArr[20], fiboIndex, num1 = 0, num2 = 1;
    // clrscr();

    printf("Enter number of elements in array: ");
    scanf("%d", &size);

    for (i = 0; i < size; i++)
    {
        printf("Enter element %d : ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("\nEnter element to be searched: ");
    scanf("%d", &element);

    printf("\nInput array: ");
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    bubbleSort(arr, size); // sort arr in ascending order

    printf("\nSorted array: ");
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    fiboIndex = fibonacci(num1, num2, size, fiboArr);

    findIndex = fibonacciSearch(arr, element, size, fiboArr, fiboIndex);

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

int fibonacci(int num1, int num2, int size, int fiboArr[])
{
    int sum, k;

    if (size == 1)
    {
        // inserting first element of fibonacci sequence
        fiboArr[0] = num1;
        k = 1;
    }
    else
    {
        // inserting first 2 elements of fibonacci sequence
        fiboArr[0] = num1;
        fiboArr[1] = num2;
        k = 2;

        while (1)
        {
            sum = num1 + num2;
            fiboArr[k] = sum; // store fibonacci sequence, last element has to be the sum - which is part of the loop breaking condition, hence we write this above breaking condition
            if (sum >= size)  // loop breaking condition
            {
                break;
            }
            num1 = num2;
            num2 = sum;
            k++;
        }
    }

    return k;
}

int fibonacciSearch(int arr[], int element, int size, int fiboArr[], int k) // k is required fibArr index
{
    int index; // index is similar to middle in binary search, it is used to divide the array like we do in binary search
    int offset = -1;
    int value1, value2, i;

    if (fiboArr[k] == 0) // or should we use, k == 0 || k == 1, as k >= 2 only
    {
        printf("\n\nElement not found!");
        return -1;
    }
    else
    {
        // this for loop is very similar to the one in binary search
        // instead of middle we have index
        for (i = 0; i < size; i++)
        {
            value1 = offset + fiboArr[k - 2];
            value2 = size - 1;
            index = value1 > value2 ? value2 : value1; // to store the min value

            if (arr[index] == element)
            {
                return index;
            }
            else if (arr[index] < element)
            {
                k--;
                offset = index;
            }
            else
            {
                k -= 2;
            }
        }
    }

    printf("\n\nElement not found!");
    return -1;
}
