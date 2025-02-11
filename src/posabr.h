#ifndef posabr_h
#define posabr_h
#include <stdio.h>
#include "main.c"
#include <stdlib.h>
#include <string.h>
typedef struct AbrNode{
    int board[3][3];
    struct AbrNode *children[9];
    int current_player;
    int nbr_child;
}AbrNode;
void init_game(AbrNode* state) ;
void get_possibilities(AbrNode* root, int pos[9][2], int* count);
void copy_board(const AbrNode* src, AbrNode* dest);
AbrNode* create_node(int player, const AbrNode* root, int x, int y);
void generate_pos_tree(AbrNode* root, int player, int depth, int max_depth);
void write_edges(FILE* file, AbrNode* node, int parent_id, int* node_id);
void export_tree_to_dot(AbrNode* root, const char* filename);
void format_board(char* buffer, int board[3][3]);
void createAdjacencyMatrix(int vertices, int edges);
#endif