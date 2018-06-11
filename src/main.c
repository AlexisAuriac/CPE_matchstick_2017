/*
** EPITECH PROJECT, 2017
** matchstick
** File description:
** Main file.
*/

#include <stdlib.h>
#include <time.h>
#include "my.h"
#include "matchstick.h"

int main(int ac, char **av)
{
	int lines = 0;
	int max_matches = 0;
	int win = 0;

	if (parse_arg(ac, av, &lines, &max_matches))
		return (84);
	srandom(time(NULL));
	win = matchstick(lines, max_matches);
	return (win);
}
