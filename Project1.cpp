#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
using namespace std;

const int BOARDSIZE = 3; //constant for board dimensions

void displayStars(char [][BOARDSIZE]);
void displayPositions();
void displayChoice(const char [][BOARDSIZE], const int , const int);

int main()
{
    bool win = false;
    int pos1, pos2, moves = 0;
    char stars[BOARDSIZE][BOARDSIZE] = {'*', '*', '*', '*', '*', '*', '*', '*', '*'};
    char board[BOARDSIZE][BOARDSIZE] = {'a', 'd', 'b', 'a', 'c', ' ', 'd', 'b', 'c'};

    cout << "Welcome to the Matching Game. At each move, choose two positions that you think match.\n";
    displayPositions();
    while(!win)
    {
        moves++;
        do
        {
            cout << "\nMove #" << moves << " : Enter two positions to match: ";
            cin >> pos1;
            cin >> pos2;
            if((pos1 < 1 || pos1 > 9) || (pos2 < 1 || pos2 > 9) || pos1 == pos2)
                cout << "Invalid input! Please enter valid positions.\n";
        }while((pos1 < 1 || pos1 > 9) || (pos2 < 1 || pos2 > 9) || pos1 == pos2);
        displayChoice(board, pos1, pos2);
        displayStars(stars);
    }

    return 0;
}

void displayPositions()
{
    cout << "\nBoard is:\n\n*  *  *\n*  *  *\n*  *  *\n";
    cout << "\nBoard positions are:\n\n1  2  3 \n4  5  6\n7  8  9\n";
}

void displayChoice(const char board[][BOARDSIZE], const int choice1, const int choice2)
{//displays board after selection
    cout << "\nBoard is:\n\n";
    for(int i = 0; i < BOARDSIZE; i++)
    {
        for(int j = 0; j < BOARDSIZE; j++)
        {
            if((i == (choice1 - 1) / BOARDSIZE) && (j == (choice1 - 1) % BOARDSIZE))
                cout << setw(3) << left << board[i][j];
            else if((i == (choice2 - 1) / BOARDSIZE) && (j == (choice2 - 1) % BOARDSIZE))
                cout << setw(3) << left << board[i][j];
            else
                cout << setw(3) << left << "*";
        }
        cout << endl;
    }
}

void displayStars(char starsBoard [][BOARDSIZE])
{
    cout << "\nBoard is:\n\n";
    for(int i = 0; i < BOARDSIZE; i++)
    {
        for(int j = 0; j < BOARDSIZE; j++)
            cout << setw(3) << left << starsBoard[i][j];
        cout << endl;
    }
}

















