/*
** EPITECH PROJECT, 2017
** matchstick
** File description:
** Structures header file.
*/

#ifndef STRUCT_H
#define STRUCT_H

typedef struct board {
	int *map;
	int lines;
	int max_matches;
}board_t;

typedef enum {
	OK,
	RETRY,
	EXIT
}error_t;

typedef enum {
	QUIT=0,
	PLAYER_WIN=1,
	IA_WIN=2,
	CONTINUE=3
}turn_t;

#endif
