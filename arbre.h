
#ifndef ARBRE_H
#define ARBRE_h

#include "Node.h"
Node *Creat_Node(int val,int pos);
void linking(int pos,Node *n11,Node *n12,Node *n13,Node *n21,Node *n22,Node *n23,Node *n31,Node *n32,Node *n33);
void linking_all_nodes(Node *n11,Node *n12,Node *n13,Node *n21,Node *n22,Node *n23,Node *n31,Node *n32,Node *n33);
Node *placement(int who,Node *n11,Node *n12,Node *n13,Node *n21,Node *n22,Node *n23,Node *n31,Node *n32,Node *n33);
void draw_board();
void check_logic();
void check_if_end();
#endif