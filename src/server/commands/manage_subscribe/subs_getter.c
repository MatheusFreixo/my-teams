/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** getter
*/

#include "./../../../../include/teams_server.h"

int get_list_len(char **list)
{
    int i = 0;

    if (list == NULL)
        return (1);
    for (; list[i] != NULL; i++);
    return (i);
}

char *get_all_subscribers(steams_t *server, teams_t *team)
{
    char *user_name = NULL;
    char *msg = "SUBSCRIBED-USERS\n";

    for (int i = 0; team->subscribed[i] != NULL; i++){
        user_name = strdup(
            get_user_name_by_id(server, team->subscribed[i]));
        msg = concat_malloc(msg, team->subscribed[i],
            user_name, get_user_status(server, team->subscribed[i]));
    }
    return (msg);
}
