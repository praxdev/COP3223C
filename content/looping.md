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

- Typically the variable names used for counters are `i`, `j`, and `k`.
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

The while loop does the same thing as the for loop above.

- The main difference in the examples are where the increment happens.
  - Concretely, while loops are used when it is not known beforehand how many times the loop needs to run.
    - If there was a finite starting and ending point, why would someone use a while loop over a for loop?

## The Do While Loop

```c
// Steeve Joseph
// An example of the do while loop
#include <stdio.h>
int main(void)
{
    int i = 0;

    // The following lines prints out the numbers 0-9 on their own line.
    do
    {
        printf("%d\n", i);
        i++;

    } while (i < 10);

    return 0;
}
```

### Explanation

A `do...while` loop has a very similar syntax to the `while` loop, and its purpose is similar as well. The relevant difference between the two is that the `do...while` is guaranteed to run at least once, because the evaluation is at the end of the loop.

## When Do I Know When to Use Which Loop?

Theoretically, any `for` loop can be written as a `while` loop, and any `while` loop can be written as a `for` loop. In practice, the `do-while` loop isn't used as often.

**In short, if you have a start and end condition in mind, use a for loop. Else, use a while loop.**

### Example

- If you were calculating grades for 200 students, you might use a `for` loop to do some math from `i = 0` to `i < 200`.

- However, if you didn't know how many students you had at the beginning, you'd probably do the same math in a `while` loop, until some signal to stop.

## Danger: Infinite Loop

A very common issue is getting caught in an infinite loop. You'll know you're in one if the output window just hangs for a long time, or the same thing gets printed over and over unintentionally.

```c
// Steeve Joseph
// An example of some infinite loops.
#include <stdio.h>
int main(void)
{

    // Infinite while loop: The condition in the parens always evaluates to true.
    while (1)
    {
        printf("Hi\n");
    }

    // Infinite for loop: There is no condition to stop the loop.
    //  If the above while loop is not commented out, the code below will actually never run
    //   (stuck in previous loop)
    for (;;)
    {
        printf("Bye");
    }

    return 0;
}
```

## `break`, `bontinue`, `goto`

`break`, `bontinue`, `goto` are **control sequences**. Basically, these statements modify the normal behavior of the loop.

- `break` breaks out (completely stops) out of the loop it is used in.
- `continue` continues on to the next iteration of the loop.
- ~~`goto`~~ allows you to go to a specfic block of code. I only mention it for posterity, don't use it. Notice I crossed it out. **NEVER** use goto.

### Example

```c
// Steeve Joseph
// An example of break, continue.
#include <stdio.h>
int main(void)
{
    int i;
    for (i = 0; i <= 10; i++)
    {
        // Continue on to the next iteration if i is odd.
        if (i % 2 == 1)
        {
            continue;
        }

        // If i is 10, break out of the loop.
        if (i == 10)
        {
            break;
        }

        // Print i if the above two conditions are false.
        printf("%d\n", i);
    }

    return 0;
}


```

## FAQs

- **Q**: How do I know when to use `i < someNumber` vs `i <= someNumber`?

  - **A**: Which one you use depends on the scenario at hand.
    - e.g.: You want to print a line 10 times.
      - `for(i=0; i<10; i++)` can also be written as `for(i=1; 1<=10; i++)`

- **Q**: Follow-up: If it doesn't make a difference, why do people start with `i = 0` and end with `i < num`?

  - **A**: Convention, mostly. Counting in computer science typically starts at 0, mostly because it made a lot of complex math easier.

- **Q**: Sometimes I see `int i` in the `for` loop. Why?
  - **A**: Newer implementations of C allow for the declaration of the counter in the `for` loop. However, the oolder implementation of C **DOESN'T**. To be safe, I'd say declare your counters outside the loop so that your code is compatible with more (possibly older) systems, e.g. computers at NASA.

## Takeaways

1. `for` loops run code for a specified start and end point.
2. `while` loops run code while a specific condition is true.
3. **_DO NOT USE `goto`_**
