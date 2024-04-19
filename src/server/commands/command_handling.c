/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** command_handling
*/

#include "./../../../include/teams_server.h"

int check_command(steams_t *server, char *command, int client_fd)
{
    char **cmd = split_str(command, ' ');

    if (check_log(cmd[0]))
        manage_log_command(
            server, cmd[0], cmd[1], client_fd);
    if (check_context_cmd(server, parse_message(cmd[0]), client_fd))
        context_based(server, cmd, client_fd);
    if (check_user_cmd(server, parse_message(cmd[0]), client_fd))
        user_related(server, cmd, client_fd);
    if (check_subscribe_cmd(parse_message(cmd[0])))
        manage_subscribe_command(server, cmd, client_fd);
    return (0);
}
