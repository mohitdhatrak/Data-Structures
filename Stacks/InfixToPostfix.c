#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#define MAX 20

char stack[MAX];
int top = -1;

void push(char);
char pop();
void infixtoPostfix(char infixExp[], char postfixExp[]);
int getPriority(char); // -- code assuming operators will only be + - / * %
// -- also we assume an expression must have only () these parantheses, so [] or {} are considered invalid characters

// it is better to pass input infix expression through parantheses checker instead of checking only few conditions here
// here we don't check if every opening bracket has a closing one, so even (a+b-c is evaluated as abc-+( which is incorrect as postfix/prefix expressions can't have parantheses

void main()
{
    char infixExp[20], postfixExp[20];

    // clrscr();

    printf("Enter any infix expression: ");
    gets(infixExp);

    strcpy(postfixExp, "");
    infixtoPostfix(infixExp, postfixExp);

    printf("The corresponding postfix expression is: ");
    puts(postfixExp); // string is an array, so pass by reference, hence updated here

    // getch();
}

void infixtoPostfix(char infixExp[], char postfixExp[])
{
    int i = 0, j = 0; // i for infix expression index, j for postfix expression index

    while (infixExp[i] != '\0') // iterate over infix expression till we get NULL character
    {
        // 5 cases of if-else
        if (infixExp[i] == '(') // case 1
        {
            push(infixExp[i]); // -- if opening bracket, then push it to stack
        }
        else if (infixExp[i] == ')') // case 2
        {
            if (top == -1)
            {
                printf("Incorrect expression!"); // like parathesis checker, we can skip this if we implement parathesis checker
                exit(1);
            }

            while (stack[top] != '(') // -- if closing bracket, then we pop stack into our postfix expression till we get an opening bracket
            {
                postfixExp[j] = pop();
                j++;
            }

            pop(); // -- to remove left parenthesis (i.e. opening bracket)
        }
        else if (isdigit(infixExp[i]) || isalpha(infixExp[i])) // case 3
        {
            postfixExp[j] = infixExp[i]; // -- if digit or alphabet, then add it to postfix expression directly
            j++;
        }
        else if (infixExp[i] == '+' || infixExp[i] == '-' || infixExp[i] == '*' ||
                 infixExp[i] == '/' || infixExp[i] == '%') // case 4
        {
            while ((top != -1) && (stack[top] != '(') && (getPriority(stack[top]) > getPriority(infixExp[i])))
            {
                postfixExp[j] = pop(); // -- if operator priority of current stack top element is higher than current operator of infix expression, then we pop the stack into our postfix expression
                j++;
            }

            // -- once all higher priority operators are popped into postfix expression, we push current operator of infix expression
            push(infixExp[i]);
        }
        else // case 5 - any other character than above cases
        {
            printf("Invalid character in expression!");
            exit(1);
        }

        i++; // incrementing index of infix expression
    }

    // to ensure all operators get popped into postfix expression, so stack empty condition
    // for eg. (a+b-c) -> abc-+ with above code, but a+b-c -> abc with above code
    // as a+b-c does not have any parentheses outside it, so we need below loop
    while (top != -1)
    {
        postfixExp[j] = pop();
        j++;
    }

    postfixExp[j] = '\0'; // to end expression with NULL character
}

int getPriority(char op)
{
    if (op == '/' || op == '*' || op == '%')
    {
        return 1;
    }
    else if (op == '+' || op == '-')
    {
        return 0;
    }
}

void push(char c)
{
    if (top == MAX - 1)
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
        printf("Stack Underflow\n");
    }
    else
    {
        return stack[top--];
    }
}