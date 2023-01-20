#include <stdio.h>
#include <conio.h>
#include <malloc.h>
// #include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void insert();
void delete();
void display();
void peek();

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
        printf("\nEnter your choice : ");
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

void insert() // no overflow in linked list as its dynamic memory
{
    struct node *newnode;
    int val;

    printf("Enter the number to inserted in the queue: ");
    scanf("%d", &val);

    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = val;

    if (front == NULL) // adding first element to queue
    {
        front = newnode;
        rear = newnode;
        front->next = NULL;
        rear->next = NULL;
    }
    else // adding new element to existing queue, insert at rear
    {
        rear->next = newnode; // link old rear to newnode (new rear)
        rear = newnode;       // update rear
        rear->next = NULL;
    }
}

void delete()
{
    struct node *ptr;

    ptr = front; // need ptr to free memory
    if (front == NULL)
    {
        printf("Queue underflow!\n");
    }
    else
    {
        front = front->next; // updating front hence older front is deleted
        printf("The value being deleted is: %d \n", ptr->data);
        free(ptr);
    }
}

void peek()
{
    if (front == NULL)
    {
        printf("Queue is empty!\n");
    }
    else
    {
        printf("The value at front of queue is: %d \n", front->data);
    }
}

void display()
{
    struct node *ptr;

    ptr = front;
    if (front == NULL)
    {
        printf("Queue is empty!\n");
    }
    else
    {
        printf("Elements in queue from front to rear: ");
        while (ptr != NULL) // or ptr != rear->next
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
}
