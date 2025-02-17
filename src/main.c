#include <stdio.h>
#include <stdlib.h>
#include "game/uci.h"

int main() {
  int inputSize = 100;
  int size = 0;
  char *input = malloc(inputSize * sizeof(char));
  char ch;

  new_uci();

  while (1) {
    size = 0;

    while((ch = getchar()) != '\n' && ch != EOF) {
      input[size++] = ch;

      if (size == inputSize) {
        inputSize *= 2;

        char *temp = realloc(input, inputSize);
        if (!temp) {
          free(input);
          perror("Memory realocation failed for input");
          return 1;
        }
        input = temp;
      }
    }

    input[size] = '\0';

    printf("THE INPUT IS  %s\n", input);
  }

  return 0;
}

