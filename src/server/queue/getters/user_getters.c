/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** user_getters
*/

#include "../../../../include/teams_server.h"

char *get_specific_user(steams_t *server, char *id)
{
    users_t *tmp = NULL;
    char *user = "USER\n";

    LIST_FOREACH(tmp, &server->users, entry){
        if (strcmp(tmp->id, id) == 0){
            user = concat_malloc(user, tmp->id, tmp->name, tmp->status);
            return (user);
        }
    }
    return (NULL);
}

char *get_all_users(steams_t *server)
{
    users_t *tmp = NULL;
    char *users = "USERS\n";

    LIST_FOREACH(tmp, &server->users, entry){
        users = concat_malloc(users, tmp->id, tmp->name, tmp->status);
    }
    return (users);
}

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
