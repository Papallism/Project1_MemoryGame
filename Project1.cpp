#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
using namespace std;

void displayBoard();
void displayPositions();

int main()
{
    const int SIZE = 3;
    char board[SIZE][SIZE] = {'a', 'd', 'b', 'a', 'c', ' ', 'd', 'b', 'c'};

    cout << "Welcome to the Matching Game. At each move, choose two positions that you think match.\n";
    displayBoard();
    displayPositions();

    return 0;
}

void displayBoard()
{
    cout << "\nBoard is:\n";
}

void displayPositions()
{
    cout << "\nBoard positions are:\n\n1 2 3 \n4 5 6\n7 8 9\n";
}
