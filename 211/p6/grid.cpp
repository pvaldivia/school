#include"grid.h"
#include<iostream>

using namespace std;

const int ROWS = 24;
const int COLS = 60;

Grid::Grid()
{
    grid.resize(ROWS);
    for (unsigned int row = 0; row < grid.size(); row++) 
        grid[row].resize(COLS);

    for (unsigned int row = 0; row < grid.size(); row++)
    {
        for (unsigned int col = 0; col < grid[0].size(); col++)
        {
            grid[row][col] = ' ';
        }
    }
}

void Grid::set(int x, int y, char character)
{
    if (x >= 0 && x < COLS && y >= 0 && y < ROWS)
    {
        grid[y][x] = character;
    }
}

void Grid::print()
{
    for (unsigned int row = 0; row < grid.size(); row++)
    {
        for (unsigned int col = 0; col < grid[0].size(); col++)
        {
            cout << grid[row][col];
        }
        cout << "\n";
    }
}
