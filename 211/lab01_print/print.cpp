#include<iostream>
using namespace std;

int 
main()
{
    int num;
    int repNum = 0;
    cin>>num;
    while(num > 0)
    {
        cout<<repNum<<" hello\n";
        repNum++;
        num--;
    }
    return 0;
}
