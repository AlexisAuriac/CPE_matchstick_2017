/*
** EPITECH PROJECT, 2018
** matchsticks
** File description:
** Unitests for board.c.
*/

#include <stdbool.h>
#include <criterion/criterion.h>
#include "matchstick.h"

Test(board, init_board)
{
	board_t board;

	init_board(&board, 3, 2);
	cr_assert_eq(board.lines, 3);
	cr_assert_eq(board.max_matches, 2);
	cr_assert_eq(board.map[0], 1);
	cr_assert_eq(board.map[1], 3);
	cr_assert_eq(board.map[2], 5);
	free(board.map);
}

Test(board, take_stickout)
{
	board_t board;

	init_board(&board, 3, 5);
	cr_assert_eq(take_stickout(&board, 3, 2), false);
	cr_assert_eq(board.map[2], 3);
	cr_assert_eq(take_stickout(&board, 3, 4), true);
	cr_assert_eq(board.map[2], 3);
}

Test(board, no_stick)
{
	board_t board;

	init_board(&board, 3, 2);
	cr_assert_eq(no_stick(&board), false);
	for (int i = 0 ; i < 3 ; ++i)
		board.map[i] = 0;
	cr_assert_eq(no_stick(&board), true);
}
