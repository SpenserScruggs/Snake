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
        
        void print_pixel(){
            
            printf("%c", point_state[value]);
            
            if(timer > 0){
                timer -= 1;
            } 
        }
        void set_apple(){

        }

        void set_player(){

        }

};

enum class LifeState { Up, Down, Left, Right };
enum class Direction { Alive, Dead };

class Player{
    public:
        LifeState player_state;
        Direction player_direction;
        Position player_pos;
        int player_length;
        
        Player(){
          
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

        char grid_char(int point_state){

            if (point_state == 0){
                return ' ';
            }
            
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