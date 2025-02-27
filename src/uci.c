#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game/game.h"

void uci_loop() {
  char input[512];

  while (1) {
    if (!fgets(input, sizeof(input), stdin)) {
      continue;
    }

    input[strcspn(input, "\n")] = '\0';

    if (strcmp(input, "uci") == 0) {
      printf("id name Enchessment 1.0\n");
      printf("id author Vaishakh G K\n");
      printf("uciok\n");
    } else if (strcmp(input, "ucinewgame") == 0) {
      new_game();
    } else if (strcmp(input, "isready") == 0) {
      printf("readyok\n");
    } else if (strncmp(input, "position", 8) == 0) {
    } else if (strcmp(input, "go") == 0) {
      printf("bestmove e2e4\n");
    } else if (strcmp(input, "quit") == 0) {
      break;
    }
  }
}
