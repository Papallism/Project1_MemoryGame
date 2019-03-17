#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
using namespace std;

const int BOARDSIZE = 3;

void displayBoard(char [][BOARDSIZE]);
void displayPositions();

int main()
{
    int moves = 0;
    char stars[BOARDSIZE][BOARDSIZE] = {'*', '*', '*', '*', '*', '*', '*', '*', '*'};
    char board[BOARDSIZE][BOARDSIZE] = {'a', 'd', 'b', 'a', 'c', ' ', 'd', 'b', 'c'};

    cout << "Welcome to the Matching Game. At each move, choose two positions that you think match.\n";
    displayBoard(stars);
    displayPositions();

    return 0;
}

void displayBoard(char stars[][BOARDSIZE])
{
    cout << "\nBoard is:\n\n";
    for(int i = 0; i < BOARDSIZE; i++)
    {
        for(int j = 0; j < BOARDSIZE; j++)
            cout << stars[i][j] << "  ";
        cout << endl;
    }
}

void displayPositions()
{
    cout << "\nBoard positions are:\n\n1  2  3 \n4  5  6\n7  8  9\n";
}
