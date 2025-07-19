#include <ncurses.h>
#include <vector>
#include <stdio.h>
#include <array>
#include <unistd.h>
#include "snake.h"


bool Position::operator==(Position &other){
    return x == other.x && y == other.y;
}

Player::Player()
{
}

void Player::move(){
    if(player_direction == Direction::Up){
        player_pos.y -= 1;
    }
    else if (player_direction == Direction::Down){
        player_pos.y += 1;
    }
    else if (player_direction == Direction::Right){
        player_pos.x += 1;
    }
    else if (player_direction == Direction::Left){
        player_pos.x -= 1;
    }
}

void Pixel::print_pixel(WINDOW *win){
    
    if(timer > 0){
        timer -= 1;
        if(timer <= 0){
            value = 4;
        }
    } 
    mvwaddch(win, pix_pos.y, pix_pos.x, point_state[value]);
    
}

Pixel::Pixel(){
}

void Pixel::set_apple(){
    value = 5;
    // fill with function that pushbacks a position vector for all pixels not
    // with player head or tail or apple, chose random one, set a new apple
    // call at start with x apples, call again every time an apple gets eaten
}

void Frame::initial_apples(){
    
}

void Frame::add_apple(){

}



void Pixel::set_player(Player player){
    value = static_cast<int>(player.player_direction);

    if(player.player_state == LifeState::Dead){
        value = 8;
    }
}

// ——— Frame ———————————————————————
Frame::Frame(int width, int height, WINDOW* win)
{
    w = width - 2;
    h = height -2;
    window = win;
    
    current_player.player_pos.x = int(w/2);
    current_player.player_pos.y = int(h/2);
    
    for(int i = 1; i < h+1; i++){
        for (int j = 1; j < w+1; j++){
            Pixel new_pixel;
            new_pixel.pix_pos.y = i;
            new_pixel.pix_pos.x = j;
            pixel_list.push_back(new_pixel);
        }
    }
}

void Frame::draw(){
    current_player.move();

    for(int i = 0; i < pixel_list.size(); i++){
        if(pixel_list[i].value <= int(Direction::Right)){
            int tail_new = int(current_player.player_direction);
            tail_new = int(tail_new / 2) + 6;
            pixel_list[i].value = tail_new;
        }
        
        if(current_player.player_pos == pixel_list[i].pix_pos){
            pixel_list[i].timer = current_player.player_length;
            pixel_list[i].value = int(current_player.player_direction);
        }

        pixel_list[i].print_pixel(window);
    }
}

void gameLoop(Frame &frame){
    int input;
    int temp = 0;
    wtimeout(frame.window, 200);
    while(true){
        mvwprintw(frame.window, 0, 0, "%d", temp);
        input = wgetch(frame.window);

        switch (input)
        {
        case 'w':
            frame.current_player.player_direction = Direction::Up;
            break;
        case 's':
            frame.current_player.player_direction = Direction::Down;
            break;
        case 'd':
            frame.current_player.player_direction = Direction::Right;
            break;
        case 'a':
            frame.current_player.player_direction = Direction::Left;
            break;
        case 'q':
            return;
        default:
            break;
        }

        temp ++;
        frame.draw();
    }
}
