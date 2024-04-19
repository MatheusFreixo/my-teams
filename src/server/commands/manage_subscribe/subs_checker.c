/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** subs_checker
*/

#include "./../../../../include/teams_server.h"

bool check_list(char **list, const char *user_id)
{
    for (int i = 0; list[i] != NULL; i++) {
        if (strcmp(list[i], user_id) == 0) {
            return (true);
        }
    }
    return (false);
}
