/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** command_checkers
*/

#include "./../../../include/teams_server.h"

bool check_subscribe_cmd(char *command)
{
    for (int i = 0; subscribe_cmd[i] != NULL; i++){
        if (strcmp(subscribe_cmd[i], command) == 0){
            return (true);
        }
    }
    return (false);
}

bool check_log(char *command)
{
    for (int i = 0; log[i] != NULL; i++){
        if (strcmp(log[i], command) == 0){
            return (true);
        }
    }
    return (false);
}

bool check_context_cmd(steams_t *server, char *command, int client_fd)
{
    if (check_client(server, client_fd) == false){
        return (false);
    }
    for (int i = 0; context_cmd[i] != NULL; i++){
        if (strcmp(context_cmd[i], command) == 0){
            return (true);
        }
    }
    return (false);
}

bool check_user_cmd(steams_t *server, char *command, int client_fd)
{
    if (check_client(server, client_fd) == false){
        return (false);
    }
    for (int i = 0; user_cmd[i] != NULL; i++){
        if (strcmp(user_cmd[i], command) == 0){
            return (true);
        }
    }
    return (false);
}
