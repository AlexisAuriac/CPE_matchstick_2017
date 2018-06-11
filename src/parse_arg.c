/*
** EPITECH PROJECT, 2018
** matchstick
** File description:
** Parses the arguments of the program.
*/

#include "my.h"

int parse_arg(int ac, char **av, int *lines, int *max_matches)
{
	if (ac != 3) {
		my_putstr("You must give 2 arguments\n");
		return (84);
	}
	else if (!my_str_is(av[1], IS_NUM) || !my_str_is(av[2], IS_NUM)) {
		my_putstr("Arguments must be numbers\n");
		return (84);
	}
	*lines = my_getnbr(av[1]);
	if (*lines <= 1 || *lines >= 100) {
		my_putstr("The board must be from 1 to 100 lines\n");
		return (84);
	}
	*max_matches = my_getnbr(av[2]);
	if (*max_matches <= 0) {
		my_putstr("You must be able to take more than 0 match\n");
		return (84);
	}
	return (0);
}
