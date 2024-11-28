#include "arbre.h"
#include <stdio.h>
#include <stdlib.h>

Node *Creat_Node(int val,int pos){
    Node *q=NULL;
    q = (Node*)malloc(sizeof(Node));
    q->val=val;
    q->pos = pos;
    return q;
}
void linking_all_nodes(Node *n11,Node *n12,Node *n13,Node *n21,Node *n22,Node *n23,Node *n31,Node *n32,Node *n33){
    linking(n11->pos,n11,n12,n13,n21,n22,n23,n31,n32,n33);
    linking(n12->pos,n11,n12,n13,n21,n22,n23,n31,n32,n33);
    linking(n13->pos,n11,n12,n13,n21,n22,n23,n31,n32,n33);
    linking(n21->pos,n11,n12,n13,n21,n22,n23,n31,n32,n33);
    linking(n22->pos,n11,n12,n13,n21,n22,n23,n31,n32,n33);
    linking(n23->pos,n11,n12,n13,n21,n22,n23,n31,n32,n33);
    linking(n31->pos,n11,n12,n13,n21,n22,n23,n31,n32,n33);
    linking(n32->pos,n11,n12,n13,n21,n22,n23,n31,n32,n33);
    linking(n33->pos,n11,n12,n13,n21,n22,n23,n31,n32,n33);
}
void linking(int pos,Node *n11,Node *n12,Node *n13,Node *n21,Node *n22,Node *n23,Node *n31,Node *n32,Node *n33){
    switch (pos){
        case 11:
            n11->right=n12;
            n11->down=n21;
            n11->rd=n22;
            n11->ld=NULL;
            n11->left=NULL;
            n11->up=NULL;
            n11->lup=NULL;
            n11->rup=NULL;
            
            break;
        case 12:
            n12->right=n13;
            n12->down=n22;
            n12->rd=NULL;
            n12->ld=NULL;
            n12->left=n11;
            n12->up=NULL;
            n12->lup=NULL;
            n12->rup=NULL;
            break;
        case 13:
            n13->right=NULL;
            n13->down=n23;
            n13->rd=NULL;
            n13->ld=n22;
            n13->left=n12;
            n13->up=NULL;
            n13->lup=NULL;
            n13->rup=NULL;
            break;
        case 21:
            n21->right=n22;
            n21->down=n31;
            n21->rd=NULL;
            n21->ld=NULL;
            n21->left=NULL;
            n21->up=n11;
            n21->lup=NULL;
            n21->rup=NULL;
            break;
        case 22:
            n22->right=n23;
            n22->down=n32;
            n22->rd=n33;
            n22->ld=n31;
            n22->left=n21;
            n22->up=n12;
            n22->lup=n11;
            n22->rup=n13;
            break;
        case 23:
            n23->right=NULL;
            n23->down=n33;
            n23->rd=NULL;
            n23->ld=NULL;
            n23->left=n22;
            n23->up=n13;
            n23->lup=NULL;
            n23->rup=NULL;
            break;
        case 31:
            n31->right=n32;
            n31->down=NULL;
            n31->rd=NULL;
            n31->ld=NULL;
            n31->left=NULL;
            n31->up=n21;
            n31->lup=NULL;
            n31->rup=n22;
            break;
        case 32:
            n32->right=n33;
            n32->down=NULL;
            n32->rd=NULL;
            n32->ld=NULL;
            n32->left=n31;
            n32->up=n22;
            n32->lup=NULL;
            n32->rup=NULL;
            break;
        case 33:
            n33->right=NULL;
            n33->down=NULL;
            n33->rd=NULL;
            n33->ld=NULL;
            n33->left=n32;
            n33->up=n23;
            n33->lup=n22;
            n33->rup=NULL;
            break;
        
    }
}
Node *placement(int who,Node *n11,Node *n12,Node *n13,Node *n21,Node *n22,Node *n23,Node *n31,Node *n32,Node *n33){
    int where=0;
    printf("where to play , player");
    scanf("%d",where);
    if(where==n11->pos){
        n11->val=who;
    }
    else if(where==n12->pos){
        n12->val=who;
    }
    else if(where==n13->pos){
        n13->val=who;
    }
    else if(where==n21->pos){
        n21->val=who;
    }
    else if(where==n22->pos){
        n22->val=who;
    }
    else if(where==n23->pos){
        n23->val=who;
    }
    else if(where==n31->pos){
        n31->val=who;
    }
    else if(where==n32->pos){
        n32->val=who;
    }
    else if(where==n33->pos){
        n33->val=who;
    }
}
void draw_board(){
    
};
void check_logic(){

};
void check_if_end(){

};
void deplacement(){

};
void check_if_solid_movement(){
    
};