#include <stdio.h>
#include <conio.h>
#include <malloc.h>
// #include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *start = NULL;

struct node *createList(struct node *);
struct node *displayList(struct node *);
struct node *insertStart(struct node *);
struct node *insertEnd(struct node *);
struct node *insertBefore(struct node *);
struct node *insertAfter(struct node *);
struct node *deleteStart(struct node *);
struct node *deleteEnd(struct node *);
struct node *deleteBefore(struct node *);
struct node *deleteAfter(struct node *);
struct node *deleteNode(struct node *);
struct node *deleteList(struct node *);
struct node *sortList(struct node *);

void main()
{
    int choice;

    // clrscr();

    do
    {
        printf("\n *** OPERATIONS MENU ***");
        printf("\n 1. Create a list"); // can also be used to add multiple data later
        printf("\n 2. Display the list");
        printf("\n 3. Insert start");
        printf("\n 4. Insert end");
        printf("\n 5. Insert before a node");
        printf("\n 6. Insert after a node");
        printf("\n 7. Delete start");
        printf("\n 8. Delete end");
        printf("\n 9. Delete before");
        printf("\n10. Delete after");
        printf("\n11. Delete node");
        printf("\n12. Delete list");
        printf("\n13. Sort list");
        printf("\n14. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            start = createList(start);
            break;

        case 2:
            printf("\nLinked list : ");
            start = displayList(start);
            break;

        case 3:
            start = insertStart(start);
            break;

        case 4:
            start = insertEnd(start);
            break;

        case 5:
            start = insertBefore(start);
            break;

        case 6:
            start = insertAfter(start);
            break;

        case 7:
            start = deleteStart(start);
            break;

        case 8:
            start = deleteEnd(start);
            break;

        case 9:
            start = deleteBefore(start);
            break;

        case 10:
            start = deleteAfter(start);
            break;

        case 11:
            start = deleteNode(start);
            break;

        case 12:
            start = deleteList(start);
            break;

        case 13:
            printf("\nSorted list : ");
            start = sortList(start);
            break;

        case 14:
            printf("Program exit...");
            break;

        default:
            printf("Enter a valid input!\n");
        }
    } while (choice != 14);

    // getch();
}

struct node *createList(struct node *start)
{
    struct node *newnode, *ptr;
    int data;

    printf("\nEnter the data: ");
    scanf("%d", &data);

    while (data != -1)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = data;
        newnode->next = NULL;

        if (start == NULL)
        {
            start = newnode;
        }
        else
        {
            ptr = start;
            // we need to traverse list from start to get to the last node
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = newnode;
        }

        printf("Enter the data: ");
        scanf("%d", &data);
    }
    printf("\nLinked list created! \n");

    return start;
}

struct node *displayList(struct node *start)
{
    struct node *ptr;
    ptr = start;

    if (start == NULL)
    {
        printf("list is empty!");
    }
    else
    {
        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
    }
    printf("\n");

    return start;
}

struct node *insertStart(struct node *start)
{
    struct node *newnode;
    int data;

    printf("\nEnter the data: ");
    scanf("%d", &data);

    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = start; // newnode will point to the 2nd node
    start = newnode;       // start will now point to the newnode making it the 1st node

    return start;
}

struct node *insertEnd(struct node *start)
{
    struct node *newnode, *ptr;
    int data;

    printf("\nEnter the data: ");
    scanf("%d", &data);

    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;

    ptr = start;
    while (ptr->next != NULL) // to find the last node
    {
        ptr = ptr->next;
    }
    ptr->next = newnode; // link last node to newnode (making it the new last node)

    return start;
}

struct node *insertBefore(struct node *start)
{
    struct node *newnode, *ptr, *preptr; // preptr is always 1 node behind ptr
    int data, value;

    printf("\nEnter the data: ");
    scanf("%d", &data);
    printf("\nEnter the value before which the data has to be inserted: ");
    scanf("%d", &value);

    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;

