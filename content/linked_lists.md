# Linked Lists
A linked list, in essence, is a list of data strung together with pointers.

## Consider the (static) Array
So far, arrays have been sufficient for cases when we need a collection of data of the same type. However, there are a couple of cases where arrays may not be the best tool to use.

Some features of the Array:
1. The array size needs to be declared at compile time.
2. Arrays are a static (unchanging) size.
3. Arrays are contiguous blocks of memory.

The above aren't necessarily good or bad things, they are just facts. There are some limitations that come from them though.


### Example 1
What happens if we (the programmers) don't know what size the array should be when writing the code? We could always guess, right?

#### Case 1: Guess too high
If we guess a size that's huge, we could reason that the user will never enter enough data to fill the array completely, though this comes with the potential of wasting excess memory.

- e.g. We declare `char name[128]`, but the average name is 7-9 chars.

#### Case 2: Guess too low
Another example, what if we guess a size that's reasonable, based on what we know about our data? Unfortunately, this breaks when we reach edge cases/anomalies in our data.

- e.g. We declare `char name[10]`, but the user's name is "Jean-Pierre".

#### ~~Case 3: Guess just right~~
Forget about this case, it is practically impossbile to consistently guess how much space a user will need.


### Example 2
What if we need to change the size of the array after declaring it? For example, what if we need to double the size of the array at some point during program execution?

For this, we would have to make a new array that is double the size of the first array, copy over all the elements. This is a very expensive process computationally, and we'd like to avoid it if possible.


### Example 3
What if our array is just too dang big? 
- For example, what if wanted to represent the population of the human race in 2019, around 7.5 billion people? 
  - Theoretically, we could create a huge array to hold all that data, but practically speaking, this is not an option. 

Specifically, let's say we were using just an int in each cell. 
- Remember that an int is 4 bytes, and for a 7 billion elemens, we'd need 28 gigabytes worth of memory. 
  - This in itself isn't an issue, but one of the core features of an array is that it is comprised of a contiguous block of memory. 
  - Even if we had a PC w/ 32 GB of memory, it is extremely unlikely that we'll have 28 GB of free memory in a row. 

## A New Option: the Linked List
A linked list is a collection of nodes strung together with pointers. Each node is comprised of a piece of data, and a pointer to the next node in the list. The last node points to `NULL`, because we need to know when we are at the end of the list.

### A Bird's Eye View of a Linked List
![](https://media.geeksforgeeks.org/wp-content/uploads/singly-linkedlist.png)

### A Cross Section of Two Links
![LL](https://visualgo.net/img/ll_illustration.png)


## No Free Lunch: Drawbacks of the Linked List
Although we gain some flexibility from using a linked list over an array, that comes at the cost of some of the features that the array does really well, namely:
- no random access
  - i.e. we can't do `linkedListName[someNumber]`
  - instead, if we want to access an element, we must start at the head and traverse the list until we get to the data we are looking for.

## Common Linked List Operations
1. Creating a new node.
2. Adding a node to the end of the list.
3. Removing a node from the end of the list.
4. Adding a node to the front of the list.
5. Removing a node from the front of the list.

## Cowboy Coding
[Here](https://repl.it/repls/OlivedrabFamiliarHertz) is a full coding sample (w/comments) showing off linked lists