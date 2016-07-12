#include<iostream>
#include"dstack.h"

using namespace std;

int main()
{
    Dstack stack;
    double value;
    while (cin >> value)
    {
        stack.push(value);
    }
    cout << "There are " << stack.size() << " numbers in the stack.\n";

    while(stack.empty() == false)
    {
        stack.pop(value);
        cout << value << endl;
    }
    cout << "There are " << stack.size() << " numbers in the stack.\n";

    return 0;
}
