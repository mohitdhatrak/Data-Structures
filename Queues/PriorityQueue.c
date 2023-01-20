#include <stdio.h>
#include <malloc.h>
#include <conio.h>
// #include <stdlib.h>

struct node
{
    int data;
    int priority;
    struct node *next;
};

// priority queues types - ascending ordered or descending ordered

// priority queue using linked list
// this code is ascending order priority queue, meaning 'lowest priority value' is placed at front, and will be deleted first (in queue we delete from front/start)
// here we 'search' the proper position according to priority during 'insertion'

// priority queue using array
// we insert values at 'rear' normally like a linear queue with array,
// here we 'search' the lowest priority value, everytime during 'deletion'

// if priorities are equal, we follow FIFO rule like a normal queue

struct node *start = NULL;

struct node *insert(struct node *);
struct node *delete(struct node *);
// struct node *peek(struct node *);
struct node *display(struct node *);

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
            start = insert(start);
            break;

        case 2:
            start = delete (start);
            break;

        case 3:
            // start = peek(start);
            break;

        case 4:
            start = display(start);
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

struct node *insert(struct node *start)
{
    struct node *newnode, *ptr;
    int val, pri;

    printf("Enter the value: ");
    scanf("%d", &val);
    printf("Enter its priority: ");
    scanf("%d", &pri);

    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->priority = pri;

    // if newnode has higher priority than start, we make newnode as the start
    if (start == NULL || pri < start->priority)
    {
        newnode->next = start;
        start = newnode;
    }
    else
    {
        ptr = start;
        while (ptr->next != NULL && ptr->next->priority <= pri)
        {
            ptr = ptr->next; // finally, ptr becomes the node after which we need to insert newnode to place it at its proper priority position
        }
        newnode->next = ptr->next;
        ptr->next = newnode;
    }

    return start;
}

struct node *delete(struct node *start)
{
    struct node *ptr;

    if (start == NULL)
    {
        printf("Queue underflow!\n");
    }
    else
    {
        ptr = start;
        printf("Deleted item is: %d \n", ptr->data);
        start = start->next; // we delete from start as the list is already as per priority while insertion only, so we just delete the first element (in ascending order priority queue, 'lower priority value' = highest priority, so deleted 1st)
        free(ptr);
    }

    return start;
}

struct node *display(struct node *start)
{
    struct node *ptr;

    ptr = start;
    if (start == NULL)
    {
        printf("Queue is empty!\n");
    }
    else
    {
        printf("Priority queue is: \n");
        while (ptr != NULL)
        {
            printf("%d [priority = %d] \n", ptr->data, ptr->priority);
            ptr = ptr->next;
        }
    }

    return start;
}