# Functions (work in progress)

A function is a block of code that performs some purpose. Some functions you may be familiar with are `printf()`, `scanf()`, `main()`.

## Anatomy of a Function

1. Your typical function declaration has at leeast these parts:

   - the return type
   - the function name
   - the parameter list

2. The sum of these parts is referred to as the **function signature**. For each function you define, it must have a unique function signature.
   - Specifically, two functions **cannot** have the same name and parameter list in C. This is similar to how two files on your desktop cannot have the same name and same file extension.
     - Otherwise, how would the OS know which one's which?

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

## The Main Interactions with A Function

In C, there are 3 main ways you'll be interacting with functions.

1. Writing the functional prototype.
   1. This lets the compiler know a function with a specific name, parameter list, and return type **will be** defined.
2. Defining the function
   1. This is writing the function signature, the curly braces, and the code to be run when the function is called.
3. Calling the function.
   1. This is writing the function name, and the parens with the arguments inside.

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

- The reason this happens is because in a C program, each line is run top down, sequentially.
- What this means is, when `main()` is called, the compiler doesn't "know" what `getAreaOfCircle`() is, because it hasn't gotten to that line yet.

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

## Functions vs Methods (vs Subroutines vs Procedures)

- For the most part, **function** and **method** are used interchangeably.
  Technically, a method is a function that is defined within a class. This is important in Object Oriented Programming, but this can be a fun fact for now.
- **Functions** are also referred to occasionally as **subroutines** or **procedures**.

## Arguments vs Parameters

These two terms are also used interchangeably for the most part. The rule of thumb I follow is that we call them arguments when the function is being called, and parameters when the function is being defined. [This StackOverflow answer is good.](https://stackoverflow.com/a/1788926)

## Pass by Reference vs Pass by Value

AKA (call by reference, call by value). This may be a bit slippery, try to understand.

### Example

```c
// Steeve Joseph
// An example of a (defunct) swap function.

#include <stdio.h>

void swap(int a, int b);

int main()
{
    int a = 71;
    int b = 37;

    printf("Before swapping, a: %d, b: %d\n", a, b);
    swap(a, b);
    printf("After swapping, a: %d, b: %d\n", a, b);

    return 0;
}

// The intent is to swap the value two integers.
void swap(int a, int b)
{
    // temp serves as an intermediary
    int temp;

    // Do you understand why we can't write the code like this?
    // a=b;
    // b=a;

    temp = a;
    a = b;
    b = temp;

    return;
}
```

If you run the code above, you may be surprised by the output. Specifically, the code above doesn't **actually** swap the two ints. Why is this?

### Explanation

- C, by default, passes arguments to functions **by value**.

  - What this means is that when the function is called, the values of a and b are passed to the function, not the actual integers.

  - Say you were doing some calculations on a set of data. You'd want to be able to work and manipulate the values **without** modifying the original data set.

    - This makes it so that in the event that something were to go awry within the function, there'd be no real harm done to the data that was passed to it.

But what if we **wanted** to modify the original data, such as in our `swap()` function?

### Example

```c
// Steeve Joseph
// An example of a swap function.

#include <stdio.h>

void swap(int *a, int *b);

int main()
{
    int a = 71;
    int b = 37;

    printf("Before swapping, a: %d, b: %d\n", a, b);

    // Instead of passing the values of a and b, we tell swap WHERE a and b are in memory.
    swap(&a, &b);

    printf("After swapping, a: %d, b: %d\n", a, b);

    return 0;
}

// Swaps two integers.
// Takes as parameters the addresses of two ints.
void swap(int *a, int *b)
{
    int temp;

    // set temp to the value at a's address.
    temp = *a;

    // set the contents of a to the contents of b.
    *a = *b;

    // set the contents of b to temp.
    *b = temp;
}
```

### Explanation

#### Pass by Reference

Pass by reference is what it sounds like. Instead of passing the value of the argument to a fucntion, we instead pass a reference to that argument. This is done using a **pointer**. A pointer, in the simplest sense, is a memory address where data is stored. Passing an argument by reference allows us to directly modify the contents at that memory address.

A list of some ELI5 explanations on pointers in case my explanation wasn't clear:

1. [Sensible example](https://www.reddit.com/r/learnprogramming/comments/1w6v07/eli5_pointers_and_their_usefulness/)
2. [Another example](https://www.reddit.com/r/explainlikeimfive/comments/j5cdd/eli5_pointers_in_programming/)
3. [More in-depth explanation using C++](https://www.reddit.com/r/explainlikeimfive/comments/5zsw16/eli5pointers_in_programming/)
