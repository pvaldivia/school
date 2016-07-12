#include <iostream>
#include <assert.h>
using namespace std;

int largest_in_array(int values[], int size)
{
    assert(size > 0);
    // replace this will the real code...
    if(size == 1)
    return values[0];

    int largest_in_rest_array = largest_in_array(values + 1, size - 1);
    if (values[0] > largest_in_rest_array)
    return values[0];
    else
    return largest_in_rest_array;

}

int main()
{
    int values[1000];
    int size;
    cout << "Enter integers.  Type control-D when done\n";
    for (size = 0; cin >> values[size]; size++)
      ;
    cout << "The largest value is " << largest_in_array(values, size) << endl;
}
