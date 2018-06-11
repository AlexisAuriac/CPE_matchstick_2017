/*
** EPITECH PROJECT, 2018
** matchstick
** File description:
** Game loop.
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "matchstick.h"

void win_mssg(turn_t win)
{
	if (win == IA_WIN)
		my_putstr("Moron\n");
	else if (win == PLAYER_WIN)
		my_putstr("Player wins\n");
}

int matchstick(int lines, int max_matchs)
{
	board_t board;
	turn_t win = CONTINUE;

	if (!init_board(&board, lines, max_matchs)) {
		my_puterr("Malloc failed\n");
		return (0);
	}
	draw_board(&board);
	my_putchar('\n');
	while (win == CONTINUE) {
		win = player_turn(&board);
		if (win == CONTINUE)
			win = ia_turn(&board);
	}
	free(board.map);
	win_mssg(win);
	return (win);
}
