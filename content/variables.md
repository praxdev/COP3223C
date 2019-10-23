# Variables, Constants and Literals

In short, variables are references to values in memory.

## Available Data Types in C

- Remember there are a variety of data types in C. I like to describe them as integer types and floating point types.

## Constants in C

- Constants are values in memory. Constants (typically) don't change when they are declared. They have the same data types as variables in C.

Constants are typically written like so:

```c
// single word constant (approximation of PI)
const float PI = 3.14;

// using 1 billion as "infinity", oo kinda looks like the lemniscate (∞)
const double oo = 1e9;

// constant that has multiple words
const char[] MY_FAVORITE_QUOTE = "I am the greatest";
```

## The Beautiful `#define`

There is another way to define constants in C, using the `#define` [preprocessor directive](https://www.reddit.com/r/learnprogramming/comments/1lz0z0/please_eli5_the_preprocessor_the_compiler_and_the/cc46f13?utm_source=share&utm_medium=web2x).

- Basically, if you have `#define NICE 420`, what'll happen is that when you run your program, every instance of `NICE` in your code will be replaced by the value 420 (obligatory blaze it).

- `#define` typically indicates global constants.

## Constants using `const` vs constants using `#define`

- When do I know which to use?
  - A good rule of thumb is to use `#define` for a global value that won't change.
    - Why?
      - When you write larger programs (that span multiple files), you can easily write all your `#define`s (hundreds of constants) in a header file (.h extension), and use one line to import all your
  - Personally, I have not been in a situation where I needed to use `const` in C

* Defining a constant w/ `#define` doesn't have the equal sign, the syntax for it is `#define NAME VALUE`
* Mildly interesting:
  - when `const float PI = 3.14;` is used, the OS, at runtime, keeps accessing the memory locations where the `PI` is located, at each use.
  - when `#define PI 3.14` is used, the preprocessor literally does a find and replace for "PI" and puts 3.14 there, which is a bit more efficient than having the processor access a memory location during runtime.
