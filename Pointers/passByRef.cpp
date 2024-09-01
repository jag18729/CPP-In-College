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
    printf("Initial State:\n");
    printf("Memory Address of x: %p\n", (void *)&x);
    printf(" ┌───────────┐\n");
    printf(" │  x = %i   │ <─── x\n", x);
    printf(" └───────────┘\n");
    sleep(3);

    // Call passByValue
    printf("\nCalling passByValue(x):\n");
    passByValue(x);
    sleep(3);

    // Call passByReference
    printf("\nCalling passByReference(x):\n");
    passByReference(x);
    sleep(3);

    // Call passByPointer
    printf("\nCalling passByPointer(&x):\n");
    passByPointer(&x);
    sleep(3);

    // Final comparison
    printf("\nFinal Comparison of x:\n");
    printf(" ┌──────────────┬───────────────┬──────────────────┬──────────────────┐\n");
    printf(" │ Initial x    │ After passByValue │ After passByReference │ After passByPointer │\n");
    printf(" ├──────────────┼───────────────┼──────────────────┼──────────────────┤\n");
    printf(" │   %i         │       %i        │       %i            │       %i            │\n", 5, 5, 20, 30);
    printf(" └──────────────┴───────────────┴──────────────────┴──────────────────┘\n\n");
    sleep(5);

    return 0;
}

void passByValue(int val)
{
    printf("Inside passByValue:\n");
    printf(" ┌────────────┬─────────────┐\n");
    printf(" │  x = %i     │  val = %i   │\n", 5, val);
    printf(" ├────────────┼─────────────┤\n");
    printf(" │  %p  │  %p   │ <── val (copy of x)\n", (void *)&val, (void *)&val);
    printf(" └────────────┴─────────────┘\n");
    printf(" val has a different address from x\n");
    sleep(3);

    val = 10;
    printf("After modifying val inside passByValue:\n");
    printf(" ┌────────────┬─────────────┐\n");
    printf(" │  x = %i     │  val = %i   │\n", 5, val);
    printf(" ├────────────┼─────────────┤\n");
    printf(" │  %p  │  %p   │ <── val (modified copy)\n", (void *)&val, (void *)&val);
    printf(" └────────────┴─────────────┘\n");
    printf(" x remains unchanged because val is just a copy.\n\n");
    sleep(3);
}

void passByReference(int &ref)
{
    printf("Inside passByReference:\n");
    printf(" ┌────────────┬─────────────┐\n");
    printf(" │  x = %i     │  ref = %i   │\n", 5, ref);
    printf(" ├────────────┼─────────────┤\n");
    printf(" │  %p  │  %p   │ <── ref (alias of x)\n", (void *)&ref, (void *)&ref);
    printf(" └────────────┴─────────────┘\n");
    printf(" ref has the same address as x\n");
    sleep(3);

    ref = 20;
    printf("After modifying ref inside passByReference:\n");
    printf(" ┌────────────┬─────────────┐\n");
    printf(" │  x = %i    │  ref = %i   │\n", 20, ref);
    printf(" ├────────────┼─────────────┤\n");
    printf(" │  %p  │  %p   │ <── ref (modified x)\n", (void *)&ref, (void *)&ref);
    printf(" └────────────┴─────────────┘\n");
    printf(" x is changed because ref is an alias to x.\n\n");
    sleep(3);
}

void passByPointer(int *ptr)
{
    printf("Inside passByPointer:\n");
    printf(" ┌────────────┬───────────────┬───────────────┐\n");
    printf(" │   *ptr     │    ptr        │   &ptr        │\n");
    printf(" ├────────────┼───────────────┼───────────────┤\n");
    printf(" │   %i       │   %p   │   %p  │ <── ptr points to the address of x\n", *ptr, (void *)ptr, (void *)&ptr);
    printf(" └────────────┴───────────────┴───────────────┘\n");
    sleep(3);

    *ptr = 30;
    printf("After modifying *ptr inside passByPointer:\n");
    printf(" ┌────────────┬───────────────┬───────────────┐\n");
    printf(" │   *ptr     │    ptr        │   &ptr        │\n");
    printf(" ├────────────┼───────────────┼───────────────┤\n");
    printf(" │   %i       │   %p   │   %p  │ <── *ptr now holds the modified value at x's address\n", *ptr, (void *)ptr, (void *)&ptr);
    printf(" └────────────┴───────────────┴───────────────┘\n");
    sleep(3);
}
