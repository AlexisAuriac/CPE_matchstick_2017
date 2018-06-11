/*
** EPITECH PROJECT, 2018
** matchstick
** File description:
** IA's turn.
*/

#include "my.h"
#include "matchstick.h"

void choose_move(board_t *board, int *line, int *matches)
{
	do {
		*line = my_randrange(1, board->lines + 1);
	} while (board->map[*line - 1] == 0);
	if (board->max_matches > board->map[*line - 1])
		*matches = my_randrange(1, board->map[*line - 1] + 1);
	else
		*matches = my_randrange(1, board->max_matches + 1);
}

turn_t ia_turn(board_t *board)
{
	int line = 0;
	int matches = 0;

	my_putstr("AI's turn...\n");
	choose_move(board, &line, &matches);
	take_stickout(board, line, matches);
	my_putstr("AI removed ");
	my_put_nbr(matches);
	my_putstr(" match(es) from line ");
	my_put_nbr(line);
	my_putchar('\n');
	draw_board(board);
	if (no_stick(board))
		return (PLAYER_WIN);
	my_putchar('\n');
	return (CONTINUE);
}