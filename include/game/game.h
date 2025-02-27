#ifndef GAME_H
#define GAME_H

#define WHITE 'W'
#define BLACK 'B'

// castle state
extern int whiteCastle;
extern int blackCastle;

extern int repeat;
extern int fiftyMove;

extern char turn;

void new_game();
void make_move(char *move);

#endif
