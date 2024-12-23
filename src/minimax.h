#ifndef minimax_h
#define minimax_h
#include "arbre.h"
void board_matrix(int matrix[3][3], Node *n11, Node *n12, Node *n13, Node *n21, Node *n22, Node *n23, Node *n31, Node *n32, Node *n33);
void get_best_move(int matrix[3][3], int *best_row, int *best_col);
int minimaxe(int matrix[3][3], bool maximizer);
void get_possible_move(int matrix[3][3], int list[9][2], int *count);
int end_game(int matrix[3][3], int who1, int who2);
void placement_ia(int where,int who, Node *n11, Node *n12, Node *n13, Node *n21, Node *n22, Node *n23, Node *n31, Node *n32, Node *n33);
#endif