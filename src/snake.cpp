#include <ncurses.h>
#include <vector>
#include <stdio.h>


struct Position{
    int x;
    int y;
};

struct Frame{
    std::vector<char> 
};

class Player{
    public:
        Position player_pos;
        

        Player(){

        }
};

class Screen {
    private:
        int w;
        int h;
        int posx;
        int posy;

    public:
        std::vector<char> screen;

        Screen(int width, int height, std::vector<char> &new_screen, Position &player_pos){
            w = width;
            h = height;
            screen = new_screen;

            posx = player_pos.x;
            posy = player_pos.y;
        }

        void display(){
            for(int i=0; i<w; i++){
                for(int j=0; j<h; j++){
                    if (posx == i && posy == j){
                        printf("%c", screen[(i*w+1) * j]);
                    }
                    else{
                        printf(" ");
                    }
                }
                printf("\n");
            }
        }
};


class Apples {
    public:
        int* apples;  

        Apples(int width, int height){
            apples = new int[width*height];

        }
        ~Apples(){
            delete[] apples;
        }
};

void gameLoop(Screen game_screen, Position &player_pos){
    
    
    game_screen.display();
}