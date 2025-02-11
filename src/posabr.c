#include "posabr.h"
// Initialization
void init_game(AbrNode* state) {
    memset(state->board, 0, sizeof(state->board));
    state->current_player = PLAYER1;
    state->nbr_child = 0;
    for (int i = 0; i < 9; i++) {
        state->children[i] = NULL;
    }
}

void get_possibilities(AbrNode* root, int pos[9][2], int* count) {
    int k = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (root->board[i][j] == 0) {
                pos[k][0] = i;
                pos[k][1] = j;
                k++;
            }
        }
    }
    *count = k; // Update the count of possible moves
}

void copy_board(const AbrNode* src, AbrNode* dest) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            dest->board[i][j] = src->board[i][j];
        }
    }
}

AbrNode* create_node(int player, const AbrNode* root, int x, int y) {
    AbrNode* temp = (AbrNode*)malloc(sizeof(AbrNode));
    if (!temp) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    copy_board(root, temp); // Copy the board from the root
    temp->board[x][y] = player; // Place the move
    temp->current_player = player;
    temp->nbr_child = 0;
    for (int i = 0; i < 9; i++) {
        temp->children[i] = NULL;
    }
    return temp;
}

void generate_pos_tree(AbrNode* root, int player, int depth, int max_depth) {
    // Base case: Stop recursion if depth exceeds max_depth
    if (depth > max_depth) {
        return;
    }

    int pos[9][2];
    int count = 0;
    get_possibilities(root, pos, &count); // Get all possible moves

    // Iterate through available positions and create child nodes
    for (int i = 0; i < count; i++) {
        int x = pos[i][0];
        int y = pos[i][1];
        root->children[root->nbr_child] = create_node(player, root, x, y);
        root->nbr_child++;
    }

    // Recursively generate the tree for each child
    for (int i = 0; i < root->nbr_child; i++) {
        generate_pos_tree(root->children[i], -player, depth + 1, max_depth);
    }
}

// helper function to format the board state as a string
void format_board(char* buffer, int board[3][3]) {
    int pos = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            pos += sprintf(buffer + pos, "%d", board[i][j]);
            if (j < 2) pos += sprintf(buffer + pos, " "); // Space between columns
        }
        if (i < 2) pos += sprintf(buffer + pos, "\\n"); // Newline between rows
    }
}

// Recursive helper function to write nodes and edges
void write_edges(FILE* file, AbrNode* node, int parent_id, int* node_id) {
    if (!node) return;

    int current_id = (*node_id)++;

    // Format the board as a string for the label
    char board_str[128];
    format_board(board_str, node->board);

    // Write the current node with its board state as a label
    fprintf(file, "    node%d [label=\"{Player: %d|%s}\"];\n", current_id, node->current_player, board_str);

    // Add an edge from the parent node to the current node
    if (parent_id >= 0) {
        fprintf(file, "    node%d -> node%d;\n", parent_id, current_id);
    }

    // Recurse for all children
    for (int i = 0; i < node->nbr_child; i++) {
        write_edges(file, node->children[i], current_id, node_id);
    }
}

// Main function to export the tree to a DOT file
void export_tree_to_dot(AbrNode* root, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        perror("Unable to open file");
        return;
    }

    fprintf(file, "digraph GameTree {\n");
    fprintf(file, "    node [shape=record];\n"); // Use record shape for structured labels

    int node_id = 0; // Start with the root node
    write_edges(file, root, -1, &node_id); // Call the helper function

    fprintf(file, "}\n");
    fclose(file);

    printf("DOT file generated: %s\n", filename);
}

//function to create the adjacency matrix
void createAdjacencyMatrix(int vertices, int edges) {
    int i, j, u, v;

    // Allouer dynamiquement une matrice 2D
    int** adjacencyMatrix = (int**)malloc(vertices * sizeof(int*));
    for (i = 0; i < vertices; i++) {
        adjacencyMatrix[i] = (int*)malloc(vertices * sizeof(int));
    }

    // Initialiser la matrice avec des zéros
    for (i = 0; i < vertices; i++) {
        for (j = 0; j < vertices; j++) {
            adjacencyMatrix[i][j] = 0;
        }
    }

    printf("Entrez les paires de sommets connectés par des arêtes (u, v):\n");
    for (i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        adjacencyMatrix[u][v] = 1;
        adjacencyMatrix[v][u] = 1; // Ajouter cette ligne seulement pour un graphe non orienté
    }

    printf("Matrice d'adjacence:\n");
    for (i = 0; i < vertices; i++) {
        for (j = 0; j < vertices; j++) {
            printf("%d ", adjacencyMatrix[i][j]);
        }
        printf("\n");
    }

    // Libérer la mémoire
    for (i = 0; i < vertices; i++) {
        free(adjacencyMatrix[i]);
    }
    free(adjacencyMatrix);
}
