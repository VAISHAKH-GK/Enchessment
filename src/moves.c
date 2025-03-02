#include "game/moves.h"
#include "board/board.h"
#include "board/piece.h"
#include "game/game.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void make_move(char *move) {
  int from_file = file_index(move[0]);
  int from_rank = rank_index(move[1]);

  int to_file = file_index(move[2]);
  int to_rank = rank_index(move[3]);

  char piece = Board[from_rank][from_file];
  printf("piece is %c\n", piece);

  Board[from_rank][from_file] = EMPTY;
  Board[to_rank][to_file] = piece;

  if (turn == WHITE) {
    turn = BLACK;
    return;
  }

  turn = WHITE;
}

int generate_pawn_moves(int row, int col, char moves[][6]) {
  int count = 0;
  int direction = turn == WHITE ? 1 : -1;
  int new_row = row + direction;

  if (is_inside(new_row, col) && Board[new_row][col] == EMPTY) {
    sprintf(moves[count++], "%c%c%c%c", 'a' + col, '1' + row, 'a' + col,
            '1' + new_row);
  }

  if ((turn == WHITE && row == 1) || (turn == BLACK && row == 6)) {
    int second_row = row + 2 * direction;
    if (is_inside(second_row, col) && Board[second_row][col] == EMPTY &&
        Board[new_row][col] == EMPTY) {
      sprintf(moves[count++], "%c%c%c%c", 'a' + col, '1' + row, 'a' + col,
              '1' + second_row);
    }
  }

  return count;
}

int generate_knight_moves(int row, int col, char moves[][6]) {
  int count = 0;
  int knight_moves[8][2] = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1},
                            {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};

  for (int i = 0; i < 8; i++) {
    int new_row = row + knight_moves[i][0];
    int new_col = col + knight_moves[i][1];

    if (is_inside(new_row, new_col) &&
        (Board[new_row][new_col] == EMPTY ||
         (turn == WHITE ? is_black(Board[new_row][new_col])
                        : is_white(Board[new_row][new_col])))) {
      sprintf(moves[count++], "%c%c%c%c", 'a' + col, '1' + row, 'a' + new_col,
              '1' + new_row);
    }
  }

  return count;
}

int generate_bishop_moves(int row, int col, char moves[][6]) {
  int count = 0;
  int directions[4][2] = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

  for (int i = 0; i < 4; i++) {
    int new_row = row + directions[i][0];
    int new_col = col + directions[i][1];

    while (is_inside(new_row, new_col)) {
      if (Board[new_row][new_col] == EMPTY) {
        sprintf(moves[count++], "%c%c%c%c", 'a' + col, '1' + row, 'a' + new_col,
                '1' + new_row);
      } else if (turn == WHITE ? is_black(Board[new_row][new_col])
                               : is_white(Board[new_row][new_col])) {
        sprintf(moves[count++], "%c%c%c%c", 'a' + col, '1' + row, 'a' + new_col,
                '1' + new_row);
        break;
      } else {
        break;
      }

      new_row += directions[i][0];
      new_col += directions[i][1];
    }
  }

  return count;
}

int generate_rook_moves(int row, int col, char moves[][6]) {
    int count = 0;
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    for (int i = 0; i < 4; i++) {
        int new_row = row + directions[i][0];
        int new_col = col + directions[i][1];

        while (is_inside(new_row, new_col)) {
            if (Board[new_row][new_col] == EMPTY) {
                sprintf(moves[count++], "%c%c%c%c", 'a' + col, '1' + row, 'a' + new_col, '1' + new_row);
            } else if (turn == WHITE ? is_black(Board[new_row][new_col]) : is_white(Board[new_row][new_col])) {
                sprintf(moves[count++], "%c%c%c%c", 'a' + col, '1' + row, 'a' + new_col, '1' + new_row);
                break;
            } else {
                break;
            }

            new_row += directions[i][0];
            new_col += directions[i][1];
        }
    }

    return count;
}

void white_move() {
  char b[BOARD_SIZE][BOARD_SIZE];
  memcpy(b, Board, sizeof(b));

  char moves[100][6];
  int move_count = 0;

  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      switch (b[i][j]) {
      case W_PAWN:
        move_count += generate_pawn_moves(i, j, moves + move_count);
        break;
      case W_KNIGHT:
        move_count += generate_knight_moves(i, j, moves + move_count);
        break;
      case W_BISHOP:
        move_count += generate_bishop_moves(i, j, moves + move_count);
        break;
      case W_ROOK:
        move_count += generate_rook_moves(i, j, moves + move_count);
        break;
      }
    }
  }

  if (move_count > 0) {
    srand(time(NULL));
    int best_move = rand() % (move_count + 1);

    printf("bestmove %s\n", moves[best_move]);
    make_move(moves[best_move]);
  }
}

void black_move() {
  char b[BOARD_SIZE][BOARD_SIZE];
  memcpy(b, Board, sizeof(b));

  char moves[100][6];
  int move_count = 0;

  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      switch (b[i][j]) {
      case B_PAWN:
        move_count += generate_pawn_moves(i, j, moves + move_count);
        break;
      case B_KNIGHT:
        move_count += generate_knight_moves(i, j, moves + move_count);
        break;
      case B_BISHOP:
        move_count += generate_bishop_moves(i, j, moves + move_count);
        break;
      case B_ROOK:
        move_count += generate_rook_moves(i, j, moves + move_count);
        break;
      }
    }
  }

  if (move_count > 0) {
    srand(time(NULL));
    int best_move = rand() % (move_count + 1);

    printf("bestmove %s\n", moves[best_move]);
    make_move(moves[best_move]);
  }
}

void generate_move() {
  if (turn == WHITE) {
    white_move();
  } else {
    black_move();
  }
  print_board();
}
