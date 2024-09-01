#include <stdio.h>

// Function declarations
void passByValue(int val);
void passByReference(int &ref);
void passByPointer(int *ptr);

int main()
{
    int x = 5;

    // Print the initial value and memory address of 'x'
    printf("Initial x = %i, Address of x = %p\n", x, (void *)&x);

    // Call passByValue
    passByValue(x);
    printf("After passByValue, x = %i, Address of x = %p\n", x, (void *)&x);

    // Call passByReference
    passByReference(x);
    printf("After passByReference, x = %i, Address of x = %p\n", x, (void *)&x);

    // Call passByPointer
    passByPointer(&x);
    printf("After passByPointer, x = %i, Address of x = %p\n", x, (void *)&x);

    return 0;
}

void passByValue(int val)
{
    // Print the value and address of 'val' (which is a copy)
    printf("Inside passByValue, val = %i, Address of val = %p (copy of x)\n", val, (void *)&val);
    val = 10;
    printf("Inside passByValue after change, val = %i, Address of val = %p\n", val, (void *)&val);
}

void passByReference(int &ref)
{
    // Print the value and address of 'ref' (which is the same as 'x')
    printf("Inside passByReference, ref = %i, Address of ref = %p (same as x)\n", ref, (void *)&ref);
    ref = 20;
    printf("Inside passByReference after change, ref = %i, Address of ref = %p\n", ref, (void *)&ref);
}

void passByPointer(int *ptr)
{
    // Print the value pointed to by 'ptr' and the address 'ptr' holds (which is the address of 'x')
    printf("Inside passByPointer, *ptr = %i, Address of *ptr = %p, Address of ptr = %p\n", *ptr, (void *)ptr, (void *)&ptr);
    *ptr = 30;
    printf("Inside passByPointer after change, *ptr = %i, Address of *ptr = %p, Address of ptr = %p\n", *ptr, (void *)ptr, (void *)&ptr);
}
