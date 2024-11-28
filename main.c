#include <stdio.h>
#include "arbre.h"
#define PLAYER1 1
#define PLAYER2 0
int game_over=0;




int main(){
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
    

    //game loop
    while(!game_over){
        
    }

}