# Functions
A function is a block of code that performs some purpose. Some functions you may be familiar with are  `printf()`, `scanf()`, `main()`.

## Anatomy of a Function
Your typical function has these parts: 
* the return type
* the function name 
* the parameter list
* the curly braces
* the code that is run when the function is called

### Example using `main()`
```c
// int is the return type
// the function name is main
// main takes no parameters.
int main()
{
    // We return 0 because the function has a return type of int.
    return 0;
}
```

## Functional Prototypes in C
Consider the code below
```c
// Steeve Joseph
// An example of writing functions in C.

#include <stdio.h>

#define PI 3.14

int main()
{
    // Example: Let's says we want to calculate the area of a circle
    int radius = 3;
    double area = getAreaOfCircle(radius);

    return 0;
}

// Notice the syntax:
// returnType functionName(parameters)
// {   
//   *code*
// }
double getAreaOfCircle(double radius)
{
    return PI * (radius * radius);
}
```

If this code were to be run as-is, you'd probably get a warning about "implicit declaration of `getAreaOfCircle()`". 
* The reason this happens is because in a C program, each line is run top down, sequentially. 
* What this means is, when main() is called, the compiler doesn't "know" what getAreaOfCircle() is, because it hasn't gotten to that line yet. 

To remedy this, we have to declare a functional prototype at the top of our file. All a functional prototype does is let the compiler know that there will be a function that will be defined below.


```c
// Steeve Joseph
// An example of writing functions in C.

#include <stdio.h>

#define PI 3.14

// functional protoype
double getAreaOfCircle(double radius);


int main()
{
    int radius = 3;

                  // calling the function 
    double area = getAreaOfCircle(radius);

    return 0;
}

// actual definition of the function
double getAreaOfCircle(double radius)
{
    return PI * (radius * radius);
}
```