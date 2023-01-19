#include <stdio.h>
#include <conio.h>
#define MAX 20

int stack[MAX], top = -1;

void push();
void pop();
void peek(); // shows the value at the top of the stack
void display();

void main()
{
    int choice;

    // clrscr();

    do
    {
        printf("\n*** OPERATIONS MENU ***");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Peek");
        printf("\n4. Display");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push();
            break;

        case 2:
            pop();
            break;

        case 3:
            peek();
            break;

        case 4:
            display();
            break;

        case 5:
            printf("Program exit...");
            break;

        default:
            printf("Enter a valid input!\n");
        }
    } while (choice != 5);

    // getch();
}

void push()
{
    int val;

    if (top == MAX - 1)
    {
        printf("Stack overflow!\n");
    }
    else
    {
        printf("\nEnter a number: ");
        scanf("%d", &val);

        stack[++top] = val;
        printf("Pushed element is %d \n", stack[top]);
    }
}

void pop()
{
    if (top == -1)
    {
        printf("Stack underflow!\n");
    }
    else
    {
        printf("Popped element is %d \n", stack[top--]);
    }
}

void peek()
{
    if (top == -1)
    {
        printf("Stack is empty! \n");
    }
    else
    {
        printf("Peeked element is %d \n", stack[top]);
    }
}

void display()
{
    int i;

    if (top == -1)
    {
        printf("Stack is empty! \n");
    }
    else
    {
        printf("Elements in stack from top to bottom: ");
        for (i = top; i >= 0; i--)
        {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}