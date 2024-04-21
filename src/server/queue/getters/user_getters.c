/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** user_getters
*/

#include "../../../../include/teams_server.h"

char *get_user_name_by_id(steams_t *server, char *id)
{
    users_t *tmp = NULL;
    int i = 0;

    LIST_FOREACH(tmp, &server->users, entry){
        if (strcmp(tmp->id, id) == 0){
            return (tmp->name);
        }
        i++;
    }
    return (NULL);
}

bool get_user_status(steams_t *server, char *id)
{
    users_t *tmp = NULL;
    int i = 0;

    LIST_FOREACH(tmp, &server->users, entry){
        if (strcmp(tmp->id, id) == 0){
            return (tmp->status);
        }
    }
    return (false);
}

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
    int i = 0;

    LIST_FOREACH(tmp, &server->users, entry){
        users = concat_malloc(users, tmp->id, tmp->name, tmp->status);
    }
    return (users);
}

char *get_user_name(steams_t *server, int client_fd)
{
    users_t *tmp = NULL;
    int i = 0;

    LIST_FOREACH(tmp, &server->users, entry){
        if (i == server->nb_users){
            break;
        }
        if (tmp->fd == client_fd){
            return (tmp->name);
        }
    }
    return (NULL);
}
