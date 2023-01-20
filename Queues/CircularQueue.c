#include <stdio.h>
#include <conio.h>
#define MAX 20

int queue[MAX];
int front = -1, rear = -1;

// linear queue code, only few changes
// helps make sure all spaces are used in queue no vacancy

void insert();
void delete();
void peek(); // same code as linear queue no change
void display();

void main()
{
    int choice;

    // clrscr();

    do
    {
        printf("\n*** OPERATIONS MENU ***");
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Peek");
        printf("\n4. Display");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insert();
            break;

        case 2:
            delete ();
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

void insert()
{
    int num;

    printf("Enter the number to be inserted in the queue: ");
    scanf("%d", &num);

    if ((front == 0 && rear == MAX - 1) || (rear == front - 1)) // overflow condition --  change 1
    {
        printf("Queue overflow!\n");
    }
    else if (front != 0 && rear == MAX - 1) // taking rear to start of queue -- change 2
    {
        rear = 0;
        queue[rear] = num;
    }
    else if (rear == -1) // adding first element to queue
    {
        front = rear = 0;
        queue[rear] = num;
    }
    else
    {
        queue[++rear] = num; // like push in stack
    }
}

void delete()
{
    if (rear == -1) // or front == -1
    {
        printf("Queue underflow!\n");
    }
    else
    {
        printf("The number deleted is: %d \n", queue[front]);

        // condition where queue becomes empty
        if (front == rear)
        {
            front = rear = -1; // reset front and rear values as queue got empty
        }
        else
        {
            // to update front, we have 2 cases now -- change 1
            if (front == MAX - 1) // since last element reached, front is set to 0
            {
                front = 0;
            }
            else
            {
                front++;
            }
        }
    }
}

void peek()
{
    if (rear == -1) // or front == -1
    {
        printf("Queue is empty!\n");
    }
    else
    {
        printf("The first value in queue is: %d \n", queue[front]);
    }
}

void display()
{
    int i;

    if (rear == -1) // or front == -1
    {
        printf("Queue is empty!\n");
    }
    else
    {
        printf("Elements in queue from front to rear: ");
        if (front <= rear) // then same logic for display as linear queue
        {
            for (i = front; i <= rear; i++)
            {
                printf("%d ", queue[i]);
            }
        }
        else // change 1 -- if front > rear
        {
            for (i = front; i < MAX; i++)
            {
                printf("%d ", queue[i]);
            }
            for (i = 0; i <= rear; i++)
            {
                printf("%d ", queue[i]);
            }
        }
        printf("\n");
    }
}