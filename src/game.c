#include "game/uci.h"
#include "game/game.h"
#include "board/board.h"

int whiteCastle;
int blackCastle;

int repeat;
int fiftyMove;

char turn;

void new_game() {
  reset_board();

  whiteCastle = 0;
  blackCastle = 0;

  repeat = 0;
  fiftyMove = 0;

  turn = WHITE;

  print_board();
}