    ptr = start;
    while (ptr->data != value) // we insert before 'ptr', so we compare with ptr
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    // new node is to be inserted between preptr and ptr
    preptr->next = newnode;
    newnode->next = ptr;

    return start;
}

struct node *insertAfter(struct node *start)
{
    struct node *newnode, *ptr, *preptr;
    int data, value;

    printf("\nEnter the data: ");
    scanf("%d", &data);
    printf("\nEnter the value after which the data has to be inserted: ");
    scanf("%d", &value);

    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;

    ptr = start;
    preptr = ptr;                 // need to initialize preptr here
    while (preptr->data != value) // we insert after 'preptr', so we compare with preptr
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    // new node is to be inserted between preptr and ptr
    preptr->next = newnode;
    newnode->next = ptr;

    return start;
}

struct node *deleteStart(struct node *start)
{
    struct node *ptr;

    ptr = start; // we store it so we can free its memory space
    start = start->next;

    printf("\nDeleted node with value %d \n", ptr->data);
    free(ptr);

    return start;
}

struct node *deleteEnd(struct node *start)
{
    struct node *ptr, *preptr;

    ptr = start;
    while (ptr->next != NULL)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = NULL; // 2nd last node points to NULL, now acting as last node

    printf("\nDeleted node with value %d \n", ptr->data);
    free(ptr);

    return start;
}

struct node *deleteBefore(struct node *start)
{
    struct node *ptr, *preptr, *postptr;
    int value;

    printf("\nEnter the value before which the node has to be deleted: ");
    scanf("%d", &value);

    ptr = start;
    postptr = ptr->next;
    while (postptr->data != value) // here, we compare with postptr
    {
        preptr = ptr;
        ptr = ptr->next;
        postptr = ptr->next; // post ptr is 1 node ahead of ptr
    }
    preptr->next = postptr; // linking preptr to postptr, as ptr is deleted

    printf("\nNode deleted! \n");
    free(ptr);

    return start;
}

struct node *deleteAfter(struct node *start)
{
    struct node *ptr, *preptr;
    int value;

    printf("\nEnter the value after which the node has to be deleted: ");
    scanf("%d", &value);

    ptr = start;
    preptr = ptr;
    while (preptr->data != value) // similar to insert after
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = ptr->next; // linking preptr to node after ptr

    printf("\nNode deleted! \n");
    free(ptr);

    return start;
}

struct node *deleteNode(struct node *start)
{
    struct node *ptr, *preptr;
    int value;

    printf("\nEnter the value of the node which has to be deleted: ");
    scanf("%d", &value);

    ptr = start;
    if (ptr->data == value)
    {
        start = deleteStart(start);
    }
    else
    {
        while (ptr->data != value)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = ptr->next; // linking preptr to node after ptr

        printf("\nNode deleted! \n");
        free(ptr);
    }

    return start;
}

struct node *deleteList(struct node *start)
{
    struct node *ptr;

    if (start != NULL)
    {
        ptr = start;
        while (ptr != NULL)
        {
            // start = deleteStart(ptr); // we can use deleteStart function too
            start = start->next;
            free(ptr);
            ptr = start;
        }
        printf("\nWhole list deleted! \n");
    }
    else
    {
        printf("\nLinked list is empty! \n");
    }

    return start;
}

struct node *sortList(struct node *start)
{
    struct node *ptr1, *ptr2;
    int temp;

    if (start == NULL)
    {
        printf("list is empty! \n");
    }
    else
    {
        ptr1 = start;
        while (ptr1->next != NULL)
        {
            ptr2 = ptr1->next;
            while (ptr2 != NULL)
            {
                if (ptr1->data > ptr2->data)
                {
                    temp = ptr1->data;
                    ptr1->data = ptr2->data;
                    ptr2->data = temp;
                }
                ptr2 = ptr2->next;
            }
            ptr1 = ptr1->next;
        }

        start = displayList(start);
    }

    return start;
}