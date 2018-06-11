/*
** EPITECH PROJECT, 2018
** my_screensaver
** File description:
** Generaly useful functions.
*/

#include <stdlib.h>

int my_randrange(int min, int max)
{
	int rand = 0;

	if (max == min)
		return (min);
	rand = random() % (max - min) + min;
	return (rand);
}
