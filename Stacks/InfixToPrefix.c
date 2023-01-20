// we use infix to postfix code only, as follows:

// For example, given an infix expression (A - B / C) * (A / K - L)

// Step 1 : Reverse the infix string. NOTE - that while reversing the string you must interchange left and right parentheses.
// (L - K / A) * (C / B - A)

// Step 2 : Obtain the corresponding postfix expression of the infix expression obtained as a result of Step 1. So we pass the reversed infix expression into infixToPostfix function

// Step 3 : Reverse the postfix expression to get the prefix expression

// code for reversing the infix expression
// void reverse(char str[])
// {
//     int len, i = 0, j = 0;
//     len = strlen(str);
//     j = len - 1;
//     while (j >= 0)
//     {
//         if (str[j] == '(')
//             temp[i] = ')'; // temp[] is global variable to store new infix exps
//         else if (str[j] == ')')
//             temp[i] = '(';
//         else
//             temp[i] = str[j];
//
//         i++, j--;
//     }
//     temp[i] = '\0';
// }