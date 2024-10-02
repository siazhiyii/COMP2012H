#include <random>

const int LAB1_RAND_SEED = 1337;
const int BOARD_WIDTH = 4;
const int BOARD_HEIGHT = 4;
std::mt19937 randGen(LAB1_RAND_SEED);

#include "functions.h"

bool randomNewTile(int board[][BOARD_WIDTH]) {

    int randIdx[BOARD_WIDTH * BOARD_HEIGHT] = {};
    int numFree = 0;
    for (int i = 0; i < BOARD_WIDTH * BOARD_HEIGHT; i++) {
        if (board[i / BOARD_HEIGHT][i % BOARD_WIDTH] == 0) {
            randIdx[numFree] = i;
            numFree++;
        }
    }

    if (numFree == 0) return false;

    int selectIdx = randIdx[randGen() % numFree];
    int tile = randGen() % 10;
    board[selectIdx / BOARD_HEIGHT][selectIdx % BOARD_WIDTH] = tile ? 2 : 4;

    return true;

}


int main() {

    int board[BOARD_HEIGHT][BOARD_WIDTH] = {};
    randomNewTile(board);
    randomNewTile(board);
    
    while (true) {
        printBoard(board);
        if (checkWin(board)) {
            cout << "[*] Congratulations! You won! [*]" << endl;
            break;
        }
        cout << "=======================================================" << endl;
        cout << "Input move (w/a/s/d, e to exit): ";

        string s;
        cin >> s;
        cout << endl;
        s = s.substr(0, 1);
        if (s == "w") {
            moveBoardUp(board);
        } else if (s == "a") {
            moveBoardLeft(board);
        } else if (s == "s") {
            moveBoardDown(board);
        } else if (s == "d") {
            moveBoardRight(board);
        } else if (s != "e") {
            continue;
        } else {
            break;
        }

        if (!randomNewTile(board)) {
            cout << "[*] You lose! [*]" << endl;
            break;
        }

    }
    
}