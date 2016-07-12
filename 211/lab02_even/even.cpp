//even.cpp
//Valdivia, Pedro
//pvaldivia1

#include<iostream>

using namespace std;


int main()
{
    int num;
    int not_true = 0;

    while (cin>>num)
    {
        if (num %2 == 0)
        {
            not_true = not_true;

        }
        else 
        {
            not_true++;
        }
    }

    if (not_true == 0)
    {
        cout<<"all even\n";
        return 0;
    }
    else 
    {
        cerr<<"not all even\n";
        return 1;
    }
}

