# Looping

This is one of my favorite subjects for a couple of reasons:

1. Learning to loop saves a bunch of time when done correctly.
2. This was a part of Intro to C I particularly struggled with.

## Motivation

We use loops to do some task over and over.

## The `for` loop

### Example

```c
// Steeve Joseph
// An example of the for loop
#include <stdio.h>
int main(void)
{
    int i;

    // The following lines prints out the numbers 0-9 on their own line.
    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", i);
    }

    return 0;
}
```

### Explanation

The anatomy of a `for` loop:

```c
for(initialization; condition; increment/decrement)
{
    *code to be repeated*
}
```

#### Initialization

The initialization statement declares some variable, typically a counter.

- Typically the variable names used for counters are `i`, `j`, and `k`
- Occasionally, you'll see the counter declared inside the for statement. I would recommend avoiding that practice, and I explain a little more detail in the FAQs.

#### Condition

The condition determines how long the code in the block will be repeated. Specifically, the loop will run until the condition is false.

#### Increment/Decrement

Somewhat self-explanatory, but since we're using a variable as a counter, we want to increase/or decrease the counter after each iteration of a task.

  ```c
    int i;
  
    // Example of increment
    for(i = 0; i < 10; i++) 
    {
        printf("%d\n", i);

        if(i >= 9)
            printf("Entering double digits...\n");

    }

    // Example of decrement
    for(i = 10; i >=0 ; i--) 
    {
        printf("%d\n", i);

        if(i == 0)
            printf("Blast off!\n");
    }
  ```
  
## The `while` loop

### Example

```c
// Steeve Joseph
// An example of the while loop
#include <stdio.h>
int main(void)
{
    int i = 0;

    // The following lines prints out the numbers 0-9 on their own line.
    while (i < 10)
    {
        printf("%d\n", i);
        i++;
    }

    return 0;
}
```

### Explanation

The anatomy of a while loop:

```c
  while(condition)
  {
    *code to be run while condition is true*
  }

```

## When Do I Know When to Use Which Loop?

Theoretically, any for loop can be written as a while loop, and any while loop can be written as a for loop.

**In short, if you have a start and end condition in mind, use a for loop. Else, use a while loop.**

### Example

- If you were calculating grades for 200 students, you might use a loop to do some math from `i = 0` to `i < 200`. 
  
- However, if you didn't know how many students you had at the beginning, you'd probably do the same math in a while loop, until some signal to stop.

## FAQs

- **Q**: How do I know when to use `i < someNumber` vs `i <= someNumber`?

  - **A**: Which one you use depends on the scenario at hand.
    - e.g.: You want to print a line 10 times.
      - `for(i=0; i<10; i++)` can also be written as `for(i=1; 1<=10; i++)`

- **Q**: Follow-up: If it doesn't make a difference, why do people start with `i = 0` and end with `i < num`?

  - **A**: Convention, mostly. Counting in computer science typically starts at 0, mostly because it made a lot of complex math easier.

- **Q**: Sometimes I see int i in the for loop. Why?
  - **A**: Newer implementations of C allow for the declaration of the counter in the for loop. However, the oolder implementation of C **DOESN'T**. To be safe, I'd say declare your counters outside the loop so that your code is compatible with more (possibly older) systems, e.g. computers at NASA.
