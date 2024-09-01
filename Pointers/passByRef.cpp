#include <stdio.h>
#include <unistd.h> // For the sleep function

// Function declarations
void passByValue(int val);
void passByReference(int &ref);
void passByPointer(int *ptr);

int main()
{
    int x = 5;

    // Initial state of 'x'
    printf("Initial x:\n");
    printf("Memory Address: %p\n", (void *)&x);
    printf(" ┌──────────┐\n");
    printf(" │   %i    │ <── x (Original Value)\n", x);
    printf(" └──────────┘\n\n");
    sleep(3);

    // Call passByValue
    printf("Calling passByValue(x):\n");
    printf("Passing a COPY of x to the function...\n\n");
    sleep(3);
    passByValue(x);
    sleep(3);

    // Call passByReference
    printf("Calling passByReference(x):\n");
    printf("Passing a REFERENCE to x, so the function can change its value...\n\n");
    sleep(3);
    passByReference(x);
    sleep(3);

    // Call passByPointer
    printf("Calling passByPointer(&x):\n");
    printf("Passing the ADDRESS of x using a pointer, so the function can change its value...\n\n");
    sleep(3);
    passByPointer(&x);
    sleep(3);

    // Final comparison
    printf("Final Comparison of x:\n");
    printf(" ┌──────────────┬───────────────┬───────────────┐\n");
    printf(" │ Initial x    │ After passByValue │ After passByReference │ After passByPointer │\n");
    printf(" ├──────────────┼───────────────┼───────────────┼───────────────┤\n");
    printf(" │   %i        │       %i       │       %i       │        %i        │\n", 5, 5, 20, 30);
    printf(" └──────────────┴───────────────┴───────────────┴───────────────┘\n\n");
    sleep(5);

    return 0;
}

void passByValue(int val)
{
    printf("Inside passByValue:\n");
    printf("Memory Address: %p\n", (void *)&val);
    printf(" ┌──────────┐\n");
    printf(" │   %i    │ <── val (Copy of x)\n", val);
    printf(" └──────────┘\n\n");
    sleep(3);

    val = 10;
    printf("Modifying the COPY of x (val):\n");
    printf("Memory Address: %p\n", (void *)&val);
    printf(" ┌──────────┐\n");
    printf(" │   %i    │ <── val (Modified Copy)\n", val);
    printf(" └──────────┘\n\n");
    sleep(3);

    printf("Notice how x itself is not affected by this change, because only a copy was passed.\n\n");
    sleep(3);
}

void passByReference(int &ref)
{
    printf("Inside passByReference:\n");
    printf("Memory Address: %p\n", (void *)&ref);
    printf(" ┌──────────┐\n");
    printf(" │   %i    │ <── ref (Same as x)\n", ref);
    printf(" └──────────┘\n\n");
    sleep(3);

    ref = 20;
    printf("Modifying the value of x through the REFERENCE (ref):\n");
    printf("Memory Address: %p\n", (void *)&ref);
    printf(" ┌──────────┐\n");
    printf(" │   %i    │ <── ref (Modified x)\n", ref);
    printf(" └──────────┘\n\n");
    sleep(3);

    printf("Notice how x itself is now modified, because a reference to x was passed.\n\n");
    sleep(3);
}

void passByPointer(int *ptr)
{
    printf("Inside passByPointer:\n");
    printf("Pointer Address: %p\n", (void *)&ptr);
    printf("Points to Address: %p\n", (void *)ptr);
    printf(" ┌──────────┐\n");
    printf(" │   %i    │ <── *ptr (Value at Address)\n", *ptr);
    printf(" └──────────┘\n\n");
    sleep(3);

    *ptr = 30;
    printf("Modifying the value of x through the POINTER (*ptr):\n");
    printf("Pointer Address: %p\n", (void *)&ptr);
    printf("Points to Address: %p\n", (void *)ptr);
    printf(" ┌──────────┐\n");
    printf(" │   %i    │ <── *ptr (Modified Value at Address)\n", *ptr);
    printf(" └──────────┘\n\n");
    sleep(3);

    printf("Notice how x is modified by changing the value at its memory address via the pointer.\n\n");
    sleep(3);
}
