#include <stdio.h>
#include "game/uci.h"
#include "game/game.h"
#include "board/board.h"
#include "board/piece.h"

int whiteCastle;
int blackCastle;

int repeat;
int fiftyMove;

char turn;

void new_game() {
  default_board();

  whiteCastle = 0;
  blackCastle = 0;

  repeat = 0;
  fiftyMove = 0;

  turn = WHITE;

  print_board();
}

void make_move(char *move) {
  int from_file = file_index(move[0]);
  int from_rank = rank_index(move[1]);

  int to_file = file_index(move[2]);
  int to_rank = rank_index(move[3]);

  char piece = Board[from_rank][from_file];

  Board[from_rank][from_file] = EMPTY;
  Board[to_rank][to_file] = piece;
}
