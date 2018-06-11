/*
** EPITECH PROJECT, 2018
** matchstick
** File description:
** Player's turn.
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include "my.h"
#include "matchstick.h"

bool error_line(int line, board_t *board)
{
	if (line < 1 || line > board->lines) {
		my_putstr("Error: this line is out of range\n");
		return (true);
	}
	return (false);
}

bool error_matches(int matches, board_t *board)
{
	if (matches == 0) {
		my_putstr("Error: you have to remove at least one match\n");
		return (true);
	}
	else if (matches > board->max_matches) {
		my_putstr("Error: you cannot remove more than ");
		my_put_nbr(board->max_matches);
		my_putstr(" matches per turn\n");
		return (true);
	}
	return (false);
}

error_t get_arg(int *arg, board_t *board, char *mssg,
		bool (*error)(int, board_t *))
{
	char *str = NULL;
	error_t rtrn = OK;

	my_putstr(mssg);
	str = get_next_line(STDIN_FILENO);
	if (str == NULL)
		rtrn = EXIT;
	else if (!my_str_is(str, IS_NUM)) {
		my_putstr("Error: invalid input (positive number expected)\n");
		rtrn = RETRY;
	}
	else
		*arg = my_getnbr(str);
	if (rtrn == OK && error(*arg, board))
		rtrn = RETRY;
	free(str);
	return (rtrn);
}

turn_t player_turn(board_t *board)
{
	int line = 0;
	int matches = 0;
	bool retry = true;

	my_putstr("Your turn:\n");
	while (retry) {
		ANLERR(get_arg(&line, board, "Line: ", error_line));
		ANLERR(get_arg(&matches, board, "Matches: ", error_matches));
		retry = take_stickout(board, line, matches);
	}
	my_putstr("Player removed ");
	my_put_nbr(matches);
	my_putstr(" match(es) from line ");
	my_put_nbr(line);
	my_putchar('\n');
	draw_board(board);
	if (no_stick(board))
		return (IA_WIN);
	my_putchar('\n');
	return (CONTINUE);
}
