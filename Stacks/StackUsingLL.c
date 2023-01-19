#include <stdio.h>
#include <conio.h>
#include <malloc.h>
// #include <stdlib.h>

struct stack
{
    int data;
    struct stack *next;
};

struct stack *top = NULL;

struct stack *push(struct stack *);
struct stack *pop(struct stack *);
struct stack *peek(struct stack *); // shows the value at the top of the stack
struct stack *display(struct stack *);

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
            top = push(top);
            break;

        case 2:
            top = pop(top);
            break;

        case 3:
            top = peek(top);
            break;

        case 4:
            top = display(top);
            break;
        }
    } while (choice != 5);

    //  getch();
}

struct stack *push(struct stack *top)
{
    struct stack *ptr;
    int val;

    printf("\nEnter a number: ");
    scanf("%d", &val);

    ptr = (struct stack *)malloc(sizeof(struct stack));
    ptr->data = val;

    if (top == NULL)
    {
        ptr->next = NULL;
        top = ptr;
    }
    else
    {
        ptr->next = top;
        top = ptr;
    }
    printf("Pushed element is %d \n", top->data);

    return top;
}

struct stack *pop(struct stack *top)
{
    struct stack *ptr;

    ptr = top;
    if (top == NULL)
    {
        printf("Stack underflow!\n");
    }
    else
    {
        top = top->next;
        printf("Popped element is %d \n", ptr->data);
        free(ptr);
    }

    return top;
}

struct stack *peek(struct stack *top)
{
    if (top == NULL)
    {
        printf("Stack is empty! \n");
    }
    else
    {
        printf("Peeked element is %d \n", top->data);
    }

    return top;
}

struct stack *display(struct stack *top)
{
    struct stack *ptr;

    ptr = top;
    if (top == NULL)
    {
        printf("Stack is empty! \n");
    }
    else
    {
        printf("Elements in stack from top to bottom: ");
        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }

    return top;
}