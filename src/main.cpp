#include <ncurses.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <snake.h>

using namespace::std;

int main(){

    initscr();
    noecho();

    curs_set(0);
    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    WINDOW *win = newwin(yMax/1.25, xMax/1.25, yMax/8, xMax/8);
    box(win, 0, 0);

    Player player;

    Frame frame(player, int(xMax/1.25), int(yMax/1.25), win);

    wgetch(win);

    endwin();
    return 0;
}