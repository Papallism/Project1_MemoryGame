#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void cleanBoard(char [][BOARDSIZE]);
void fillBoard(char [][BOARDSIZE]);

int main()
{
    int pos;
    char board[3][3] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

    srand(time(0));

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
            cout << board[i][j] << " ";
        cout << endl << endl;
    }

    return 0;
}

void cleanBoard(char board[][BOARDSIZE])
{
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            board[i][j] = " ";
}

void fillBoard(char [][BOARDSIZE])
{
    for(int i = 1; i < 9; i++)
    {
        do
        {
            pos = rand() % 9 + 1;
        }while(board[(pos - 1) / 3][(pos - 1) % 3] != ' ');
        switch(i)
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





















