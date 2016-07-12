#include <iostream>
#include <ctype.h>
#include <assert.h>
using namespace std;

bool is_int(char str[])
{
    // replace this will the real code...
    if (*str == 0)
    return true;
    return (isdigit(*str) && is_int(str + 1));

}

int main()
{
    char buf[1000];
    cout << "Enter a string: ";
    cin >> buf;

    if (is_int(buf))
      cout << "<" << buf << "> is an integer.\n";
    else cout << "<" << buf << "> is NOT an integer.\n";
}
