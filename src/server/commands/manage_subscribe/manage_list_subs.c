/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** manage_list_subs
*/

#include "./../../../../include/teams_server.h"

char **add_user_id_to_list(char **list, const char *user_id)
{
    char **tmp = malloc(sizeof(char *) * (get_list_len(list) + 2));
    int i = 0;

    if (list != NULL) {
        for (; list[i] != NULL; i++) {
            tmp[i] = strdup(list[i]);
        }
    }
    tmp[i] = strdup(user_id);
    tmp[i + 1] = NULL;
    return (tmp);
}

char **remove_user_from_list(char **list, const char *user_id)
{
    char **tmp = malloc(sizeof(char *) * (get_list_len(list) + 1));
    int j = 0;

    for (int i = 0; list[i] != NULL; i++) {
        if (strcmp(list[i], user_id) != 0) {
            tmp[j] = strdup(list[i]);
            j++;
        }
    }
    tmp[j] = NULL;
    return (tmp);
}
