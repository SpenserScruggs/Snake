#pragma once

#include <ncurses.h>
#include <vector>
#include <stdio.h>
#include <array>


struct Position{
    int x, y;
    bool operator==(Position &other);
};

enum class LifeState { Alive, Dead };
enum class Direction { Up=0, Down=1, Left=2, Right=3 };

class Player{
public:
    LifeState player_state;
    Direction player_direction = Direction::Up;
    Position player_pos;
    int player_length = 15;

    Player();
    void move();
};

class Pixel{
public:
    int value = 4;
    int timer = 0;
    Position pix_pos;

    std::array<char, 9> point_state = { '^', 'v', '<', '>', ' ', '*', '|', '-', 'X' };
    
    Pixel();

    void print_pixel(WINDOW *win);
    void set_player(Player player);
};


class Frame{
private:
    int w, h;
    std::vector<Pixel> pixel_list;
    
public:
    WINDOW* window;
    Player current_player;

    Frame(int width, int height, WINDOW *win);
    void draw(); 
    void initial_apples(); 
    void add_apple(std::vector<Pixel> &pixels);
};



void gameLoop(Frame &frame);