#include <bits/stdc++.h>
using namespace std;

const int N = 3;
char board[N][N];

void printIt(int row)
{
    int j = 0;

    if (board[row][j] == 'X' || board[row][j] == 'O')
        printf("  %c  |", board[row][j]);
    else
        printf("     |");

    if (board[row][j + 1] == 'X' || board[row][j + 1] == 'O')
        printf("  %c  |", board[row][j + 1]);
    else
        printf("     |");

    if (board[row][j + 2] == 'X' || board[row][j + 2] == 'O')
        printf("  %c  \n", board[row][j + 2]);
    else
        printf("     \n");
}

int main()
{
    char alpha = 'a';
  
    board[0][0] = 'O';
    board[2][1] = 'X';
    board[2][2] = 'X';

    //testing output
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            //cout << "(" << i << "," << j << ")" << " ";
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "\n";
    for (int row = 1; row < 10; row++)
    {
        int j = 0;

        if (row % 3 == 0 && row != 9)
            cout << "_____|_____|_____\n";

        else if (row == 2)
        {
            printIt(0);
        }

        else if (row == 5)
        {
            printIt(1);
        }

        else if (row == 8)
        {
            printIt(2);
        }

        else
            printf("     |     |     \n");
    }
}