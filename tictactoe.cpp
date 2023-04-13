#include <iostream>
#include "board.h"
using namespace std;

int main() {
    Board board;

    bool player1 = true;
    bool done = false;

    while(!done) {
        system("clear");
        cout << board;

        if (player1) {
            bool success = false;
            while (!success) {
                int x, y;
                cout << "Player 1: ";
                cin >> x >> y;
                success = board.updateGrid(x, y, PLAYER1);
            }
        } else {
            bool success = false;
            while (!success) {
                int x, y;
                cout << "Player 2: ";
                cin >> x >> y;
                success = board.updateGrid(x, y, PLAYER2);
            }
        }
        player1 = !player1;
    }

    return 0;
}
