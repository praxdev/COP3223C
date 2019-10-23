# Strings

In computer science terminology, strings are a string of characters between quotes. "This is an example string". In C, strings are almost synonymous with character arrays.

## string.h

`string.h` is a library in C that performs certain operations with strings.

### Examples of Some Common String Functions

```c
// Steeve Joseph
// An example of some common string operations w/ string.h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// global variables: only for examples, pls don't do this
char h[] = "hello";
char w[] = "world";

// A temporary buffer
char temp[128];

void strcatEx();
void strlenEx();
void strcmpEx();
void strcpyEx();
void strtokEx();
void strstrEx();

int main()
{
    strcatEx();
    strlenEx();
    strcmpEx();
    strcpyEx();
    strtokEx();
    strstrEx();
    return 0;
}

void strcatEx()
{
    printf("function strcatEx:\n");

    char combined[128];

    // strcat(str1, str2) appends str2 to str1
    // str1 must have enough space to accomodate str2
    strcpy(combined, strcat(h, w));

    // Notice no space is printed, do you know why?
    printf("Output of strcat(\"%s\", \"%s\"): %s\n", h, w, combined);
    printf("\n");
}

void strlenEx()
{
    printf("function strlenEx:\n");

    // Getting the length of a string
    //  strlen() only counts the filled in characters of the char array
    //  (ignoring \0 and othe empty slots)
    printf("The length of %s is: %d\n", h, strlen(h));
    printf("\n");
}

void strcmpEx()
{
    printf("function strcmpEx:\n");

    // Comparing two strings
    // strcmp has the following syntax:
    // strcmp(str1, str2)
    // strcmp returns:
    //   * -1 if str1 < str2 (str1 comes before str2)
    //   * 1 if str1 > str2
    //   * 0 if str1 == str2
    // this in lexicographical order
    // so, the below prints -1
    printf("Output of strcmp(\"%s\", \"%s\"): %d\n", h, w, strcmp(h, w));
    printf("\n");
}

void strcpyEx()
{
    printf("function strcpyEx:\n");

    // If you need to set/change the value of a string, use strcpy()
    strcpy(temp, "steeve");
    printf("\n");
}

void strtokEx()
{
    printf("function strtokEx:\n");

    // Setup our string
    char str[] = "Hi, my name is <name>";

    // Set token equal to the first "word" (the piece before the first space)
    char *token = strtok(str, " ");

    int i = 0;

    // If token == NULL, we are at the end of the string
    while (token != NULL)
    {
        printf("Word number %d: %s\n", i++, token);

        // move on to the next token in the string
        // the first arg is NULL here to tell the compiler that we are using the same string as the last time
        token = strtok(NULL, " ");
    }

    printf("\n");
}

void strstrEx()
{
    printf("function strtokEx:\n");

    // strstr(haystack, needle) finds the first occurence of <needle> in <haystack>,
    // and returns the needle, followed by the rest of the string.

    char haystack[] = "find the needle in the haystack";
    char hs1[] = "no n33dl3 here";

    // printf "needle in the haystack"
    printf("%s\n", strstr(haystack, "needle"));

    // This prints <(null)>, why?
    // A: "needle" is not present in hs2, only "n33dl3" is
    // strstr(haystack, needle) returns null if needle is not found in haystack
    printf("<%s>\n", strstr(hs1, "needle"));

    char mim[] = "My favorite game is monkey in the middle.";

    // What does this print?
    printf("%s\n", strstr(mim, "monkey"));
}
```
