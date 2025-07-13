#include <ncurses.h>
#include <vector>
#include <stdio.h>
#include <array>

struct Position{
    int x;
    int y;
};

struct Pixel{
    int value = 0;
    int timer = 0;

    char point_state[8] = { ' ', '*', '>', '<', '^', 'v', '|', '-' };
    
    void print_pixel(){
        
        printf("%c", point_state[value]);
        
        if(timer > 0){
            timer -= 1;
        } 
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
        int w;
        int h;
        std::vector<Pixel> pixel_list;

    public:

        Frame(Player player, int width, int height){
            h = height;
            w = width;
            pixel_list.resize(w*h);


        }

        char grid_char(int point_state){

            if (point_state == 0){
                return ' ';
            }
            
        }

        void draw(){

        }    
};



void gameLoop(){
    
}