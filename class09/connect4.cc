#include <iostream>
#include <string>

using namespace std;

const int ROWS = 6;
const int COLS = 7;

void print_board(char board[][COLS]) {
    cout << "--------------" << endl;
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            cout << board[row][col] << " ";
        }
        cout << endl;
    }
    cout << "--------------" << endl;
}

/**
 * @brief Attempt to play piece of given color in column col.
 * If column is full, return false (i.e. didn't make the play).
 * Otherwise, return true, and alter the 2D array!
 * 
 * @param board - 2D array representing Connect Four
 * @param col - column to play in
 * @param color - color of the piece to play
 * @return true - if the play happened successfully
 * @return false - if the column was already full
 */
bool play(char board[][COLS], int col, char color) {
    for (int row = ROWS - 1; row >= 0; row--) {
        if (board[row][col] == '.') {
            board[row][col] = color;
            return true;
        }
    }
    return false;
}

int main() {

    char connect4[ROWS][COLS]  =  {{'.', '.', '.', '.', '.', 'b', '.'},
                                   {'.', '.', '.', '.', '.', 'b', 'b'},
                                   {'r', '.', '.', 'b', '.', 'r', 'r'},
                                   {'b', 'b', '.', 'r', '.', 'b', 'b'},
                                   {'r', 'r', '.', 'r', 'b', 'r', 'b'},
                                   {'r', 'b', '.', 'r', 'b', 'r', 'r'}};

    // cout << connect4 << endl; // prints address in memory
    //cout << connect4[3] << endl; // also prints address in memory

    print_board(connect4);

    // // Not an out of bounds error, but gives the first value in the next row
    // cout << connect4[1][7] << endl;
    // cout << "after end of last row: " << connect4[6][7] << endl;

    // // Print the entire 2D array in non-nested for loop:
    // // This is just to show you how it's stored; you should use nested loops!
    // for (int i = 0; i < ROWS * COLS; i++) {
    //     cout << connect4[0][i];
    // }
    // cout << endl;

    bool played_piece;
    played_piece = play(connect4, 3, 'b');
    print_board(connect4);
    cout << "played? " << played_piece << endl;

    played_piece = play(connect4, 5, 'r');
    print_board(connect4);
    cout << "played? " << played_piece << endl;

}
