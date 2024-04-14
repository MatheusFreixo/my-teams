/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** getters
*/

#include "../../../include/teams_server.h"

char *get_user_name(steams_t *server, int client_fd)
{
    users_t *tmp = NULL;

    LIST_FOREACH(tmp, &server->users, entry){
        if (tmp->fd == client_fd){
            return (tmp->name);
        }
    }
    return (NULL);
}
