/*
** EPITECH PROJECT, 2017
** matchstick
** File description:
** Contains the prototypes of the project's functions.
*/

#ifndef MATCHSTICK_H
#define MATCHSTICK_H

#include "const.h"
#include "struct.h"
#include "macro.h"

//parse_arg.c
int parse_arg(int ac, char **av, int *lines, int *max_matches);

//utilities.c
int my_randrange(int min, int max);

//matchstick.c
int matchstick(int lines, int max_matches);

//board.c
bool init_board(board_t *board, int lines, int max_matches);
void draw_board(board_t *board);
bool take_stickout(board_t *board, int line, int matches);
bool no_stick(board_t *board);

//player.c
bool error_line(int line, board_t *board);
bool error_matches(int matches, board_t *board);
turn_t player_turn(board_t *board);

//ia.c
turn_t ia_turn(board_t *board);

#endif
