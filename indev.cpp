#include <iostream>
#include <string>
#include "Board.h"
#include <iomanip>

using namespace std;

void drawHorizontalSeparater() {
    for (int i = 0; i < 5; i++) {
        cout << " ---";
    }
    cout << endl;
}

void drawSeparatedValues(int row) {
    cout << "|";

    for (int col = 0; col < 5; col++) {
        char board[row][col] = ' ';

        cout << " " << board[row][col] << " |";
    }
    cout << endl;
}

void displayBoard() {
    drawHorizontalSeparater();
    for (int row = 0; row < 5; row++) {
        drawSeparatedValues(row);
        drawHorizontalSeparater();
    }
}