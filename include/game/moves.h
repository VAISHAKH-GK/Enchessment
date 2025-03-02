#ifndef MOVES_H
#define MOVES_H

void make_move(char *move);

int generate_pawn_moves(int row, int col, char moves[][6]);
int generate_knight_moves(int row, int col, char moves[][6]);
int generate_bishop_moves(int row, int col, char moves[][6]);
int generate_rook_moves(int row, int col, char moves[][6]);
int generate_queen_moves(int row, int col, char moves[][6]);
int generate_king_moves(int row, int col, char moves[][6]);

void white_move();
void black_move();
void generate_move();

#endif
