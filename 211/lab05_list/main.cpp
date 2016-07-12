#include <iostream>
using namespace std;
#include "list.h"

int main()
{
    // instantiate a List class (the constructor takes NO arguments)
    List list;
    int value;

    // NOTE:
    // List list();  is incorrect, when there are no arguments don't use ()

    // insert numbers into the list
    while (cin >> value)
    {
       list.insert_at_end(value);
    }
    list.print();
    cout << "sum = " << list.sum() << endl;

    /*list.print();
    list.insert(1);
    list.print();
    list.insert(2);
    list.print();
    list.insert(3);
    list.print();*/

    return 0;
}
