#include <bits/stdc++.h>
using namespace std;

const int N = 3;
char board[N][N];

void boardFiller(int user_input, char sign)
{

    if (user_input == 1)
        board[2][0] = sign;
    else if (user_input == 2)
        board[2][1] = sign;
    else if (user_input == 3)
        board[2][2] = sign;

    else if (user_input == 4)
        board[1][0] = sign;
    else if (user_input == 5)
        board[1][1] = sign;
    else if (user_input == 6)
        board[1][2] = sign;

    else if (user_input == 7)
        board[0][0] = sign;
    else if (user_input == 8)
        board[0][1] = sign;
    else if (user_input == 9)
        board[0][2] = sign;
}

void signPlacement(int row)
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

void printBoard()
{
    cout << "\n------------------TIC TAC TOE-----------------" << endl;

    //testing output
    // for (int i = 0; i < N; i++)
    // {
    //     for (int j = 0; j < N; j++)
    //     {
    //         //cout << "(" << i << "," << j << ")" << " ";
    //         cout << board[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    for (int row = 1; row < 10; row++)
    {
        int j = 0;

        if (row % 3 == 0 && row != 9)
            cout << "_____|_____|_____\n";

        else if (row == 2)
        {
         signPlacement(0);
        }

        else if (row == 5)
        {
         signPlacement(1);
        }

        else if (row == 8)
        {
         signPlacement(2);
        }

        else
            printf("     |     |     \n");
    }

    cout << "\n\n";
}

bool columnChecking(int r, int c)
{
    while (r != N - 1)
    {

        if (board[r][c] == board[r + 1][c])
            r++;
        else
            return false;
    }

    return true;
}

bool rowChecking(int r, int c)
{
    while (c != N - 1)
    {

        if (board[r][c] == board[r][c + 1])
            c++;
        else
            return false;
    }

    return true;
}

bool leftDiagonalChecking(int r, int c)
{
    while (r != N - 1 && c != N - 1)
    {

        if (board[r][c] == board[r + 1][c + 1])
        {
            r++;
            c++;
        }
        else
            return false;
    }

    return true;
}

bool rightDiagonalChecking(int r, int c)
{
    while (r != N - 1 && c != 0)
    {

        if (board[r][c] == board[r + 1][c - 1])
        {
            r++;
            c--;
        }

        else
            return false;
    }

    return true;
}

bool isMatched(int r, int c)
{
    bool a, b, d;

    // (0,0) [diagonal-left corner]
    if (r == c)
    {
        //cout << "INSIDE DIAGONAL CHECKING.." << endl;
        a = leftDiagonalChecking(r, c);
        b = columnChecking(r, c);
        d = rowChecking(r, c);

        return (a || b || d);
    }

    // (0,1), (0,2), ...... [col]
    else if (r == 0)
    {
        //cout << "INSIDE COLUMN CHECKING.." << endl;
        a = columnChecking(r, c);
        return a;
    }

    // (0,2) [diagonal-right corner]
    else if (r == 0 && c == N - 1)
    {
        //cout << "INSIDE DIAGONAL CHECKING..2" << endl;
        a = rightDiagonalChecking(r, c);
        b = columnChecking(r, c);
        d = rowChecking(r, c);

        return (a || b || d);
    }

    // (1,0), (2,0), ..... [row]
    else if (c == 0)
    {
        //cout << "INSIDE ROW CHECKING.." << endl;
        a = rowChecking(r, c);
        return a;
    }

}

bool checkWinner()
{
    bool checkCrossMatching;

    for (int i = 0; i < N; i++) // becareful about indexing...N-1 or N-2??
    {

        if (i == 0)
        {
            for (int j = 0; j < N; j++)
            {
                checkCrossMatching = isMatched(i, j);
                if (checkCrossMatching)
                    return true;
            }
        }

        else
        {
            int j = 0;
            checkCrossMatching = isMatched(i, j);
            if (checkCrossMatching)
                return true;
        }
    }

    return false;
}

int main()
{

    int turn = 0;
    char sign, alpha = '1';
    int user_input;

    // initialize;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            board[i][j] = alpha;
            alpha++;
        }

    // taking user input
    while (turn != N * N)
    {

        // seeking user input
        while (1)
        {
            // define 1st or 2nd user
            if (turn % 2 == 0)
            {
                sign = 'X';
                cout << "Player 1 (X)" << endl;
            }
            else
            {
                sign = 'O';
                cout << "Player 2 (O)" << endl;
            }

            // user input
            cin >> user_input;

            // check input
            if (user_input > 0 && user_input < 10)
                break;
            else
            {
                cout << "Please Enter between 1 to 9" << endl;
            }
        }

        // place input to corresponding cells
        boardFiller(user_input, sign);

        // show the board
        printBoard();

        // check winner
        if (checkWinner())
        {
            if (turn % 2 == 0)
                cout << ">>>>>> Player 1 is the Winner <<<<<<\n\n" << endl;
            else
                cout << ">>>>>> Player 2 is the Winner <<<<<<\n\n" << endl;
            break;
        }

        turn = turn + 1;
    }
}