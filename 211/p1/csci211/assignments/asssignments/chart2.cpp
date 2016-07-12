//chart2.cpp
//Valdivia, Pedro
//pvaldivia1

#include<iostream>
#include<array>

using namespace std;

const int MAX = 100;

int find_largest(int []);

int main()
{
//ARRAY AND VARIABLES FOR CHART_CPP   
    int values[MAX];
    int bigNum;
    int astericConst;
    int numRows = 0;
    int numCols = 0; 
//COLLECTS USER INPUT FOR DECLARED ARRAY
    for (int i = 0; i < MAX; i++)
    {
        cin>>values[i];
        if (values[i] != 0)
        {
            numCols++;
        }
        if (values[i] == 0) 
        {
            do 
            {
                values[i+1] = 0;
                i++;
            }while (i < MAX);
        }
    }
//VARIABLES AND FUNCTION THAT SET UP THE CHART
    bigNum = find_largest(values);
    numRows = bigNum;
    astericConst = bigNum;
//PRINTS THE ASTERIC CHART
    for (int row = 0; row < numRows; row++)
    {
        for(int col = 0; col < numCols; col++)
        {
            if (values[col] == astericConst)
            {
                cout<<"*";
                values[col] = values[col] - 1;
            }
            else
            {
                cout<<" ";
            }
        }
        astericConst--;
        cout<<"\n";
    }

return 0;
}

//FUNCTION THAT FINDS THE LARGEST NUMBER IN THE PASSED IN ARRAY
int find_largest(int array[])
{   
    int num = 0;
    int largest = 0;

    for (int i = 0; i < MAX; i++)
    {
        num = array[i];
        if (largest > num ) continue;
        largest = num;
    }

    return largest;
}

