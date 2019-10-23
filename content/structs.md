# Structures (WIP)
In C, a structure, or `struct`, as it's referred to when writing the code, gives us the ability to define a custom data type.

# Example
```c
// Steeve Joseph
// An example of using structs, and struct pointers.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// A new keyword in C: typedef
// Similar to #define, typefed allows you to define  (alias) a data type
// From now on, myFavoriteData can be used where int would be used.
typedef int myFavoriteData;

// using typedef on a struct so that we can
// initialize with "Student" instead of "struct Student"
typedef struct Student
{
    char name[128];

    // long is a an integer with a higher max value.
    long ID;
    double GPA;
} Student;


void printStudent(Student *stud);
Student *createStudent(char *name, long ID, double GPA);


int main(void)
{
    // This is the declaration of a student.
    // If you did "int i", int would be the data type, i would be the variable name
    // Here, "struct Student" is the data type, s0 is the variable name
    struct Student s0;

    // Because we did typedef'd struct Student up above, we can omit the struct keyword and 
    // just use Student to declare.
    Student s1;


    // Initializing s1's fields
    // A field of a struct can be accessed with dot (.) notation
    // struct_name.struct_field
    strcpy(s1.name, "First Last");
    s1.ID = 1010;
    s1.GPA = 2.75;


    // Create a Student pointer. 
    // Using a pointer here gives us flexibility in our operations.
    // For example, the Student is created in another function, and we can reference it in main()
    // This allows us to export work out to a function and keep main() clean and legible; 
    Student *steeve;

    // Create student returns a pointer to a Student.
    steeve = createStudent("Steeve Joseph", 420, 3.8);
        
    // Print out the info for steeve.
    printStudent(steeve);

    return 0;
}

// Create a student
//
// Params:
//   1. A string that represents the students name
//   2. A long representing the ID
//   3. A double representing the GPA
//
// Returns: A pointer to a struct that represents the newly created student.
Student *createStudent(char *name, long ID, double GPA)
{
    // Usually when we declare a variable in a function, that variable is destroyed once the 
    // function ends.

    // Since we what this variable accessible outside the function
    // We use malloc() to allocate memory for stud.
    // such that stud can be "permanently" stored.
    Student *stud =  malloc(sizeof(Student));


    // Whoa whoa whoa, what's with the arrows here?
    //   So, normally, with a struct, you access the struct's fields with struct_name.struct_field
    //   However, with a struct pointer, you'd use (*struct_name).struct_field

    // Instead of doing all those keystrokes, a shortened syntax is the arrow operator.
    // So, (*struct_name).struct_field is synonymous with struct_name->struct_field.
    strcpy(stud->name, name);
    stud->ID = ID;
    stud-> GPA = GPA;

    return stud;
}

void printStudent(Student *stud)
{
    printf("\n");
    printf("Student name: %s\n", stud->name);
    printf("Student ID: %ld\n", stud->ID);
    printf("Student GPA: %lf\n", stud->GPA);
    printf("\n");
}



```