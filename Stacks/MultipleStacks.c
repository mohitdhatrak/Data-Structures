#include <stdio.h>
#include <conio.h>
#define MAX 20

int stack[MAX], topA = -1, topB = MAX;

void pushA();
void popA();
void peekA();
void displayA();

// stack B starts from the other end of array, so we need to decrement to add new values
void pushB();
void popB();
void peekB();
void displayB();

void main()
{
    int choice, val;

    // clrscr();

    do
    {
        printf("\n*** OPERATIONS MENU ***");
        printf("\n1. Push in stack A");
        printf("\n2. Push in stack B");
        printf("\n3. Pop from stack A");
        printf("\n4. Pop from stack B");
        printf("\n5. Peek into stack A");
        printf("\n6. Peek into stack B");
        printf("\n7. Display stack A");
        printf("\n8. Display stack B");
        printf("\n9. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            pushA();
            break;

        case 2:
            pushB();
            break;

        case 3:
            popA();
            break;

        case 4:
            popB();
            break;

        case 5:
            peekA();
            break;

        case 6:
            peekB();
            break;

        case 7:
            displayA();
            break;

        case 8:
            displayB();
            break;

        case 9:
            printf("Program exit...");
            break;

        default:
            printf("Enter a valid input!\n");
        }
    } while (choice != 9);

    // getch();
}

void pushA()
{
    int val;

    if (topA == topB - 1) // when index of top of A is just 1 behind top of B
    {
        printf("Stack overflow!\n");
    }
    else
    {
        printf("\nEnter a number: ");
        scanf("%d", &val);

        stack[++topA] = val;
        printf("Pushed element is %d \n", stack[topA]);
    }
}

void pushB()
{
    int val;

    if (topB - 1 == topA) // when index of top of B is just 1 ahead of top of A
    {
        printf("Stack overflow!\n"); // same condition as for A
    }
    else
    {
        printf("\nEnter a number: ");
        scanf("%d", &val);

        stack[--topB] = val;
        printf("Pushed element is %d \n", stack[topB]);
    }
}

void popA()
{
    if (topA == -1)
    {
        printf("Stack underflow!\n");
    }
    else
    {
        printf("Popped element is %d \n", stack[topA--]);
    }
}

void popB()
{
    if (topB == MAX)
    {
        printf("Stack underflow!\n");
    }
    else
    {
        printf("Popped element is %d \n", stack[topB++]);
    }
}

void peekA()
{
    if (topA == -1)
    {
        printf("Stack A is empty! \n");
    }
    else
    {
        printf("Peeked element is %d \n", stack[topA]);
    }
}

void peekB()
{
    if (topB == MAX)
    {
        printf("Stack B is empty! \n");
    }
    else
    {
        printf("Peeked element is %d \n", stack[topB]);
    }
}

void displayA()
{
    int i;

    if (topA == -1)
    {
        printf("Stack A is empty! \n");
    }
    else
    {
        printf("Elements in stack A from top to bottom: ");
        for (i = topA; i >= 0; i--)
        {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

void displayB()
{
    int i;

    if (topB == MAX)
    {
        printf("Stack B is empty! \n");
    }
    else
    {
        printf("Elements in stack B from top to bottom: ");
        for (i = topB; i < MAX; i++)
        {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}
