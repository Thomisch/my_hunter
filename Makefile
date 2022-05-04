##
## EPITECH PROJECT, 2020
## B-MUL-100-STG-1-1-myrunner-thomas.decaudain
## File description:
## Makefile
##

SRC		=	src/*.c

OBJ		=	$(SRC:.c=.o)

NAME	=	my_hunter

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc $(SRC) -o $(NAME) -lcsfml-graphics -lcsfml-system -lcsfml-audio
	
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all