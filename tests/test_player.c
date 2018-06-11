/*
** EPITECH PROJECT, 2018
** matchstick
** File description:
** Tests for player.c.
*/

#include <stdbool.h>
#include <criterion/criterion.h>
#include "matchstick.h"

Test(player, error_line)
{
	board_t board;

	init_board(&board, 3, 3);
	cr_assert_eq(error_line(0, &board), true);
	cr_assert_eq(error_line(4, &board), true);
	cr_assert_eq(error_line(2, &board), false);
}

Test(player, error_matches)
{
	board_t board;

	init_board(&board, 3, 3);
	cr_assert_eq(error_matches(0, &board), true);
	cr_assert_eq(error_matches(4, &board), true);
	cr_assert_eq(error_matches(2, &board), false);
}
