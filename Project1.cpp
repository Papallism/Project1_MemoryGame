#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
using namespace std;

const int BOARDSIZE = 3; //constant for board dimensions

void clearScreen();
void displayStars(const char [][BOARDSIZE]);
void displayPositions();
void displayChoice(const char [][BOARDSIZE], char [][BOARDSIZE], const int , const int);
bool endGame(const char [][BOARDSIZE], const char [][BOARDSIZE]);
void cleanBoard(char [][BOARDSIZE]);
void fillBoard(char [][BOARDSIZE]);

int main()
{
    char replay;
    bool win = false;
    int pos1, pos2, moves = 0;
    char stars[BOARDSIZE][BOARDSIZE] = {'*', '*', '*', '*', '*', '*', '*', '*', '*'};
    char board[BOARDSIZE][BOARDSIZE];

    cleanBoard(board);
    fillBoard(board);
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
            if((pos1 < 1 || pos1 > 9) || (pos2 < 1 || pos2 > 9) || pos1 == pos2) //invalid input warning
                cout << "Invalid input! Please enter valid positions.\n";
        }while((pos1 < 1 || pos1 > 9) || (pos2 < 1 || pos2 > 9) || pos1 == pos2); //do-while loop until user inputs valid positions
        displayChoice(board, stars, pos1, pos2);
        clearScreen();
        win = endGame(board, stars);
        if(!win)
            displayStars(stars);
        else //check if the user wants to replay after winning
        {
            displayStars(board);
            cout << "\nYou did it in " << moves << " moves. Play again (Y or N)? ";
            do
            {
                cin >> replay;
                if(replay != 'y' && replay != 'Y' && replay != 'n' && replay && 'N') //message for invalid input
                    cout << "\nInvalid input. Please enter a valid character.\n";
                if(replay == 'y' || replay == 'Y')
                { //user wants to replay so everything is reset
                    cleanBoard(board);
                    fillBoard(board);
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

//displays the starting board and the position of each element
void displayPositions()
{
    cout << "\nBoard is:\n\n*  *  *\n*  *  *\n*  *  *\n";
    cout << "\nBoard positions are:\n\n1  2  3 \n4  5  6\n7  8  9\n";
}

//reveals the users choice on board
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

//displays the board with stars during the game
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

//prints 50 new lines after a 2-second pause
void clearScreen()
{
    Sleep(2000);
    for(int i = 0; i < 50; i++)
        cout << endl;
}

//determines if the user found all pairs
bool endGame(const char board[][BOARDSIZE], const char stars[][BOARDSIZE])
{
    for(int i = 0; i < BOARDSIZE; i++)
        for(int j = 0; j < BOARDSIZE; j++)
            if(board[i][j] >= 'a' && board[i][j] <= 'd') //if current element is a character
                if((board[i][j] != stars[i][j]) || (board[i][j] == ' ')) //and if the corresponding element in the asterisks board is not revealed
                    return false;   //or if it is a space then return false to keep playing
    return true;    //return true because all elements are matched
}

//fills array with spaces
void cleanBoard(char board[][BOARDSIZE])
{
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            board[i][j] = ' ';
}

//fills random positions with characters
void fillBoard(char board[][BOARDSIZE])
{
    int pos;
    srand(time(0));
    for(int i = 1; i < 9; i++)
    {
        do
        {
            pos = rand() % 9 + 1; //while generated position is not empty generate again
        }while(board[(pos - 1) / 3][(pos - 1) % 3] != ' ');
        switch(i) //use variable i to keep track of letters added to the board
        {
            case 1:
            case 2: board[(pos - 1) / 3][(pos - 1) % 3] = 'a';
                    break;
            case 3:
            case 4: board[(pos - 1) / 3][(pos - 1) % 3] = 'b';
                    break;
            case 5:
            case 6: board[(pos - 1) / 3][(pos - 1) % 3] = 'c';
                    break;
            case 7:
            case 8: board[(pos - 1) / 3][(pos - 1) % 3] = 'd';
                    break;
        }
    }
}
