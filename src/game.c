#include <stdio.h>
#include <string.h>
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

