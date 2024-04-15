##
## EPITECH PROJECT, 2024
## my_teams
## File description:
## Makefile
##

SRC		=	./main.c								\
			./create/socket.c						\
			./create/exit.c							\
			./create/server.c						\
			./client_connection/client_management.c	\
			./client_connection/connection.c		\
			./error_handling/error_handling.c		\
			./commands/command_handling.c			\
			./commands/command_checkers.c			\
			./commands/split_str.c					\
			./commands/manage_context.c				\
			./queue/manage_user_log.c				\
			./queue/manage_uuid.c					\
			./queue/manage_create.c					\
			./queue/manage_teams.c					\
			./queue/manage_channels.c				\
			./queue/manage_threads.c				\
			./queue/manage_replies.c				\
			./queue/checkers.c						\
			./queue/getters.c						\

OBJ		=	$(SRC:.c=.o)

INCLUDE	=	-I./../../include/ -I./../../libs/myteams/

FLAG	=	-Wall -Wextra -g $(INCLUDE)

NAME	=	myteams_server

SHARE_LIB		=	-L../../libs/myteams/ -lmyteams

all:	$(NAME)

$(NAME):	$(OBJ)
		gcc $(FLAG) -o $(NAME) $(OBJ) $(SHARE_LIB) -luuid
		mv $(NAME) ../../

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f ../../$(NAME)

re: fclean all
