# Arrays

An array is a collection of elements of the same type. Previously, you may have declared 3 individual `int`s to hold 3 individual integer pieces of data. Similarly, if you wanted to have ONE variable/reference to those pieces of data, you'd use an array.

### An Example Using an Integer Array

```c
// Steeve Joseph
// An example of arrays.
#include <stdio.h>

#define ARRAY_SIZE 3

int main()
{

    // So, you could declare 3 ints, and perform some operation on them one by one.
    int i = 0, j = 1, k = 2;

    printf("Using 1-by-1 var printing:\n");
    printf("%d -> %d -> %d -> %s\n", i, j, k, "END");

    // Alternatively, if the data type is the same among variables, you could declare
    // an array and loop through it performing some operation on each element of the array.

    // Array declaraction syntax:
    // data_type array_name[ size_of_array ];
    int a[ARRAY_SIZE];

    // Initializing array values.
    // This is important bc, when an array is declared, there still may be garbage values in the cells of the array.
    // (C doesn't always clear out the values in the cells; the behavior is architecture dependent)
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        a[i] = i;
    }

    printf("\nPrinting out elements of array:\n");

    // printing all array vals.
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        printf("%d -> ", a[i]);

        if (i == ARRAY_SIZE - 1)
            printf("END\n");
    }

    return 0;
}
```

### Explanation

- `int a[3]` declares a new integer array of length 3.
- The position of an individual element in an array, called the **index**, is referred to by the brackets `[]`.
  - Array indices start at 0, and end at one less than the size of the array.
  - So, the valid indices for `a` are 0, 1, and 2 (`ARRAY_SIZE` is a constant set to 3).

## So What?

Common questions after learning about arrays are, "Why would I choose to use an array?" In the example above, since you only had a need for 3 `int`s, it may seem trvial to use another tool when the 3 variables worked just as well. I think this is a valid point, since tou are learning to use tools of the C language.

That being said, there are certain applications where arrays make more sense to use.

## Strings

One of the main uses for arrays in C are used in strings. A string, in simplest terms, is a character array.

### Example

```c
// Steeve Joseph
// An example of strings/character arrays.
#include <stdio.h>

// Note: I was trying to keep this short. If you're wondering "how do I know this actually works?"
//  you can:
//    1. Paste the code here: https://repl.it/languages/c,
//    2. Modify the code to loop through the arrays, printing each element
//  not a hard requirement, but this goes a long way to "proving" this to yourself.
int main()
{
    // what are the valid indices for `name`?.
    char name[16];

    printf("Please enter your name:\n");
    scanf("%s", &name);
    printf("Hi, %s!\n", name);

    // printing out `name` character by character (or element by element, in the array sense).
    int i;
    for (i = 0; i < 16; i++)
    {
        printf("name[%d]: %c\n", i, name[i]);
    }

    // Q: wth just happened above?
    // A: You've ran into the null-terminator, congratulations.

    return 0;
}
```

### Explanation

- `char name[16]` declares a char array/string (will be used synonymously when using C), with valid indices 0-15.
- `scanf("%s", &name);` reads the user input into the variable `name`. Note: the ampersand isn't actually needed here in this case.

## Null Terminator

- If you ran the code above, you may notice that if the name you entered is fewer than 16 characters, some weird values get printed out to the console.

- This is because in C, there is a character called the **null terminator** that tells the string where it is supposed to end.

This is what happens on my end when I run the code above

![string error](https://i.imgur.com/hqydspO.png)

"steeve" takes up the indices 0-5, and name[6] is reserved for the null-terminating character, a backslash 0 `\0`.

Basically, since the loop runs past the size of the array, and the behavior (e.g. what gets printed out) is undefined and garbage values in memory are (potentially) printed out.

### How Does This Affect Me

Since the last character of a string is reserved for the null terminating character, when you declare a string in C, account for one extra character.

So, if I knew I was going to enter in the name "steeve":

```c
int name[7] = {'s', 't', 'e', 'e', 'v', 'e'};

// Somewhere in memory is something like this:
+-----+-----+-----+-----+-----`+-----+------+
| 's' | 't' | 'e' | 'e' | 'v'  | 'e' | '\0' |
+-----+-----+-----+-----+-----`+-----+------+
```

## Inline Array Declaration

If you know what you want your array to "look like" at the time of declaration, you can declare it inline.

### Example

```c
// Steeve Joseph
// An example of inline array declaration.
#include <stdio.h>

// Note: I was trying to keep this short. If you're wondering "how do I know this actually works?"
//  you can:
//    1. Paste the code here: https://repl.it/languages/c,
//    2. Modify the code to loop through the arrays, printing each element
//  not a hard requirement, but this goes a long way to "proving" this to yourself.
int main()
{
    // Declaring, then initializing.
    int a[5];
    for (int i = 0; i < 5; i++)
        a[i] = i + 1;

    // Declaration + initialization, in one swoop.
    int b[5] = {1, 2, 3, 4, 5};

    // An alternative approach to the above; this does the same thing.
    int c[] = {1, 2, 3, 4, 5};
    return 0;
}
```
