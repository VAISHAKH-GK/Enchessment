#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "game/moves.h"
#include "board/board.h"
#include "board/piece.h"
#include "game/game.h"

void make_move(char *move) {
  printf("move is - %c%c%c%c\n", move[0], move[1], move[2], move[3]);
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

    if (is_inside(new_row, new_col) && (Board[new_row][new_col] == EMPTY || (turn == WHITE ? is_black(Board[new_row][new_col]) : is_white(Board[new_row][new_col])))) {
      sprintf(moves[count++], "%c%c%c%c", 'a' + col, '1' + row, 'a' + new_col,
              '1' + new_row);
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
      }
    }
  }

  if (move_count > 0) {
    printf("bestmove %s\n", moves[0]);
    make_move(moves[0]);
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
      }
    }
  }

  if (move_count > 0) {
    printf("bestmove %s\n", moves[0]);
    make_move(moves[0]);
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
