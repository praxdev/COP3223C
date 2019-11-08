# Pointers

One of the biggest tools you'll use in the C programming language is the pointer. For some, this is a bit of a slippery concept to grasp, even for senior software developers. Hopefully, explaining what a pointer is, and why you'd want to use one helps solidify the concept.

## What is A Pointer?

Recall your basic C [data types](https://www.tutorialspoint.com/cprogramming/c_data_types.htm). A pointer, in its simplest form, is a **reference** to an element of some data type.

### Analogy

What is a name?

When someone says/mentions your name, they are using your name to refer to the idea of you.

Maybe when they mention your name, your image pops into their mind, or they think of info associated to you (such as height, hair color, siblings, etc.).

Let's say you were 5'8", had brown hair, went to UCF, and liked Panic! At the Disco.

If someone were to ask their friend if they knew you, it'd be inefficient to have to mention those details each and every time. Instead, they could just ask, "Do you know <your name here>?"

### Another Analogy

Let's say you bought some furniture from me and you need to pick it up from my store. It wouldn't make sense for me to describe every detail of my store just so you can pick up a couch or something. I'd just give you the address. The address in this example plays the same role that a pointer plays. The address **refers** to where my store is.

### Pointer Etymology

The reason a pointer has its name is because it **POINTS** to an address where some data is being held.

## A Pointer's Purpose

A common sticking point to learning a tool is knowing _when_ or _why_ to use it. If you've used functions in C, you may have noticed you can pass variables to functions either **by reference** (using a pointer) or **by value** (passing a copy of the data).

### A Big Question

Passing by value seems more intuitive, so why would I ever go through the effort of learning pointers so I can pass by reference?

### A (Somewhat) Fulfilling Answer

Efficiency.

Imagine you declared an array of 1024 elements, maybe the array represents sutdent grades, for example. Let's say you wanted to update **one** grade in that array.

If you were passing by value, the OS would make a copy of all 1024 student grades, pass it into the function, make the modification, and pass the entire array back to the calling function.

If you were passing by reference, all you'd be doing is telling the OS _where_ the array is in memory, and when the function is called, the function would access the array directly and make the update. No need to copy all that data over.

### An Analogy

Let's say that I was hiring a painter to paint the inside of my house.

I _could_ construct a complete replica of my house, deliver it to the painter, have him paint the replica, and have him deliver the replica back to me. From that point on, I will refer to the replica as my house. I _could_ do that, but why would I?

Instead, what I'd _actually_ do is tell the painter where I live (give him my address), and let him in to paint the interior of my house. This is objectively easier and less expensive, and that's why I chose that option.

In this analogy, pass by value is the first method, pass by reference (via pointers) is the second.

I use the painter and the house analogy because it is very likely that at some point you'll be working with very large pieces of data, that represent real-world things, and it'll be imperative that you do efficient work.

## Pointer Declaration & Dereferencing

### Example

```c
// Steeve Joseph
// A basic example of pointers.
#include <stdio.h>

int main()
{
    int num = 420;

    // syntax for declaring a pointer:
    // data_type *pointer_name = <a memory address>
    int *numPtr = &num;

    // Regular variable printing
    printf("The value of num is: %d\n", num);

    //Printing the value of numPtr
    printf("The memory address of numPtr is: %x\n", numPtr);

    // Printing the contents of numPtr.
    printf("The contents of numPtr is: %d\n", *numPtr);
}
```

### Explanation

In our main(), the first thing we do is declare `num` and set it to 420 (nice). The next line of code **declares** a pointer. Remember that the `&` translates to "address of", so we are setting the value of numPtr to be the address of num. Pointers hold memory addresses.

## The Ampersand
The ampersand operator (&) is used when passing the address of 

## The Star
The start operator is **overloaded**, as in, it's meaning is a bit different depending on _where_ it is used. There are 3 main cases where you'll use the star.

### Declaration
During declaration, the `*` indicates the declaration of a pointer to a data type.

### In Function Signature
In the function signature, `*` indicates a pointer to a data type will be acceo

### Everywhere Else
In most other places you use `*`, the star loosely translates to, "contents of".

### Illustration
```c
// Steeve Joseph
// An example of using pointers.
#include <stdio.h>

void swap(int *a, int *b);

int main() 
{
    int a = 68, b = 419;

    // the star here indicates ptr will be a POINTER to an int.
    int *ptr = &a;


    printf("a is: %d, b is: %d\n", a, b);
    
    // pass the addresses of a and b to our swap function.
    // remember that if we just passed the values of a and b, 
    // a copy of them would be made in the function, and then destroyed when the 
    // function ends.
    swap(&a, &b);
    
    printf("a is: %d, b is: %d\n", a, b);

    return 0;
}


// The star operator here indicates that POINTERS to ints will be accepted as arguments.
void swap(int *a, int *b)
{
    int temp;

    // the star here translates loosely to "the contents of"
    temp = *a;

    // set the contents of a to the contents of b.
    *a = *b;

    // set the contents of b to temp.
    *b = temp;    
}
```
