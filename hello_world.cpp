#include <iostream>
using namespace std;

int main()
{
    cout << "Hello, World!";
    return 0;
}

// Output: Hello, World!
```

    ##2. C++ Variables
        A variable is a name given to a memory location.It is the basic unit of storage in a program.The value stored in a variable can be changed during program execution.

    ## #2.1 Variable Declaration






```cpp

// Path: variable_declaration.cpp

#include <iostream>
    using namespace std;

int main()
{
    // Variable declaration
    int a;
    float b;
    char c;
    double d;

    // Variable initialization
    a = 5;
    b = 3.14;
    c = 'A';
    d = 12.345;

    cout << "Value of a: " << a << endl;
    cout << "Value of b: " << b << endl;
    cout << "Value of c: " << c << endl;
    cout << "Value of d: " << d << endl;

    return 0;
}
