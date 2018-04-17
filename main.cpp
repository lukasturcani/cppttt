#include "cppttt.h"
#include <iostream>
#include <ncurses.h>

int main() {

    initscr();
    noecho();
    cbreak();
    refresh();

    TicTacToe game {};

    while (game.running) {
        game.draw();

        game.player_move();
        game.draw();
        game.check_status();
        if (!game.running) break;

        game.bot_move();
        game.draw();
        game.check_status();

    }

    char e;
    cin >> e;
    endwin();
    return 0;
}
