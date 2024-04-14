/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** checkers
*/

#include "../../../include/teams_server.h"

bool check_client(steams_t *server, int client_fd)
{
    users_t *tmp = NULL;

    LIST_FOREACH(tmp, &server->users, entry){
        if (tmp->fd == client_fd){
            return (true);
        }
    }
    return (false);
}
