/*
** EPITECH PROJECT, 2018
** matchstick
** File description:
** Tests for parse_arg().
*/

#include <stdlib.h>
#include <criterion/criterion.h>
#include "my.h"
#include "matchstick.h"

Test(arg, ac)
{
	cr_assert_eq(parse_arg(2, NULL, NULL, NULL), 84);
	cr_assert_eq(parse_arg(4, NULL, NULL, NULL), 84);
}

Test(arg, av_not_numeric)
{
	char *av[3] = {NULL};
	int a;
	int b;

	av[1] = my_strdup("sd3sdfqsdfq");
	av[2] = my_strdup("4444444");
	cr_assert_eq(parse_arg(3, av, &a, &b), 84);
	my_strcpy(av[1], "3");
	my_strcpy(av[2], "dfs4");
	cr_assert_eq(parse_arg(3, av, &a, &b), 84);
	free(av[1]);
	free(av[2]);
}

Test(arg, av_lines)
{
	char *av[3] = {NULL};
	int a;
	int b;

	av[1] = my_strdup("100");
	av[2] = my_strdup("4");
	cr_assert_eq(parse_arg(3, av, &a, &b), 84);
	my_strcpy(av[1], "0");
	cr_assert_eq(parse_arg(3, av, &a, &b), 84);
	free(av[1]);
	free(av[2]);
}

Test(arg, av_max_matches)
{
	char *av[3] = {NULL};
	int a;
	int b;

	av[1] = my_strdup("10");
	av[2] = my_strdup("0");
	cr_assert_eq(parse_arg(3, av, &a, &b), 84);
	free(av[1]);
	free(av[2]);
}
