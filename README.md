# Data-Structures

### Q. Difference b/w int arr[] and int \*arr OR What is the difference between pointer and array?

### A -> Array in C is used to store elements of same types whereas Pointers are address varibles which stores the address of a variable. Now array variable is also having a address which can be pointed by a pointer and array can be navigated using pointer.r Benefit of using pointer for array is two folds, first, we store the address of dynamically allocated array to the pointer and second, to pass the array to a function. Following are the differences in using array and using pointer to array.

### Ans link -> https://www.quora.com/What-is-the-difference-between-pointer-and-array

### An asterisk is a pointer to a type.

### Thus, int[] \* is a pointer to an array of ints. That is, you have a pointer to an array type/variable.

### On the other hand, the int _ is a pointer to an int. There is a common behaviour in redirecting between int[] and int _, but it is not the same (e.g. one of the first google search results https://www.quora.com/What-is-the-difference-between-pointer-and-array)

### Setting aside that difference of int * and int[], the *arr[] is a pointer to an array. Because you can use the pointer mechanics/arithmetics to access arrays using pointers, you can think the *arr[] as a two dimensional array. That is, the equivalent of *arr[] with only pointers is int\*\*
