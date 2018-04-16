#include <vector>
#include <string>
#include <ncurses.h>

using namespace std;

/**
 *  1 | 2 | 3
 *  ----------
 *  4 | 5 | 6
 *  ----------
 *  7 | 8 | 9
 *
 ()
 */
class TicTacToe {
private:
    WINDOW *win { newwin(5, 10, 0, 0) };

public:
    bool running { true };
    vector<char> state {'1', '2', '3',
                        '4', '5', '6',
                        '7', '8', '9'};

    void draw() {
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

    void drawline() {
        waddch(win, '\n');
        for (int i{0}; i < 9; i++) {
            waddch(win, '-');
        }
        waddch(win, '\n');
    }



};
