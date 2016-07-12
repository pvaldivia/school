//chart.cpp
//Valdivia, Pedro
//pvaldivia1

#include<iostream>
#include<array>

using namespace std;

const int MAX = 100;

int find_largest(int []);
void create_chart(int, int, int []);
void rotate_counterclockwise(char [][MAX],int,int);

int main()
{
    int values[MAX];
    int bigNum;
    int numRows = 0;
    int numCols = 0; 
    for (int i = 0; i < MAX; i++)
    {
        cin>>values[i];
        if (values[i] != 0)
        {
            numRows++;
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

    bigNum = find_largest(values);
    numCols = bigNum;
    create_chart(numRows,numCols,values);
//    cout<<bigNum;

/*    for (int i = 0; i < MAX; i++)
    {
        cout<<values[i]<<endl;
        
    }
*/

return 0;
}

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

void create_chart(int rows, int cols, int arrayNum [])
{
    char arrayChar[rows][cols];
    int num = 0;
    int numAsterics;
    do 
    {
        if (arrayNum[num] > 0)
        {
            numAsterics = arrayNum[num];
            for (int row = 0; row < rows; row++)
            {
                for (int col = 0; col < numAsterics; col++)
                {
                        arrayChar[row][col] = '*';
                }
                num++;
                numAsterics = arrayNum[num];
            }
        }
    } while (arrayNum[num] != 0);



    for (int w = 0; w < rows; w++)
    {
        for (int e = 0; e < cols; e++)
        {
            if (arrayChar[w][e] != '*')
            {
                arrayChar[w][e] = ' ';
            }
        }
    }
    rotate_counterclockwise(arrayChar,rows,cols);

}

void rotate_counterclockwise(char array[][], int rows, int cols)
{
    char newArray[cols][rows];

   /* for (int col = 0; col < cols; col++)
    {
        for (int row = 0; row < rows; row++)
        {
            newArray[col-row-1][row] = array[col][row];
        }
    }*/
    for (int p = 0; p < cols; p++)
    {
        for (int c = 0; c < rows; c++)
        {
            cout<<newArray[p][c];
        }
        cout<<"\n";
    }
}
