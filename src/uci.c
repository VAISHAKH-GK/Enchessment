#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game/uci.h"
#include "board/board.h"
#include "game/game.h"

void uci_loop() {
  char input[512];

  while (1) {
    if (!fgets(input, sizeof(input), stdin)) {
      continue;
    }

    input[strcspn(input, "\n")] = '\0';

    char *command = strtok(input, " ");

    if (strcmp(command, "uci") == 0) {
      printf("id name Enchessment 1.0\n");
      printf("id author Vaishakh G K\n");
      printf("uciok\n");
    } else if (strcmp(command, "ucinewgame") == 0) {
      new_game();
    } else if (strcmp(command, "isready") == 0) {
      printf("readyok\n");
    } else if (strcmp(command, "position") == 0) {
      char *arg = strtok(NULL, "");
      uci_position(arg);
    } else if (strcmp(input, "go") == 0) {
      printf("bestmove e2e4\n");
    } else if (strcmp(input, "quit") == 0) {
      break;
    }
  }
}

void uci_position(char *pos) {
  pos = strtok(pos, " ");
  if (strcmp(pos, "startpos") == 0) {
    default_board();
    char *next = strtok(NULL, " ");
    if (strcmp(next, "moves") == 0) {
      next = strtok(NULL, " ");
      while (next) {
        make_move(next);
        next = strtok(NULL, " ");
      }
    }
  }
}
