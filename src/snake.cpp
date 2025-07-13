#include <ncurses.h>
#include <vector>
#include <stdio.h>
#include <array>

struct Position{
    int x;
    int y;
};

struct Pixel{
    int value;
    bool not_empty = false;
    
    char point_state[8] = { ' ', '*', '>', '<', '^', 'v', '|', '-' };

    void print_pixel(){
        printf("%c", point_state[value]);
    }
};

class Frame{
    private:
        int w;
        int h;

    public:
        std::vector<char> frame_chars;
        std::vector<std::array<int, 2>> point_data;

        Frame(Player player, int width, int height){
            h = height;
            w = width;
        }

        void frame_initialize(){

        }

        char grid_char(int point_state){

            if (point_state == 0){
                return ' ';
            }
            
        }

        void draw(){

        }    
};

class Player{
    public:
        Position player_pos;
        int player_length;
        bool player_state;
        int player_direction;
        
        Player(){
            
        }
        
};


void gameLoop(){
    
    
    
}