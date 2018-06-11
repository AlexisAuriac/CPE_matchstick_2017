/*
** EPITECH PROJECT, 2017
** matchstick
** File description:
** Macros header file.
*/

#ifndef MACROS_H
#define MACROS_H

#define ANLERR(error)			   \
	switch(error) {                    \
	case RETRY :                       \
		continue;                  \
	case EXIT :                        \
		return (QUIT);		   \
	default:                           \
		break;                     \
	}

#endif
