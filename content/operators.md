# Operators

## Arithmetic Operators

Arithmetic operators in C perform the same function as arithmetic operators in math.

### The `+, -, *, /` Operators

Just like in math, `+` adds two numbers, `-` subtracts the two numbers, `/` divides two numbers, and `*` multiplies two numbers

### The Mod Operator (`%`)

A (probably) new operator to you is the mod operator, denoted by `%` (the percent symbol). What this operator does is divide two numbers, and returns the remainder of the division.

- examples:
  - 5 % 2 is 1.
  - 3 % 3 is 0.
  - 2 % 3 is 2. Why?

#### Brief example of arithmetic operators

```c
int main()
{
    int a = 3;
    int b = 2;
    int c;

    c = a + b;
    c = a * b;
    c = a - b;

    // sets c to be 1.
    // Why?
    // In integer divison, the result is truncated. In english, it means that the remainder is tossed and only the whole number part is considered.
    // This has to do with the way integers are represented in C.
    // TL;DR: If you care about the remainder after division, use a `float` or a `double` instead of an int.
    c = a / b;

    // Sets c to be 1, because the remainder of a / b is 1.
    // Concretely, 3 % 2 is 1.
    c = a % b;

    return 0;
}
```

`+, - , /, *, %`

## Interlude: An Introduction to `if`

One of the tools you'll use often in C is the `if` statement. `if` checks if a statement is true.
Usage:

```c
#include <stdio.h>

int main()
{
    int blazeit = 420;

    // double equals sign checks for equality
    // (single equals was already taken for assignment)
    if(blazeit == 420)
        printf("NICE");

    // common way to check if a number is odd,
    //  essentially saying "divide blazeit by 2 and if the remainder of that operation is 0 (it divides evenly)", print out that c is even.
    if(blazeit % 2 == 0)
        printf("%d is even", blazeit);


    // Note the curly braces after this if statement.
    // We put the curly braces to denote that
    //  there will be more than one line of code executed depending on the if statement

    // My recommendation is to always put the curly braces
    if((blazeit / 10) == 420)
    {
        printf("420 / 10 equals 42.\n");
        printf("Coincedence? I think not.\n");
    }
}
```

## Relational Operators

### The `==` and `!=` Operators

- `==` checks that the first number is equal to the the second number

  - Q: Why 2 equal signs instead of just the one?
    - A: The single equal sign was already in use for assignment

- `!=` checks that the first number is **NOT** equal to the second number.

- _**COMMON MISTAKE**_: Using `=` instead of `==`
  - Remember, checking for equality requires **2** equal signs

### The `<` and `>` Operators

- `<` checks that the first number is less than the second number, `>` checks that the first number is greater than the second number.

### The `<=`and `>=` Operators

- `<` checks that the first number is less than or equal to the second number, `>` checks that the first number is greater than or equal to the second number.

## Brief example of relational operators

```c
#include <stdio.h>

int main()
{
    int bobsAge = 18;
    int majority = 18;
    int drinkingAge = 21;
    int rentalCarAge = 25;

    if(bobsAge >= majority)
    {
        printf("Bob is an adult");
    }

    if(bobsAge < drinkingAge)
    {
        printf("Bob cannot yet drink (legally).");
    }

    if(bobsAge != -1)
    {
        printf("Bob is alive.");
    }
}
```

## Logical Operators

### The `&&` and `||` Operators

- `&&` checks that condition 1 **AND** condition 2 is true.
- `||` checks that condition 1 **OR** condition 2 is true.
  - **NOTE**: `||` performs a "short circuit". Essentially, if condition 1 is true, condition 2 isn't even looked at.
    - Q: Why does that happen?
      - A: It is more efficient. If you only care about one or the other, why check both if the first satisfies your constraints?
  - the pipe key (`|`) is above the enter key on your keyboard

### The `!` Operator

- `!` flips the result of the condition being evaluated. Essentially, if `condition` is true, `!condition` is false, and vice-versa.

#### Brief example of logical operators

