#include <iostream>
using namespace std;

class Board
{
private:
    static const int ROWS = 11;
    static const int COLS = 5;
    char board[ROWS][COLS];

public:
    void displayBoard();
};