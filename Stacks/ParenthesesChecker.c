#include <stdio.h>
#include <conio.h>
#include <string.h>
#define MAX 3

int top = -1;
int stack[MAX];

void push(char);
char pop();

// getting wrong answer for few expression in vc code
// eg. {a+b-(c-d)}, ({}[{}]()) -- but works correctly online, code logic correct

void main()
{
    char exp[MAX], temp;
    int i, flag = 1;

    // clrscr();

    printf("Enter an expression: ");
    gets(exp);

    // we push only opening brackets into the stack, and once we get closing bracket, we pop stack to get latest opening bracket, then check popped opening bracket with current closing bracket
    // if it matches, we continue further, else break
    for (i = 0; i < strlen(exp); i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (top == -1)
            {
                flag = 0;
                break;
            }
            else
            {
                temp = pop();

                if (exp[i] == ')' && (temp == '{' || temp == '['))
                {
                    flag = 0;
                    break;
                }
                else if (exp[i] == '}' && (temp == '(' || temp == '['))
                {
                    flag = 0;
                    break;
                }
                else if (exp[i] == ']' && (temp == '(' || temp == '{'))
                {
                    flag = 0;
                    break;
                }
            }
        }
    }

    // this is to ensure that all opened brackets are closed, stack should be empty if all open brackets got popped
    if (top >= 0) // or top != -1
    {
        flag = 0;
    }

    if (flag == 1)
    {
        printf("Valid expression");
    }
    else
    {
        printf("Invalid expression");
    }

    // getch();
}

void push(char c)
{
    if (top == (MAX - 1))
    {
        printf("Stack Overflow\n");
    }
    else
    {
        stack[++top] = c;
    }
}

char pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n"); // useless as pop won't be called if top == -1
    }
    else
    {
        return (stack[top--]);
    }
}