/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** user_related
*/

#include "./../../../../include/teams_server.h"

void manage_user(steams_t *server, char **command, int client_fd)
{
    char *user = NULL;

    if (command[1] == NULL)
        return;
    user = get_specific_user(server, command[1]);
    if (user == NULL){
        user = malloc(sizeof(char) * strlen(command[1]) + 13);
        user = "ERROR-USER\n";
        strcat(user, command[1]);
    }
    write(client_fd, user, strlen(user));
}

void manage_users(steams_t *server, char **command, int client_fd)
{
    char *users = get_all_users(server);

    write(client_fd, users, strlen(users));
}

void user_related(steams_t *server, char **command, int client_fd)
{
    if (strcmp(command[0], "/users") == 0)
        manage_users(server, command, client_fd);
    if (strcmp(command[0], "/user") == 0)
        manage_user(server, command, client_fd);
}
