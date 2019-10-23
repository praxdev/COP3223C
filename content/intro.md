# Introduction

## What is Programming? What about Computer Science?

Programming, essentially, is giving instructions to a computer so that it performs some task or solves some problem. Holistically, the goal of computer science is to solve problems, and a lot of the time, computers are what we use to solve those problems.

## What is a programming language?

A programming language is like a spoken language. It is a set of words, symbols, etc used to convey an idea or to get a point across.

- You may ask, "If a programming language serves a purpose similar to say, English, why isn't code written in English?"
  - English is long, and has ~17K words in its lexicon. Programming languages allow you to express complex ideas concisely.
  - English is ambiguous
    - Imagine someone asking you, "Do you want ice cream or cookies?" And with a sly grin you answer, "yes". Implicitly they meant "this or that (but not both)", but a valid interpration is "this or that". A programming language typically has less ambiguity, given that each expression typically means one and only one thing.

## The C Programming Language

The C language in particular is the focus of the class. C was created by a team of scientists at Bell Labs, the most prominent among them being Brian Kernighan and Denis Ritchie.

- Fun fact: K&R are on the UCF wall of CS and Electrical Engineering in HEC.

## Things to Note

- In the beginning, CS/programming seems like this mystical thing that you have to be super smart/talented to understand

- Realistically, the main skill built when programming/compsci is problem-solving.

- Thus, it is helpful to think of learning C as a tool, and as you progress through the semester, you are building your toolbox to solve a wide array of problems. I'd argue that this perspective is optimistic, and also pragmatic.

* For ~~the rest of your life~~ the remainder of your class, you'll be encountering a series of scenarios that can be described as problems, broken down to core pieces, and solved. To be able to adequately solve these problems, it helps to gain some proficiency with the tools. Welcome to C.

# Your First C Program

Usually, when you begin learning a programming language, you start with a "Hello World" assignment, wherein the goal is to simply print out "Hello World" to the screen.

Your first C program will likely look something like this

```c
 1 // need to include the library for input/output
 2 //  (for printing)
 3 #include <stdio.h>
 4
 5
 6 // main function
 7 int main() {
 8   // print to screen
 9    printf("Hello world!");
10
11    // return error code
12    return 0;
13 }
```

## Notes

- the "//" denotes a comment. Comments are like notes programmers use to explain what is happening if the code itself is not apparent. They are completely ignored by the compiler and has no effect on the code.
- Line 3, Line 9:
  - Line 9 calls the printf() function, that prints something to the screen. To use `printf()`, you must import the standard input/output library (stdio.h). Think of line 3 as saying, "Include all the functions in the library stdio.h"
- Units of functionality are broken down into blocks known as **functions**. Basically, calling a function is akin to saying, "Do this thing"
  - Whenever you build/run a C program, your Operating System will look for a function called `main`, and attempt to run it.
- Note that line 7 begins with `int`. Note also that line 12 says `return 0`. What does this mean?
  - Every function in C will have a return type, and the return type indicates the data type that the value returns. [Brief intro to data types in C](https://www.geeksforgeeks.org/data-types-in-c/)
  - We will get to data types a bit later, but in this specific context, here's what happens.
    1. The program is compiled (built)
    2. The program is run
    3. The OS looks for the main function
    4. If found, the code in `main()` runs.
       1. Else, an error is given. Errors are fun :)
    5. "Hello World" is printed to the screen/console.
       1. `printf()` is another function. It prints whatever is in the double quotes to the screen.
    6. The value 0 is returned.
       1. Not super important right now, but returning 0 from main indicates that there was no error when the program was run.

## Takeaways:

1. The main goal of programming and computer science is to solve problems. One of the tools that is used to do this is a programming language, and the programming language is used becaue it gives a concise, [deterministic](https://en.wikipedia.org/wiki/Deterministic_algorithm) way to express a solution to a problem.
2. Every program you write in C will have these parts:
   1. An `int main()` function that (typically) returns 0, and the necessary code will be in between curly braces.
   2. You'll typically write `#include <stdio.h>` at the top of your programs to include necessary standard IO functionality such as printing to the console, reading in user input, etc. [Full stdio.h specification here](https://www.tutorialspoint.com/c_standard_library/stdio_h.htm)
