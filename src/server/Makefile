##
## EPITECH PROJECT, 2024
## my_teams
## File description:
## Makefile
##

SRC		=	./main.c										\
			./create/socket.c								\
			./create/exit.c									\
			./create/server.c								\
			./client_connection/client_management.c			\
			./client_connection/connection.c				\
			./error_handling/error_handling.c				\
			./commands/command_handling.c					\
			./commands/command_checkers.c					\
			./commands/manage_context.c						\
			./commands/context_based/context_based.c		\
			./commands/user_related/user_related.c			\
			./commands/manage_subscribe/manage_subscribe.c	\
			./commands/manage_subscribe/manage_list_subs.c	\
			./commands/manage_subscribe/subs_checker.c		\
			./commands/manage_subscribe/subs_getter.c		\
			./queue/log_system/manage_user_log.c			\
			./queue/manage_uuid.c							\
			./queue/inserters/manage_create.c				\
			./queue/inserters/manage_teams.c				\
			./queue/inserters/manage_channels.c				\
			./queue/inserters/manage_threads.c				\
			./queue/inserters/manage_replies.c				\
			./queue/manage_messages.c						\
			./queue/manage_list.c							\
			./queue/checkers.c								\
			./queue/getters/general_getters.c				\
			./queue/getters/user_getters.c					\
			./queue/getters/list_getters.c					\
			./queue/store_lists/store_users.c				\
			./queue/setters.c								\
			./queue/upload_lists/upload_users.c								\
			./../common/parser.c							\
			./../common/split_str.c							\
			./../common/concat/concat_string.c				\
			./../common/concat/concat_message.c				\
			./../common/concat/concat_subs_message.c		\
			./../file_management/write_file.c				\
			./../file_management/read_file.c				\

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
