#include <iostream>
#include<stdlib.h>

using namespace std;

bool legal_int(char*);

int main(int argc, char *argv[])
{
    int total_value = 0;

    for (int i = 1; i < argc; i++)
    {
        if (!legal_int(argv[i]))
        {
            cerr << "Error: illegal integer." << endl;
            exit(1);
        }
        total_value = total_value + atoi(argv[i]);
    }
    cout << total_value << endl;

    return 0;
}

bool legal_int(char *str)
{
    while (*str != 0)
    {
        if (!isdigit(*str))
        return false;

        str++;
    }
    return true;
}
