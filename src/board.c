/*
** EPITECH PROJECT, 2018
** matchstick
** File description:
** Handles the board struct.
*/

#include <stdlib.h>
#include "my.h"
#include "struct.h"

bool init_board(board_t *board, int lines, int max_matches)
{
	board->map = malloc(sizeof(int) * lines);

	if (board->map == NULL)
		return (false);
	for (int i = 0 ; i < lines ; ++i)
		board->map[i] = i * 2 + 1;
	board->lines = lines;
	board->max_matches = max_matches;
	return (true);
}

void draw_board(board_t *board)
{
	int j = 0;

	for (int i = 0 ; i < 2 * board->lines + 1 ; ++i)
		my_putchar('*');
	my_putchar('\n');
	for (int i = 0 ; i < board->lines ; ++i) {
		my_putchar('*');
		for (j = 0 ; j < board->lines - i - 1 ; ++j)
			my_putchar(' ');
		for (int k = 0 ; k < board->map[i] ; ++k, ++j)
			my_putchar('|');
		for (; j < 2 * board->lines - 1 ; ++j)
			my_putchar(' ');
		my_putstr("*\n");
	}
	for (int i = 0 ; i < 2 * board->lines + 1 ; ++i)
		my_putchar('*');
	my_putstr("\n");
}

bool take_stickout(board_t *board, int line, int matches)
{
	if (matches > board->map[line - 1]) {
		my_putstr("Error: not enough matches on this line\n");
		return (true);
	}
	board->map[line - 1] -= matches;
	return (false);
}

bool no_stick(board_t *board)
{
	for (register int i = board->lines ; i-- ;) {
		if (board->map[i])
			return (false);
	}
	return (true);
}
