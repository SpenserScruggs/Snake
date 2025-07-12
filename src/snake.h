#ifndef snake
#define snake

#include <ncurses.h>
#include <stdio.h>

struct Position{};

class Screen{Screen(int width, int height, Position &player_pos);};
class Apples{};


void gameLoop(Screen game_screen, Position &player_pos);

#endif
