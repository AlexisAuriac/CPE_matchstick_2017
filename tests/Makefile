##
## EPITECH PROJECT, 2018
## matchsticks
## File description:
## Makefile for unitests.
##

SRC		=	parse_arg.c	\
			utilities.c	\
			board.c		\
			player.c	\
			ia.c

SRC_UT		=	test_arg.c	\
			test_utilities.c\
			test_board.c	\
			test_player.c

SRCS		=	$(addprefix ../src/, $(SRC))

OBJ		=	$(SRCS:.c=.o)	\
			$(SRC_UT:.c=.o)

CPPFLAGS	+=	-I../include

CFLAGS		+=	-Wall -Wextra --coverage

LDFLAGS		+=	-lcriterion -lgcov -L../lib -lmy

NAME		=	units

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)
		./$(NAME)

clean	:
		$(RM) -f $(OBJ)
		$(RM) -f $(SRCS:.c=.gcda)
		$(RM) -f $(SRCS:.c=.gcno)
		$(RM) -f $(SRC_UT:.c=.gcda)
		$(RM) -f $(SRC_UT:.c=.gcno)

fclean	:	clean
		$(RM) -f $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
