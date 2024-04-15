/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** command_handling
*/

#include "./../../../include/teams_server.h"

int check_command(steams_t *server, char *command, int client_fd)
{
    char *tok = strtok(server->buffer, "\r\n");
    char **cmd = split_str(command, ' ');

    if (check_log(cmd[0])){
        manage_log_command(server, cmd[0], cmd[1], client_fd);
    } else if (strcmp(cmd[0], "/use") == 0){
        manage_context(server, cmd, client_fd);
    } else {
        manage_create_command(server, cmd, client_fd);
    }
    free(server->buffer);
    server->buffer = malloc(sizeof(char) * 1024 + 1);
    return (0);
}
