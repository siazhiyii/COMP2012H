#include <iostream>

using namespace std;

// Start your code from here
// Complete the function definitions according to the description page

void printBoard(int board[][BOARD_WIDTH])
{
    for (int row = 0; row < BOARD_HEIGHT; ++row)
    {
        cout << "+------+------+------+------+" << endl;
        for (int col = 0; col < BOARD_WIDTH; ++col)
        {
            cout << "| ";
            if (board[row][col] != 0)
            {
                int numSpaces = 4 - to_string(board[row][col]).length();
                cout << board[row][col];
                for (int k = 0; k < numSpaces; ++k)
                {
                    cout << " ";
                }
                cout << " ";
            }
            else
            {
                cout << "     ";
            }
        }
        cout << "|" << endl;
    }
    cout << "+------+------+------+------+" << endl;
}

void moveBoardUp(int board[][BOARD_WIDTH])
{
    bool boardChanged = false;
    for (int col = 0; col < BOARD_WIDTH; ++col)
    {
        for (int row = 0; row < BOARD_HEIGHT; ++row)
        {
            if (board[row][col] == 0)
            {
                for (int nextRow = row + 1; nextRow < BOARD_HEIGHT; ++nextRow)
                {
                    if (board[nextRow][col] != 0)
                    {
                        board[row][col] = board[nextRow][col];
                        board[nextRow][col] = 0;
                        boardChanged = true;
                        break;
                    }
                }
            }
        }
    }
    for (int col = 0; col < BOARD_WIDTH; ++col)
    {
        for (int row = 0; row < BOARD_HEIGHT - 1; ++row)
        {
            if ((board[row][col] != 0) && (board[row][col] == board[row + 1][col]))
            {
                board[row][col] *= 2;
                board[row + 1][col] = 0;
                boardChanged = true;
            }
        }
    }
    if (boardChanged)
    {
        for (int col = 0; col < BOARD_WIDTH; ++col)
        {
            for (int row = 0; row < BOARD_HEIGHT; ++row)
            {
                if (board[row][col] == 0)
                {
                    for (int nextRow = row + 1; nextRow < BOARD_HEIGHT; ++nextRow)
                    {
                        if (board[nextRow][col] != 0)
                        {
                            board[row][col] = board[nextRow][col];
                            board[nextRow][col] = 0;
                            boardChanged = true;
                            break;
                        }
                    }
                }
            }
        }
    }
}

void moveBoardDown(int board[][BOARD_WIDTH])
{
    bool boardChanged = false;
    for (int col = 0; col < BOARD_WIDTH; ++col)
    {
        for (int row = BOARD_HEIGHT - 1; row >= 0; --row)
        {
            if (board[row][col] == 0)
            {
                for (int nextRow = row - 1; nextRow >= 0; --nextRow)
                {
                    if (board[nextRow][col] != 0)
                    {
                        board[row][col] = board[nextRow][col];
                        board[nextRow][col] = 0;
                        boardChanged = true;
                        break;
                    }
                }
            }
        }
    }
    for (int col = 0; col < BOARD_WIDTH; ++col)
    {
        for (int row = BOARD_HEIGHT - 1; row > 0; --row)
        {
            if ((board[row][col] != 0) && (board[row][col] == board[row - 1][col]))
            {
                board[row][col] *= 2;
                board[row - 1][col] = 0;
                boardChanged = true;
            }
        }
    }
    if (boardChanged)
    {
        for (int col = 0; col < BOARD_WIDTH; ++col)
        {
            for (int row = BOARD_HEIGHT - 1; row >= 0; --row)
            {
                if (board[row][col] == 0)
                {
                    for (int nextRow = row - 1; nextRow >= 0; --nextRow)
                    {
                        if (board[nextRow][col] != 0)
                        {
                            board[row][col] = board[nextRow][col];
                            board[nextRow][col] = 0;
                            boardChanged = true;
                            break;
                        }
                    }
                }
            }
        }
    }
}

void moveBoardLeft(int board[][BOARD_WIDTH])
{
    bool boardChanged = false;
    for (int row = 0; row < BOARD_HEIGHT; ++row)
    {
        for (int col = 0; col < BOARD_WIDTH; ++col)
        {
            if (board[row][col] == 0)
            {
                for (int k = col + 1; k < BOARD_WIDTH; ++k)
                {
                    if (board[row][k] != 0)
                    {
                        boardChanged = true;
                        board[row][col] = board[row][k];
                        board[row][k] = 0;
                        break;
                    }
                }
            }
        }
    }
    for (int row = 0; row < BOARD_HEIGHT; ++row)
    {
        for (int col = 0; col < BOARD_WIDTH - 1; ++col)
        {
            if ((board[row][col] != 0) && (board[row][col] == board[row][col + 1]))
            {
                boardChanged = true;
                board[row][col] *= 2;
                board[row][col + 1] = 0;
            }
        }
    }
    if (boardChanged)
    {
        for (int row = 0; row < BOARD_HEIGHT; ++row)
        {
            for (int col = 0; col < BOARD_WIDTH; ++col)
            {
                if (board[row][col] == 0)
                {
                    for (int k = col + 1; k < BOARD_WIDTH; ++k)
                    {
                        if (board[row][k] != 0)
                        {
                            board[row][col] = board[row][k];
                            board[row][k] = 0;
                            break;
                        }
                    }
                }
            }
        }
    }
}

void moveBoardRight(int board[][BOARD_WIDTH])
{
    bool boardChanged = false;
    for (int row = 0; row < BOARD_HEIGHT; ++row)
    {
        for (int col = BOARD_WIDTH - 1; col >= 0; --col)
        {
            if (board[row][col] == 0)
            {
                for (int k = col - 1; k >= 0; --k)
                {
                    if (board[row][k] != 0)
                    {
                        boardChanged = true;
                        board[row][col] = board[row][k];
                        board[row][k] = 0;
                        break;
                    }
                }
            }
        }
    }
    for (int row = 0; row < BOARD_HEIGHT; ++row)
    {
        for (int col = BOARD_WIDTH - 1; col > 0; --col)
        {
            if ((board[row][col] != 0) && (board[row][col] == board[row][col - 1]))
            {
                boardChanged = true;
                board[row][col] *= 2;
                board[row][col - 1] = 0;
            }
        }
    }
    if (boardChanged)
    {
        for (int row = 0; row < BOARD_HEIGHT; ++row)
        {
            for (int col = BOARD_WIDTH - 1; col >= 0; --col)
            {
                if (board[row][col] == 0)
                {
                    for (int k = col - 1; k >= 0; --k)
                    {
                        if (board[row][k] != 0)
                        {
                            board[row][col] = board[row][k];
                            board[row][k] = 0;
                            break;
                        }
                    }
                }
            }
        }
    }
}

bool checkWin(int board[][BOARD_WIDTH])
{
    const int WINNING_VALUE = 2048;
    for (int row = 0; row < BOARD_HEIGHT; ++row)
    {
        for (int col = 0; col < BOARD_WIDTH; ++col)
        {
            if (board[row][col] == WINNING_VALUE)
            {
                return true;
            }
        }
    }
    return false;
}