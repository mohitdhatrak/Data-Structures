#include <stdio.h>
#include <conio.h>
// #include <stdlib.h>
#define size 10

int h[size];

void insert();
void search();
void display();

void main()
{
    int choice, i;

    // clrscr();

    // inserting -1 at all places into hash table
    for (i = 0; i < size; i++)
    {
        h[i] = -1;
    }

    do
    {
        printf("\n*** OPERATIONS MENU ***");
        printf("\n1. Insert");
        printf("\n2. Search");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insert();
            break;

        case 2:
            search();
            break;

        case 3:
            display();
            break;

        case 4:
            printf("Program exit...");
            break;

        default:
            printf("Enter a valid input!\n");
        }
    } while (choice != 4);

    // getch();
}

void insert()
{
    int key, index, hkey, i; // 'index' represents index at which key will be inserted

    printf("Enter a value to insert into hash table: "); // except -1 as we stored it as default value at all places in hash table
    scanf("%d", &key);

    hkey = key % size; // size is the size of the hash table

    for (i = 0; i < size; i++)
    {
        index = (hkey + i) % size; // formula to get 'index'

        if (h[index] == -1)
        {
            h[index] = key;
            printf("Element inserted at index %d \n", index);
            break;
        }
    }

    if (i == size)
    {
        printf("Element cannot be inserted\n");
    }
}

void search()
{
    int key, index, hkey, i;

    printf("Enter search element: ");
    scanf("%d", &key);

    hkey = key % size; // size is the size of the hash table

    for (i = 0; i < size; i++)
    {
        index = (hkey + i) % size; // formula to get 'index'

        if (h[index] == key)
        {
            printf("Value is found at index %d \n", index);
            break;
        }
    }

    if (i == size)
    {
        printf("Value is not found!\n");
    }
}

void display()
{
    int i;

    printf("Elements in the hash table are: \n");
    for (i = 0; i < size; i++)
    {
        printf("At index %d, value =  %d \n", i, h[i]);
    }
}