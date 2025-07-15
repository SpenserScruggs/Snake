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
        
        Player(){
          
        }
};

class Pixel{
    public:
        int value = 0;
        int timer = 0;
        Position pix_pos;

        std::array<char, 9> point_state = { '^', 'v', '<', '>', ' ', '*', '|', '-', 'X' };
        
        Pixel(){

        }

        void print_pixel(WINDOW *win){
            
            mvwaddch(win, pix_pos.x, pix_pos.y, point_state[value]);
            
            if(timer > 0){
                timer -= 1;
                if(timer == 0){
                    value = 0;
                }
            } 
        }
        void set_apple(){
            value = 1;
        }

        void set_player(Player player){
            value = static_cast<int>(player.player_direction);

            if(player.player_state == LifeState::Dead){
                value = 8;
            }
        }
};


class Frame{
    private:
        int w, h;
        std::vector<Pixel> pixel_list;

    public:

        Frame(Player player, int width, int height, WINDOW *win){
            h = height-2;
            w = width-2;
            pixel_list.resize(w*h);


        }

        void draw(){
            for(int i=0; i<pixel_list.size(); i++){

                if(i%w == 0){

                }
            }
        }    
};



void gameLoop(){
    
}
