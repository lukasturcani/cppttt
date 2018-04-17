#include <vector>
#include <string>
#include <ncurses.h>

#include "cppttt.h"

using namespace std;


TicTacToe::TicTacToe() :

    state {'1', '2', '3',
           '4', '5', '6',
           '7', '8', '9'},

    win { newwin(5, 10, 0, 0) },
    running { true } {};

void TicTacToe::draw() {
    for (int i{0}; i < 9; i++) {

        waddch(win, state.at(i));
        if (i == 2 || i == 5) {
            drawline();
        } else {

            waddch(win, ' ');
            waddch(win, '|');
            waddch(win, ' ');

        }
    }

    wrefresh(win);
    wmove(win, 0, 0);
}

void TicTacToe::drawline() {
    waddch(win, '\n');
    for (int i{0}; i < 9; i++) {
        waddch(win, '-');
    }
    waddch(win, '\n');
}


void TicTacToe::player_move() {
    char move { getch() };
    int move_index = move - '0';
    move_index -= 1;
    state.at(move_index) = 'x';

}


void TicTacToe::check_status() {
    int moves { 0 };
    for (auto c : state) {
        if (c == 'x' || c == 'o') moves += 1;
    }
    if (moves >= 9) {
        running = false;
    }
}


void TicTacToe::bot_move() {
    for (auto& c : state) {
        if (c != 'x' && c != 'o') {
            c = 'o';
            return;
        }
    }
}
