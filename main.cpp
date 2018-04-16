#include "cppttt.cpp"
#include <iostream>

int main() {

    initscr();

    TicTacToe game {};

    while (game.running) {
        game.draw();
        game.running = false;

    }

    char e;
    cin >> e;
    endwin();
    return 0;
}
