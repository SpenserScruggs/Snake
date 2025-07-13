#ifndef snake
#define snake

#include <ncurses.h>
#include <vector>
#include <stdio.h>
#include <array>

struct Position{
    int x, y;
};

class Pixel{
    public:
        int value = 0;
        int timer = 0;

        std::array<char, 9> point_state = { ' ', '*', '>', '<', '^', 'v', '|', '-', 'X' };
        
        void print_pixel();
        void set_apple();
        void set_player();

};

enum class LifeState { Up, Down, Left, Right };
enum class Direction { Alive, Dead };

class Player{
    public:
        LifeState player_state;
        Direction player_direction;
        Position player_pos;
        int player_length;
        
        Player();
};

class Frame{
    private:
        int w, h;
        std::vector<Pixel> pixel_list;

    public:

        Frame(Player player, int width, int height, WINDOW *win);

        char grid_char(int point_state);

        void draw(); 
};


void gameLoop();

#endif
