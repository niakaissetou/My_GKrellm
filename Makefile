##
## EPITECH PROJECT, 2024
## B-PDG-300-PAR-3-1-PDGRUSH3-naira.awadin
## File description:
## Makefile
##

SRC	=	Display.cpp	\
		Modules.cpp	\
		main.cpp

OBJ	=	$(SRC:.cpp=.o)

NAME	=	MyGKrellm

CPPFLAGS =	-I./

CFLAGS =	-std=c++20 -Wall -Wextra -Werror -lncurses

all:	$(NAME)

$(NAME):	$(OBJ)
	g++ -o $(NAME) $(OBJ) $(CPPFLAGS) $(CFLAGS)

debug:	CFLAGS += -g3
debug:	all

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	re all  clean   fclean  debug