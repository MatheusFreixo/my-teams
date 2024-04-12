##
## EPITECH PROJECT, 2024
## my_ftp
## File description:
## Makefile
##

SRC_SERVER	=	./src/server/main.c											\
				./src/server/create/socket.c								\
				./src/server/create/exit.c									\
				./src/server/create/server.c								\
				./src/server/client_connection/client_management.c			\
				./src/server/client_connection/connection.c					\
				./src/server/error_handling/error_handling.c				\

SRC_CLIENT	=	./src/client/main.c											\
				./src/client/client.c										\
				./src/client/socket.c										\
				./src/client/exit.c											\
				./src/file_management/read_file.c							\
				./src/file_management/write_file.c							\

OBJ_SERVER	=	$(SRC_SERVER:.c=.o)

OBJ_CLIENT	=	$(SRC_CLIENT:.c=.o)

INCLUDE		=	-I./include/

FLAG		=	-Wall -Wextra -g -o

NAME_SERVER	=	myteams_server

NAME_CLIENT	=	myteams_cli

LIB			=	-L./libs/myteams/ -lmyteams

all:	$(NAME)

$(NAME):	$(OBJ_SERVER) $(OBJ_CLIENT)
		gcc -I./libs/myteams $(FLAG) $(NAME_SERVER) $(OBJ_SERVER) $(LIB)
		gcc -I./libs/myteams $(FLAG) $(NAME_CLIENT) $(OBJ_CLIENT) $(LIB)

clean:
	rm -f $(OBJ_SERVER) $(OBJ_CLIENT)

fclean: clean
	rm -f $(NAME_SERVER) $(NAME_CLIENT)

re: fclean all
