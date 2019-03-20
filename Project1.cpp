#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
using namespace std;

const int BOARDSIZE = 3; //constant for board dimensions

//function prototypes
void clearScreen(); //prints 50 new lines after a 2-second pause
void displayStars(const char [][BOARDSIZE]); //displays the board with stars during the game
void displayPositions(); //displays the starting board and the position of each element
void displayChoice(const char [][BOARDSIZE], char [][BOARDSIZE], const int , const int); //reveals the users choice on board
bool endGame(const char [][BOARDSIZE], const char [][BOARDSIZE]); //determines if the user found all pairs

int main()
{
    char replay;
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
            if((pos1 < 1 || pos1 > 9) || (pos2 < 1 || pos2 > 9) || pos1 == pos2) //position input validation
                cout << "Invalid input! Please enter valid positions.\n";
        }while((pos1 < 1 || pos1 > 9) || (pos2 < 1 || pos2 > 9) || pos1 == pos2); //do-while loop until user inputs valid positions
        displayChoice(board, stars, pos1, pos2);
        clearScreen();
        win = endGame(board, stars);
        if(!win)
            displayStars(stars);
        else
            displayStars(board);
        if(win)
        { //check if the user wants to replay after winning
            cout << "\nYou did it in " << moves << " moves. Play again (Y or N)? ";
            do
            {
                cin >> replay;
                if(replay != 'y' && replay != 'Y' && replay != 'n' && replay && 'N') //message for invalid input
                    cout << "\nInvalid input. Please enter a valid character.\n";
                if(replay == 'y' || replay == 'Y') //user wants to replay so set moves to 0, win to false
                {
                    clearScreen();
                    displayPositions();
                    win = false;
                    moves = 0;
                    for(int i = 0; i < BOARDSIZE; i++) //reset the board back to asterisks for replay
                        for(int j = 0; j < BOARDSIZE; j++)
                            stars[i][j] = '*';
                }
                if(replay == 'n' || replay == 'N')
                    cout << "\nBye.\n"; //exit message after user replies with a no
            }while(replay != 'y' && replay != 'Y' && replay != 'n' && replay != 'N');
        }
    }

    return 0;
}

void displayPositions()
{
    cout << "\nBoard is:\n\n*  *  *\n*  *  *\n*  *  *\n";
    cout << "\nBoard positions are:\n\n1  2  3 \n4  5  6\n7  8  9\n";
}

void displayChoice(const char board[][BOARDSIZE], char starsBoard[][BOARDSIZE], const int choice1, const int choice2)
{//displays board after selection
    cout << "\nBoard is:\n\n";
    for(int i = 0; i < BOARDSIZE; i++)
    {
        for(int j = 0; j < BOARDSIZE; j++)
        { //output the board with asterisks but reveal the positions the user chose
            if((i == (choice1 - 1) / BOARDSIZE) && (j == (choice1 - 1) % BOARDSIZE))
                cout << setw(3) << left << board[i][j];
            else if((i == (choice2 - 1) / BOARDSIZE) && (j == (choice2 - 1) % BOARDSIZE))
                cout << setw(3) << left << board[i][j];
            else
                cout << setw(3) << left << starsBoard[i][j];
            if((board[(choice1 - 1) / BOARDSIZE][(choice1 - 1) % BOARDSIZE]) == (board[(choice2 - 1) / BOARDSIZE][(choice2 - 1) % BOARDSIZE]))
            { //if the positions match, overwrite the asterisks with the corresponding characters
                starsBoard[(choice1 - 1) / BOARDSIZE][(choice1 - 1) % BOARDSIZE] = board[(choice1 - 1) / BOARDSIZE][(choice1 - 1) % BOARDSIZE];
                starsBoard[(choice2 - 1) / BOARDSIZE][(choice2 - 1) % BOARDSIZE] = board[(choice2 - 1) / BOARDSIZE][(choice2 - 1) % BOARDSIZE];
            }
        }
        cout << endl;
    }
}

void displayStars(const char starsBoard [][BOARDSIZE])
{
    cout << "\nBoard is:\n\n";
    for(int i = 0; i < BOARDSIZE; i++)
    {
        for(int j = 0; j < BOARDSIZE; j++)
            cout << setw(3) << left << starsBoard[i][j];
        cout << endl;
    }
}

void clearScreen()
{
    Sleep(2000);
    for(int i = 0; i < 50; i++)
        cout << endl;
}

bool endGame(const char board[][BOARDSIZE], const char stars[][BOARDSIZE])
{
    for(int i = 0; i < BOARDSIZE; i++)
        for(int j = 0; j < BOARDSIZE; j++)
            if(board[i][j] >= 'a' && board[i][j] <= 'd') //if current element is a character
                if((board[i][j] != stars[i][j]) || (board[i][j] == ' ')) //and if the corresponding element in the asterisks board is not revealed
                    return false;   //or if it is a space then return false to keep playing
    return true;    //return true because all elements are matched
}
