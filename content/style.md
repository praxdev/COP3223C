# Style in C

## Why Does Style Matter?

- Clean, formatted code is easier to maintain, debug, and read.
- Also, if you ask someone to help you with an issue in your code, they will probably tell you to format your code before helping you

## Tenets of Conventional C Style

I think the best way to teach is by example:

```c
// Steeve Joseph
// 09/13/2019
// A sample C program showing some elements of style in C

// After your header comment explaining the program, then
// do your #include statements
#include <stdio.h>


// #define'd constants are typically all uppercase
#define PI 3.14

// #define with longer constant name
#define MY_FAVORITE_NUMBER 1

// choosing verbs for function names is a good idea
void greetUser()
{
    printf("Hello user!");
}

// If your variable/function name has multiple words, use camelCase
int incrementUsersAge()
{
    int age;
    printf("Please enter your age!\n");
    scanf("%d", &age);

    // Use spaces in between operators
    return age + 1;
}

// In C, put your opening brace on a new line
int main()
{
    int i;

    // indent 4 spaces in body of loops
    for(i=0; i < 10; i++)
    {
        // indent 4 spaces in body of if statement
        if(i == 5)
            break;
    }

    // if there is only one statement in the loop body, it is syntactically valid to omit the braces
    // (tip: don't)
    while(1)
        incrementUsersAge();

    return 0;
}
```
