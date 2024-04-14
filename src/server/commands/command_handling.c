/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** command_handling
*/

#include "./../../../include/teams_server.h"

int check_command(steams_t *server, char *command, int client_fd)
{
    server->tok = strtok(server->buffer, "\r\n");
    char **cmd = split_str(command, ' ');
    if (strcmp(cmd[0], "/login") == 0 && cmd[1] != NULL) {
        user_log_in(server, cmd[1], client_fd);
        return (1);
    }
    if (strcmp(cmd[0], "/logout") == 0 && check_client(server, client_fd)) {
        user_log_out(server, client_fd);
        return (1);
    }
    free(command);
    command = NULL;
    command = malloc(sizeof(char) * 1024 + 1);
    free(server->buffer);
    server->buffer = NULL;
    server->buffer = malloc(sizeof(char) * 1024 + 1);
    return (0);
}
