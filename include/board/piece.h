#ifndef PIECE_H
#define PIECE_H

// White pieces
#define W_PAWN 'P'
#define W_KNIGHT 'N'
#define W_BISHOP 'B'
#define W_ROOK 'R'
#define W_QUEEN 'Q'
#define W_KING 'K'

// Black pieces
#define B_PAWN 'p'
#define B_KNIGHT 'n'
#define B_BISHOP 'b'
#define B_ROOK 'r'
#define B_QUEEN 'q'
#define B_KING 'k'

#define EMPTY '_'

int is_black(char piece);
int is_white(char piece);

#endif
