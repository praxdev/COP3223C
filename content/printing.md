# Printing in C

## C Data Types

| Data type | Used for                              | Similar Types   |
| --------- | ------------------------------------- | --------------- |
| `int`     | integers (whole numbers)              | `short`, `long` |
| `char`    | characters (single letter/number/etc) | N/A             |
| `double`  | numbers with a decimal component      | `float`         |

### Similar Types?

The data types in the **Similar Types** column usually serve the same purpose, but the upper and lower bounds on the type is different.

- For example, the valid values for an `int` are [-2^31, 2^31-1] (interval notation).
  - A `short` on the other hand has a valid range of [-2^15, 2^15-1]

[This page](https://www.geeksforgeeks.org/data-types-in-c/) has a really good explanation of data types and their data limits.

## Printing

Printing in C is relatively simple

```c
#include <stdio.h>

int main()
{
    printf("Hello world");
    return 0;
}
```

Basically, all you need to know from the above is that the library `stdio.h` needs to be included (that is where `printf()` is defined), and that printf() takes in a string (words between quotes) and prints it out.

## format specifiers

You may be wondering why printf has the f at the end. This is because `printf` prints _formatted_ output. What this means is that you can print variables, along with [hardcoded](https://stackoverflow.com/a/1895803) strings.

### Example

```c
#include <stdio.h>

int main()
{
    int favNumber = 420;
    printf("My favorite number is: %d", favNumber);
    return 0;
}
```

- The above code prints out, "My favorite number is: 420".
- `%d` is something called a format specifier.
  - Basically, what %d is saying is, "Hey, when this program runs, take whatever is held by `favNumber` and put it here"

### Notes:

- %d is the format specifier for an int.

### Chart of Common format Specifiers

| Data type | format specifier |
| --------- | ---------------- |
| int       | %d               |
| char      | %c               |
| float     | %d               |
| double    | %lf              |

## Escape Sequences

Sometimes in `printf()`, you'll need to print a special character out to the screen. Say you wanted to print out a quote from a famous author, for example:

```c
    printf("" There is no truth, there is only perception " - WB DuBois");
```

The line above won't actually work.

- If you are viewing this online, you may notice the colors are a bit...off.
  - This is because the double quote is a special character in C, and the compiler doesn't know which double quotes to print and which ones to ignore. To remedy these cases, we use **escape sequences**.

| Sequence | Meaning       |
| -------- | ------------- |
| `\n`     | new line      |
| `\t`     | tab character |
| `\\`     | backslash     |
| `\'`     | single quote  |
| `\"`     | double quote  |

Therefore, the correct way to print the quote is:

```c
    printf("\"There is no truth, there is only perception \" - WB DuBois");
```
