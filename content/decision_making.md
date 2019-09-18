# Decision Making

In essence, these notes focuses on conditional code execution. More concretely, we'll focus on code we want to run **if** a certain set of conditions is true. That being said, the first way we'll do this is by using the `if` statement in C.

## `if`, `else if`, and `else`

**NOTE**: Code in between curly braces is sometimes referred to as a "block" of code.

- Like the names suggest:

  - Code in the `if` block runs if a given condition is true.

  - Code in the `else if` block runs if the previous `if` statement is false.

  - The else block is the default case, and the code in it will run if all else fails.

If is probably shown best by example.

```c
// Steeve Joseph
// A sample program showing off if, else-if, and else.
#include <stdio.h>

int main(void)
{
    int userAge;
    printf("Hello, please enter your age:\n");
    scanf("%d", &userAge);

    // `if` follows this syntax:
    //   if(condition)
    //   {
    //       *code to run goes here*
    //   }
    if (userAge >= 21)
    {
        printf("You are old enough to drink.\n");
    }

    else if (userAge >= 18)
    {
        printf("You are old enough to be considere an adult, but not old enough to drink. \n");
    }

    // for `if`, `else if` and `else` statements,
    //  if there is only one line you want to execute,
    //  you can omit the curly braces (I would not recommend this though)
    else if (userAge >= 0)
        printf("You are not old enough to be considere an adult, nor are you old enough to drink. \n");

    else
    {
        printf("You entered an invalid age.");
    }

    return 0;
}
```

## Nesting statements

`if`, `else if`, and `else` can be **nested** in each other, like so:

```c
#include <stdio.h>

int main(void)
{
    int userAge;
    printf("Hello, please enter your age:\n");
    scanf("%d", &userAge);

    if (userAge >= 18)
    {
        printf("You are an adult");

        // The line beneath runs if the `if` statement above is true,
        //  and also if this `if` statement is true.
        if (userAge >= 21)
            printf("... and you are old enough to drink.\n");
        else
            printf("... but you are old enough to drink.\n");
    }

    // You can alternatively write the above lines of code like this
    if (userAge >= 21 && userAge >= 18)
    {
        printf("You are an adult");
        printf("... and you are old enough to drink.\n");
    }

    else
    {
        printf("You are an adult... but you are not old enough to drink.\n");
    }

    return 0;
}
```

## `switch`

The `switch` statement has similar use to `if`, `else if`, and `else`. The main difference is in syntax. The code example below is similar to the one above, just using `switch` instead of `if`.

```c
// Steeve Joseph
// A sample program showing an example of a switch statement in C.

#include <stdio.h>

int main(void)
{
    int userAge;
    printf("Hello, please enter your age:\n");
    scanf("%d", &userAge);

    switch (userAge)
    {

    // Similar to saying, "if(userAge == 21) print...printf("You are 21 and able to drink.\n");"
    case 21:
        printf("You are 21 and able to drink.\n");
        break;

    case 18:
        printf("You are 18, an adult, but not able to drink.\n");
        break;

    // The default statement describes what happens where none of the above cases where true.
    default:
        printf("You are an age other than 21 or 18 ;)\n");
        break;
    }

    return 0;
}
```

### [Taking a Break](https://www.youtube.com/watch?v=BVmJ1NRvqQo)

A common question is, "Why is there a `break` statement in each of the `case` statemnts"?

- `break`: `break` says that we will jump out (or break out rather) of the current block of code.
- In a switch statement, after every case, once the code that we want to run runs, we don't want to run any other code in the block, so we break out of the block.
  - This may seem a bit un-intuitive, but essentially it comes down to "It's like that because the people who designed C decided it will be like that."
    - This is kind of a lame answer, but since the goal is to learn to use this tool, I'm just describing the features of the language.

## Takeaways

1. Use `if` statements to run code based on a condition.

## FAQs

### I don't understand what a condition is.

- A: A condition is something that evaluates to `true` or `false`

### Q: Why should I care about `if`?

- A: By itself, it is relatively insignificant, but later on, there are applications wherein knowing how to run code based on a condition is a very valuable skiil, most noatably when writing `loop`s.
