#include <iostream>
using namespace std;

void CD(int count) {
    while (count > 0) {
        cout<< count<< endl;
        count = count -1;
    }
    cout << "Go!\n";
}

void countDown (int count) {
    if (count <= 0) {
        cout << "Go!\n";
    } else {
        cout<<count<<endl;
        countDown(count - 1);
        }
    }

int main()
{
    cout << "hello world!";    
    return 0;
}