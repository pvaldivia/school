//chart3.cpp
//Valdivia, Pedro
//pvaldivia1

#include<iostream>
#include<array>

using namespace std;

const int MAX = 100;

int find_largest(int []);

int main()
{
//DECLARATION OF ARRAYS
    int values[MAX];
    int values2[MAX];
    int values3[MAX]; 
    int values4[MAX];

//DECLARATION OF VARIABLES
    int bigNum;
    int astericConst;
    int numRows = 0;
    int numCols = 0; 

//COLLECTS USER INPUT TO INSERT VALUES TO THE FIRST ARRAY
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

//CREATES DUPLICATES OF THE FIRST ARRAY
    for(int i = 0; i < MAX; i++)
    {
        values2[i] = values[i];
        values3[i] = values[i];
        values4[i] = values[i];
    }

//DEFINES VARIABLES FOR UPRIGHT CHART
    bigNum = find_largest(values);
    numRows = bigNum;
    astericConst = bigNum;

//DISPLAYS THE UPRIGHT ASTERIC CHART WITH FIRST ARRAY
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

//SEPARATES THE TO DIFFERENT CHARTS BEING DISPLAYED
    cout<<endl;

//DISPLAYS THE UPSIDE DOWN ASTERIC CHART WITH SECOND ARRAY
    for (int row = 0; row < numRows; row++)
    {
        for(int col = 0; col < numCols; col++)
        {
            if(values2[col] > 0)
            {
                cout<<"*";
                values2[col] = values2[col] - 1;
                

            }
            else 
            {
                cout<<" ";
            }
        }
        cout<<"\n";
    }

//SEPARATES THE ASTERIC CHARTS
    cout<<endl;

//REDEFINING THE VARIABLES TO DRAW ASTERIC CHART 3 AND 4
    numRows = numCols;
    numCols = bigNum;

//DISPLAYING RIGHT-SIDED ASTERIC CHART WITH THE THIRD ARRAY
    for (int row = 0; row < numRows; row++)
    {   
        for (int col = 0; col < numCols; col++)
        {
            if (values3[row] > 0)
            {
                cout<<"*";
                values3[row] = values3[row] - 1;
            }
            else
            {
                cout<<" ";
            }
            
        }
        cout<<"\n";
    }

//SEPARATES THE ASTERIC CHARTS
    cout<<endl;

//REDEFINING VARIABLES FOR LEFT-SIDED ASTERIC CHART
    astericConst = bigNum;

//DISPLAYING THE LEFT-SIDED ASTERIC CHART WITH THE FOURTH ARRAY
    for(int row = 0; row < numRows; row++)
    {
        for (int col = 0; col < numCols; col++)
        {
            if (values4[row] >= astericConst)
            {
                cout<<"*";
            }
            else
            {
                cout<<" ";
                values4[row] = values4[row] + 1;
            }
        }
        cout<<"\n";
    }

    return 0;
}
//HELPS FIND THE LARGEST NUMBER WITHIN THE FIRST ARRAY
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

