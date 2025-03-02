#include <ctype.h>
#include <endian.h>
#include <stdio.h>
#include "board/board.h"
#include "board/piece.h"

char Board[BOARD_SIZE][BOARD_SIZE];

void default_board() {
  char DefaultBoard[BOARD_SIZE][BOARD_SIZE] = {
      {W_ROOK, W_KNIGHT, W_BISHOP, W_QUEEN, W_KING, W_BISHOP, W_KNIGHT, W_ROOK},
      {W_PAWN, W_PAWN, W_PAWN, W_PAWN, W_PAWN, W_PAWN, W_PAWN, W_PAWN},
      {
          EMPTY,
          EMPTY,
          EMPTY,
          EMPTY,
          EMPTY,
          EMPTY,
          EMPTY,
          EMPTY,
      },
      {
          EMPTY,
          EMPTY,
          EMPTY,
          EMPTY,
          EMPTY,
          EMPTY,
          EMPTY,
          EMPTY,
      },
      {
          EMPTY,
          EMPTY,
          EMPTY,
          EMPTY,
          EMPTY,
          EMPTY,
          EMPTY,
          EMPTY,
      },
      {
          EMPTY,
          EMPTY,
          EMPTY,
          EMPTY,
          EMPTY,
          EMPTY,
          EMPTY,
          EMPTY,
      },
      {B_PAWN, B_PAWN, B_PAWN, B_PAWN, B_PAWN, B_PAWN, B_PAWN, B_PAWN},
      {B_ROOK, B_KNIGHT, B_BISHOP, B_QUEEN, B_KING, B_BISHOP, B_KNIGHT, B_ROOK},
  };

  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      Board[i][j] = DefaultBoard[i][j];
    }
  }
}

void print_board() {
  for (int i = BOARD_SIZE - 1; i >= 0; i--) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      printf("%c", Board[i][j]);
    }
    printf("\n");
  }
}

int rank_index(char rank) {
  return rank - '1';
}

int file_index(char file) {
  return file - 'a';
}

int is_inside(int row, int col) {
  return row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE;
}

int is_white(char piece) {
    return isupper(piece);
}

int is_black(char piece) {
    return islower(piece);
}
