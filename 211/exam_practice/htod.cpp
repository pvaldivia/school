#include<iostream>
#include<math.h>

using namespace std;

int main(int argc, char *argv[])
{
    double decimal;
    for (int i = 1; i < argc; i++)
    {
        decimal = decimal + atoi(argv[i])*(pow(16,argc - 1));

    }
    cout << "decimal = " << decimal << endl;
    return 0;
}


