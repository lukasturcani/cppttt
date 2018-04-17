#include <vector>
#include <ncurses.h>

using namespace std;

/**
 *  1 | 2 | 3
 *  ----------
 *  4 | 5 | 6
 *  ----------
 *  7 | 8 | 9
 *
 */
class TicTacToe {
private:
    vector<char> state;



    void drawline();

public:
    WINDOW *win;
    TicTacToe();
    void draw();
    void player_move();
    void bot_move();
    void check_status();
    bool running;

};
