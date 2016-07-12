#include<iostream>
#include"list.h"

using namespace std;

int main()
{
    List list;
    int list_value;
    int array_value;
    int size;
    int size2;

    cout <<"How many values in List?\n";
    cin >> size;
    cout <<"Enter list values.\n";
    while (size > 0)
    {
        cin >> list_value;
        list.insert(list_value);
        size--;
    }
    cout << "How Many Values in Array?" << endl;
    cin >> size2;
    int array[size2];
    int index = 0;
    cout << "Insert Array Values." << endl;

    while (index < size2)
    {
        cin >> array_value;
        array[index] = array_value;
        index++;
    }
    cout << "Original List:" << endl;
    list.print();
    cout << endl;
    cout << "Array List: " << endl;
    for (int i = 0; i < size2; i++)
    {
        cout << array[i] << endl;
    }

    if (list.contains_sequence(array,size2) == true)
    {
        cout << "True. List contains sequence.\n";
    }
    else 
    {
        cout << "False. List Does Not contain sequence.\n";
    }
    return 0;
}
