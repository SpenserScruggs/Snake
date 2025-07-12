#include <stdlib.h>
#include <stdio.h>
#include <array>
#include <ncurses.h>

class Screen {
    public:
        int w;
        int h;
        int posx;
        int posy;

        Screen(int width, int height, std::array<int, 2> &player_xypos){
            w = width;
            h = height;
            posx = player_xypos[0];
            posy = player_xypos[1];
        }

        void display(){
            for(int i=0; i<w; i++){
                for(int j=0; j<h; j++){
                    if (posx == i && posy == j){
                        printf("M");
                    }
                    else{
                        printf(" ");
                    }
                }
                printf("\n");
            }
        }  
};

class apples {
    public:
        int max_apples;

        std::array<float, 2> newthing;
};


int main(){

    std::array<int, 2> player_pos = { 9, 0 };

    Screen my_screen(10, 10, player_pos);

    my_screen.display();


    return 0;
}