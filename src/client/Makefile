##
## EPITECH PROJECT, 2024
## my_teams
## File description:
## Makefile
##

SRC			=	./main.c							\
				./client.c							\
				./socket.c							\
				./exit.c							\
				./checkers.c						\
				./message/messages.c				\
				./message/manage_create_message.c	\
				./message/parser.c					\
				./../server/commands/split_str.c	\
				./../file_management/read_file.c	\
				./../file_management/write_file.c	\

OBJ			=	$(SRC:.c=.o)

INCLUDE		=	-I./../../include/ -I./../../libs/myteams/

FLAG		=	-Wall -Wextra -g $(INCLUDE)

NAME		=	myteams_cli

SHARE_LIB	=	-L../../libs/myteams/ -lmyteams

all:	$(NAME)

$(NAME):	$(OBJ)
		gcc $(FLAG) -o $(NAME) $(OBJ) $(SHARE_LIB) -luuid
		mv $(NAME) ../../

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f ../../$(NAME)

re: fclean all
