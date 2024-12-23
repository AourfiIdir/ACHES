#include <stdio.h>
#include "arbre.h"
#include <SDL.h>
#include "minimax.h"
#define PLAYER1 1
#define PLAYER2 0
int game_over=0;
SDL_Window * window=NULL;
SDL_Renderer* render=NULL;
int init_window(void){
    
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("test",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,500,500,SDL_WINDOW_SHOWN);
    if(window ==NULL){
        printf("window initialise is false");
        EXIT_FAILURE;
    }
    render = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
    if(render==NULL){
        printf("false declaration");
        EXIT_FAILURE;
    }

    
    return EXIT_SUCCESS;
}
void destroy_window(){
    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(window);
    SDL_Quit();

}


int main(int argc,char *argv[]){
    /*
    //creat nodes 
    Node *n11=NULL;
    n11=Creat_Node(28,11);
    Node *n12=NULL;
    n12=Creat_Node(10,12);
    Node *n13=NULL;
    n13=Creat_Node(10,13);
    Node *n21=NULL;
    n21=Creat_Node(14,21);
    Node *n22=NULL;
    n22=Creat_Node(10,22);
    Node *n23=NULL;
    n23=Creat_Node(10,23);
    Node *n31=NULL;
    n31=Creat_Node(10,31);
    Node *n32=NULL;
    n32=Creat_Node(10,32);
    Node *n33=NULL;
    n33=Creat_Node(10,33);
    //linking_all_nodes(n11,n12,n13,n21,n22,n23,n31,n32,n33);
    //LINKING THE NODES
    linking(n11->pos,n11,n12,n13,n21,n22,n23,n31,n32,n33);
    linking(n12->pos,n11,n12,n13,n21,n22,n23,n31,n32,n33);
    linking(n13->pos,n11,n12,n13,n21,n22,n23,n31,n32,n33);
    linking(n21->pos,n11,n12,n13,n21,n22,n23,n31,n32,n33);
    linking(n22->pos,n11,n12,n13,n21,n22,n23,n31,n32,n33);
    linking(n23->pos,n11,n12,n13,n21,n22,n23,n31,n32,n33);
    linking(n31->pos,n11,n12,n13,n21,n22,n23,n31,n32,n33);
    linking(n32->pos,n11,n12,n13,n21,n22,n23,n31,n32,n33);
    linking(n33->pos,n11,n12,n13,n21,n22,n23,n31,n32,n33);
    */
// Initialize SDL
    //returns 0 if there no problem with intializing the sdl
    int gaming=init_window();
    while(gaming==0){

    }
    destroy_window();
    return 0;
}