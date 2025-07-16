#include <ncurses.h>
#include <vector>
#include <stdio.h>
#include <array>
#include "snake.h"


Player::Player()
{
}

void Pixel::print_pixel(WINDOW *win){
    
    mvwaddch(win, pix_pos.x, pix_pos.y, point_state[value]);
    
    if(timer > 0){
        timer -= 1;
        if(timer == 0){
            value = 0;
        }
    } 
}

Pixel::Pixel(){

}

void Pixel::set_apple(){
    value = 1;
}


void Pixel::set_player(Player player){
    value = static_cast<int>(player.player_direction);

    if(player.player_state == LifeState::Dead){
        value = 8;
    }
}

// ——— Frame ———————————————————————
Frame::Frame(Player player, int width, int height, WINDOW* /*win*/)
{
    w = width - 2;
    h = height -2;
    pixel_list.resize(w * h);
}

void Frame::draw(){

}

void gameLoop(){

}
