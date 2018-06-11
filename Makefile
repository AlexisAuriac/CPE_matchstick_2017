##
## EPITECH PROJECT, 2017
## matchstick
## File description:
## Makefile for matchstick
##

SRC		=	main.c		\
			parse_arg.c	\
			utilities.c	\
			matchstick.c	\
			board.c		\
			player.c	\
			ia.c

SRCS		=	$(addprefix src/, $(SRC))

OBJ		=	$(SRCS:.c=.o)

CPPFLAGS	+=	-I include

CFLAGS		+=	-Wall -Wextra

LDFLAGS		+=      -Llib/ -lmy

NAME		=	matchstick

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

test_run:
		make -C tests/

clean	:
		rm -f $(OBJ)
		make clean -C tests

fclean	:	clean
		rm -f $(NAME)
		make fclean -C tests

re	:	fclean	all

.PHONY	:	all clean fclean re
