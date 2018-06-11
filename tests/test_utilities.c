/*
** EPITECH PROJECT, 2018
** matchsticks
** File description:
** Tests for utilities.
*/

#include <criterion/criterion.h>
#include "matchstick.h"

Test(utilities, my_randrange)
{
	cr_assert_eq(my_randrange(1, 1), 1);
}
