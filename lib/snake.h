#pragma once

#include <ncurses.h>
#include <vector>
#include <stdio.h>
#include <array>


struct Position{
    int x, y;
};

enum class LifeState { Alive, Dead };
enum class Direction { Up, Down, Left, Right };

class Player{
    public:
        LifeState player_state;
        Direction player_direction;
        Position player_pos;
        int player_length;
    Player();
};

class Pixel{
    public:
        int value = 0;
        int timer = 0;
        Position pix_pos;

        std::array<char, 9> point_state = { '^', 'v', '<', '>', ' ', '*', '|', '-', 'X' };
        
        Pixel();

        void print_pixel(WINDOW *win);
        void set_apple();
        void set_player(Player player);
};


class Frame{
    private:
        int w, h;
        std::vector<Pixel> pixel_list;

    public:

        Frame(Player player, int width, int height, WINDOW *win);
        void draw();  
};



void gameLoop();