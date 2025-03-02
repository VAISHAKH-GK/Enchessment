#ifndef BOARD_H
#define BOARD_H

#define BOARD_SIZE 8

extern char Board[BOARD_SIZE][BOARD_SIZE];

void default_board();
void print_board();

int rank_index(char rank);
int file_index(char file);

int is_inside(int row, int col);

#endif