```c
#include <stdio.h>

int main()
{
    // Imagine you'll get a game if you have enough money and if you have significant (>= 7) interest
    int money = 0;
    int inerestInGame = 9;
    int gameCost = 60;

    // Expressing that idea in C
    if(money >= gameCost && interestInGame >= 7)
    {
        printf("I will buy game.");
    }

    // Next, imaine you'll get the game if you have enough money or
    //  if your mom is willing to get it for you
    int momsWillingness = 8;

    // NOTE: If the 1st part is true, the 2nd won't even be looked at.
    if(momsWillingness >= 7 || money >= gameCost)
    {
        printf("Will get this game");

        // This if statemenet explicitly checks whether you had enough money.
        if(money < gameCost)
        {
            printf("(bc mom will buy it for me)");
        }
    }
}
```

## Assignment Operators

### The `=`, `+=`, `-=`, `/=`, `%=` Operators

- Writing `a += 1` is synonymous with saying `a = a + 1`

  - Q: If they're the same, why are there 2 ways to do it?
    - A: The `+=` is shorter to write.
  - An even shorter syntax:
    - `a++` is used to increment a by one.

- The priciple above holds for `-=`, `*=`, and `/=`

#### Brief example of assignment operators

```c
#include <stdio.h>

int main()
{
    int a = 2;

    // The next 4 lines all produce the same result
    a = a + 1;
    a += 1;
    a++;
    ++a;

    // a is 6 since we incremented by 1 four times on the lines above
    printf("a is: %d\n", a);

    // Similarly, the next 4 lines all produce the same result
    a = a - 1;
    a -= 1;
    a--;
    --a;

    // What is the value of a now?
    printf("a is: %d\n", a);
}
```

## Bitwise Operators

### The `&` and `|` Operators

- `&` and `|` do a similar thing to `&&` and `||`, but on a bit by bit (bits as in binary) level.
  - 1 means true and 0 means false.
- `~` flips a bit to its inverse.
- `^` performs the following: `(A || B) && !(A && B)`, assuming A and B are both bits.

![Visual](https://4.bp.blogspot.com/-0KPDI41veH0/V-OtObm_UWI/AAAAAAAAAso/CkTS0zUMGKIjlE3gUD0fMhmp-B0zcfBmACLcB/s1600/Bitwise-truthtable-Javaform.jpg)

## Miscellaneous Operators

### The `sizeof()` operator

Gives the size (in bytes) of a datatype.

### The Address Operator (`&`)

Holds the address of a variable in memory.

### The Dereferencing Operator (`*`)

Points to an address of a variable in memory.

### The Ternary Operator (`?:`)

Shorthand statement for an if/else statement.

#### Example

```c
// Steeve Joseph
// An example of the ternary operator
#include <stdio.h>

void stringExample()
{
    // NOTE: A string is another data type
    //  pretty much anything in between double quotes is a string.
    // The conversion character for a string is "%s"
    printf("%s", "Hello world!");
}

int main(void)
{
    // This is a short example that illustrates strings in C.
    stringExample();

    int userAge;
    printf("Hello, please enter your age:\n");
    scanf("%d", &userAge);

    if (userAge >= 18)
        printf("You are an adult.\n");

    else
        printf("You are not an adult.\n");

    // This is extreme shorthand for the lines above.
    // Think of it like this:
    //   (condition) ? *code that should run if condition is true* : *code that should run otherwise*
    printf("%s", (userAge >= 18) ? "You are an adult" : "You are a minor");

    // Concretely:
    //   If the userAge is 18 and up, we print the first string.
    //   Else, we print the second.

    return 0;
}


```

## Operator Precedence

The operator precedende in C is similar to the one in math/science (PEMDAS).

![Operator Precedence Image](https://bit.ly/2mli9Nz)

## Takeaways

1. There a multitude of operators in C
   - Use arithmetic operators when doing some quick math
   - Use relational operators when looking for the way that two numbers compare
   - Use logical operators when looking for o
   - Use assignment operators as shortcuts for assigning values to variables/constants
