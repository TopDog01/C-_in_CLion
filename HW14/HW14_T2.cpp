#include <iostream>
using namespace std;

void printBoard(char board [3] [3]) {
    cout << "Current Board:\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << board[i] [j];
            if (j < 2) cout << "|";
        }
        cout << endl;
        if (i < 2) cout << "-----\n";
    }
}

bool checkWinner(char board [3] [3]) {
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') ||
            (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')) {
            return true;
        }
    }
    return false;
}

int main() {
    char board[3] [3];
    bool places[3] [3] = {false};
    int moves = 0;
    char currentPlayer = 'X';

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i] [j] = ' ';
        }
    }

    while (moves < 9) {
        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row and column: 0-2): ";
        cin >> row >> col;

        if ( row < 0 || row > 2 || col < 0 || col > 2 || places[row] [col]) {
            cout << "Invalid move. Try Again.\n";
            continue;
        }

        board[row] [col] = currentPlayer;
        places[row] [col] = true;
        moves++;

        printBoard(board);

        if (checkWinner(board)) {
            cout << "Player " << currentPlayer << " wins!\n";
            return 0;1
        }

        currentPlayer = (currentPlayer == 'X') ? '0' : 'X';
    }

    cout << "It's a draw!\n";
    return 0;
}