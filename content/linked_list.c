// Steeve Joseph
// A demo of linked lists in C.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIST_SIZE 5

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *createNode(int data);

Node *insertBack(Node *head, int data);
Node *removeBack(Node *head);

Node *insertFront(Node *head, int data);
Node *removeFront(Node *head);

void printArray(int *arr, int size);

int countNodes(Node *head);
void printList(Node *head);

int main()
{
    int i;
    int arr[LIST_SIZE];
    Node *head = NULL;

    // making an array of range [0, 9]
    for (i = 0; i < LIST_SIZE; i++)
    {
        arr[i] = i;
    }

    printArray(arr, LIST_SIZE);

    // making a linked list od the same range
    for (i = 0; i < LIST_SIZE; i++)
    {
        head = insertBack(head, i);
    }

    printf("The list from 0 -> %d:\n", LIST_SIZE);
    printList(head);

    // remove the last half the elements in the list
    for (i = LIST_SIZE / 2; i < LIST_SIZE; i++)
    {
        head = removeBack(head);
    }

    printf("The list after removing the back half:\n");
    printList(head);

    for (i = 99; i < 101; i++)
    {
        head = insertFront(head, i);
    }

    printf("The list after inserting 99 and 100 in the front:\n");
    printList(head);

    for (i = 0; i < 2; i++)
    {
        head = removeFront(head);
    }

    printf("The list after removing 99 and 100 from the front:\n");
    printList(head);

    return 0;
}

/**
 * A utility function for printing a visual representation of an array.
 * 
 * @param arr The pointer to the array to traverse.
 * 
 * @param size The size of the array.
*/
void printArray(int *arr, int size)
{
    int i;

    printf("\nArray: [");
    for (i = 0; i < size; i++)
    {
        printf("%d", arr[i]);

        if (i == (size - 1))
        {
            printf("");
        }
        else
        {
            printf(", ");
        }
    }

    printf("]\n\n");
}

/**
 * Creates a node for a linked list.
 * 
 * @param data The int that will be inserted into the list
 * 
 * @returns A pointer to the head of the list.
 */
Node *createNode(int data)
{
    Node *n;
 
    // Memory ALLOCation for 1 node, make n point to the allocated memory
    n = malloc(sizeof(Node));

    // if n is null, malloc() failed :( (rarely happens)
    if (n == NULL)
    {
        fprintf(stderr, "ERROR! Cannot allocate memory for node! Quitting!\n");
        exit(1);
    }

    // Set the data field.
    n->data = data;
    n->next = NULL;

    // return the new node.s
    return n;
}

/**
 * Inserts a node at the end of the line.
 * 
 * @param head The head of the list.
 * 
 * @param data The int that will be inserted into the list
 * 
 * @returns A pointer to the head of the list.
*/
Node *insertBack(Node *head, int data)
{
    Node *tmp;

    // If the list is empty, make a new node and return it.
    if (head == NULL)
    {
        head = createNode(data);
        return head;
    }

    tmp = head;

    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }

    //  ----     -----     -----
    // | a  | => | b  | => | c  |  => NULL
    //  ----     ------    -----
    //                       ^   
    //                we are here (tmp)

    // Set c's next pointer to a new node.
    //  (the new node's next pointer will be NULL, due to how createNode() is defined).
    tmp->next = createNode(data);
    
    
    // List after insertion:
    //  ----     -----     -----      ------
    // | a  | => | b  | => | c  |  => | d  | => NULL
    //  ----     ------    -----      ------

    return head;
}


/**
 * Prints a graphical representation of the current state of the list.
 * 
 * @param head The head of the list.
*/
void printList(Node *head)
{
    Node *tmp;
    int numNodes = countNodes(head);
    int i;

    if (head == NULL)
    {
        printf("\n\n(empty list)\n\n");
        return;
    }

    tmp = head;

    // Make the tops of the boxes.
    for (i = 0; i < numNodes; i++)
        printf("--------     ");

    printf("\n");

    // Make the contents of the boxes.
    for (i = 0; i < numNodes; i++)
    {
        printf("|  %-3d | ->  ", tmp->data);
        tmp = tmp->next;
    }

    printf("NULL\n");

    // Make the bottoms of the boxex.
    for (i = 0; i < numNodes; i++)
        printf("--------     ");

    printf("\n\n");
}


/**
 * Counts the number of nodes in the list.
 * 
 * @param head The firs node of the list.
 * 
 * @returns An int representing the number of nodes in the list 
 * 
*/
int countNodes(Node *head)
{
    Node *tmp;
    int count = 0;

    tmp = head;

    // While we aren't at the end of the list.
    while (tmp != NULL)
    {
        // Increment count, and move tmp down the line.
        count++;
        tmp = tmp->next;
    }

    // NOTE: if head was NULL from the beginning, count will be 0.
    return count;
}

/**
 * Removes a node from the end of the list.
 * 
 * @param head The first node of the list.
 * 
 * @returns The head of the list.
*/
Node *removeBack(Node *head)
{
    Node *tmp;

    // If the list is empty, or there's only one node, return an empty list.
    if (head == NULL || head->next == NULL)
        return NULL;


    tmp = head;

    //  ----     -----     -----
    // | a  | => | b  | => | c  |  => NULL
    //  ----     ------    -----
    //  ^          ^         ^
    // tmp       tmp->next  tmp->next->next
    while (tmp->next->next != NULL)
    {
        tmp = tmp->next;
    }


    //  ----     -----     -----
    // | a  | => | b  | => | c  |  => NULL
    //  ----     ------    -----
    //             ^   
    //         we are here (tmp)

    // Deallocate/destroy C
    free(tmp->next);


    // Current list:
    //  ----     -----     
    // | a  | => | b  |  => NULL
    //  ----     ------    
    //             ^   
    tmp->next = NULL;

    return head;
}


/**
 * Inserts a value at the beginning of the list (data becomes the new head)
 * 
 * @param head The first node in the list.
 * 
 * @param data The new value.
 * 
 * @returns The new head of the list.
*/
Node *insertFront(Node *head, int data)
{
    Node *new;

    // If the list is empty, make a new node and return it.
    if (head == NULL)
    {
        return createNode(data);
    }

    new = createNode(data);
    
    // Make new's next pointer point to head.
    new->next = head;

    // Assign new as the head of the list.
    head = new;

    return head;
}



/**
 * Removes a value from the beginning of the list
 * 
 * @param head The first node in the list.
 * 
 * @returns The new head of the list.
*/
Node *removeFront(Node *head)
{
    Node *tmp;


    // If the list is empty, return NULL
    if (head == NULL)
    {
        return NULL;
    }


    // Hold on to the head of the list.
    tmp = head;

    // Make the 2nd node the new head of the list.
    head = head->next;

    // De-allocate the memory for the old head.
    free(tmp);

    return head;
}