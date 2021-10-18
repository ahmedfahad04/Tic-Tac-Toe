#include <bits/stdc++.h>
using namespace std;

const int N = 3;
char board[N][N];
vector<int> allInputs;

bool userInputValidity(int user_input, char sign)
{

    if (user_input == 1)
    {
        if (board[2][0] != 'X' && board[2][0] != 'O')
            board[2][0] = sign;
        else
            return false;
    }
    else if (user_input == 2)
    {
        if (board[2][1] != 'X' && board[2][1] != 'O')
            board[2][1] = sign;
        else
            return false;
    }
    else if (user_input == 3)
    {
        if (board[2][2] != 'X' && board[2][2] != 'O')
            board[2][2] = sign;
        else
            return false;
    }

    else if (user_input == 4)
    {
        if (board[1][0] != 'X' && board[1][0] != 'O')
            board[1][0] = sign;
        else
            return false;
    }
    else if (user_input == 5)
    {
        if (board[1][1] != 'X' && board[1][1] != 'O')
            board[1][1] = sign;
        else
            return false;
    }
    else if (user_input == 6)
    {
        if (board[1][2] != 'X' && board[1][2] != 'O')
            board[1][2] = sign;
        else
            return false;
    }

    else if (user_input == 7)
    {
        if (board[0][0] != 'X' && board[0][0] != 'O')
            board[0][0] = sign;
        else
            return false;
    }
    else if (user_input == 8)
    {
        if (board[0][1] != 'X' && board[0][1] != 'O')
            board[0][1] = sign;
        else
            return false;
    }
    else if (user_input == 9)
    {
        if (board[0][2] != 'X' && board[0][2] != 'O')
            board[0][2] = sign;
        else
            return false;
    }

    return true;
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

void showBoard()
{
    cout << "\n------------------TIC TAC TOE-----------------\n\n"
         << endl;

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
    // r = 0, c = 2-------check if (r != 2 && c != 0)
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
        // cout << "INSIDE DIAGONAL CHECKING.." << endl;
        a = leftDiagonalChecking(r, c);
        b = columnChecking(r, c);
        d = rowChecking(r, c);

        return (a || b || d);
    }

    // (0,1), (0,2), ...... [colomn]
    else if (r == 0 && c < N - 1)
    {
        // cout << "INSIDE COLUMN CHECKING.." << endl;
        a = columnChecking(r, c);
        return a;
    }

    // (0,2) [diagonal-right corner]
    else if (r == 0 && c == N - 1)
    {
        // cout << "INSIDE DIAGONAL CHECKING..2" << endl;
        a = rightDiagonalChecking(r, c);
        b = columnChecking(r, c);

        return (a || b);
    }

    // (1,0), (2,0), ..... [row]
    else if (c == 0)
    {
        // cout << "INSIDE ROW CHECKING.." << endl;
        a = rowChecking(r, c);
        return a;
    }
}

bool checkWinner()
{
    bool checkCrossMatching;

    for (int i = 0; i < N; i++) // becareful about indexing...N, N-1 or N-2??
    {

        if (i == 0)
        {
            for (int j = 0; j < N; j++)
            {
                if (board[i][j] == 'X' || board[i][j] == 'O')
                {
                    checkCrossMatching = isMatched(i, j);
                    if (checkCrossMatching)
                        return true;
                }
            }
        }

        else
        {
            if (board[i][0] == 'X' || board[i][0] == 'O')
            {
                checkCrossMatching = isMatched(i, 0);
                if (checkCrossMatching)
                    return true;
            }
        }
    }

    return false;
}

void dualUser(int turn)
{
    int user_input;
    char sign;

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
        {

            bool isVlaid;

            // place input to corresponding cells
            isVlaid = userInputValidity(user_input, sign);
            if (isVlaid)
                break;
            else
            {
                cout << "This place is already occupied by another player. Input Again!!\n\n";
            }
        }

        else
        {
            cout << "Please Enter between 1 to 9" << endl;
        }
    }

    // show the board
    showBoard();
}

void masterUser()
{
    while (1)
    {   
        srand(time(0));
        int index = rand() % allInputs.size(); // select random input index from the vector

        bool valid = userInputValidity(allInputs[index], 'X');

        if (valid)
        {
            allInputs.erase(allInputs.begin()+index);
            return;
        }

        else
            continue;
    }
}

void singleUser()
{
    while (1)
    {
        int user_input;
        cin >> user_input;

        // check input
        if (user_input > 0 && user_input < 10)
        {

            bool isValid;

            // place input to corresponding cells
            isValid = userInputValidity(user_input, 'O');

            if (isValid)
            {
                return;
            }

            else
            {
                cout << "This place is already occupied by master user. Input Again!!\n\n";
            }
        }

        else
        {
            cout << "Please Enter between 1 to 9" << endl;
        }
        
    }
}

int main()
{

    int turn = 0, toss;
    char starter;
    char alpha = '1';

    // initialize
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            board[i][j] = alpha;
            alpha++;
        }

    for (int i = 1; i < 10; i++)
        allInputs.push_back(i);

    // instruction
    string s;

    s = "\nYou can play this game with two player. Use the numpad keys to enter your inputs.\nKeys form 1 to 9 represents the cells of tic-tac-toe.\n\n";
    cout << "\n\n---------------------------Instruction---------------------------" << endl;
    cout << s << endl;


    while (turn != N * N)
    {
        if (turn % 2 == 0)
        {
            cout << "Master User's TURN" << endl;
            masterUser();
        }

        else
        {
            cout << "Your TURN" << endl;
            singleUser();
        }

        // show the tic tac toe board
        showBoard();

        // check winner
        if (checkWinner() == true)
        {
            if (turn % 2 == 0)
                cout << ">>>>>> Master User (X) is the Winner <<<<<<\n\n"
                     << endl;
            else
                cout << ">>>>>> Your (O) are the Winner <<<<<<\n\n"
                     << endl;

            return 0;
        }

        turn = turn + 1;
    }

    cout << ">>>>>> MATCH DRAW <<<<<<\n\n";
}