#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    int pos, loop = 1;
    char board[3][3] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

    srand(time(0));

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
            cout << board[i][j] << " ";
        cout << endl << endl;
    }

    for(loop; loop <= 8; loop++)
    {
        pos = rand() % 9 + 1;

    }

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }

    return 0;
}
