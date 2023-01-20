#include <stdio.h>
#include <conio.h>
#define MAX 20

int queue[MAX];
int front = -1, rear = -1;

void insert();  // insertion occurs at the rear end, so rear++
void delete();  // deletion occurs from the front end, so front++
void peek();    // peek is for element which will be out(deleted) next, hence front end
void display(); // display from front to rear

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

    if (rear == MAX - 1)
    {
        printf("Queue overflow!\n");
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
            front++; // updating front
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
        for (i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}