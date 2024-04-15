##
## EPITECH PROJECT, 2024
## my_teams
## File description:
## Makefile
##

SRC		=	./main.c							\
			./client.c							\
			./socket.c							\
			./exit.c							\
			./messages.c						\
			./../server/commands/split_str.c	\
			./../file_management/read_file.c	\
			./../file_management/write_file.c	\

OBJ		=	$(SRC:.c=.o)

INCLUDE	=	-I./../../include/

FLAG	=	-Wall -Wextra -g -o

NAME	=	myteams_cli

LIB		=	-L./../../libs/myteams/ -lmyteams -I./../../include -I./../../libs/myteams/

all:	$(NAME)

$(NAME):	$(OBJ)
		gcc $(FLAG) $(NAME) $(OBJ) $(LIB)
		mv $(NAME) ../../

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f ../../$(NAME)

re: fclean all
