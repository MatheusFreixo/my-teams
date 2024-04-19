/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** checkers
*/


#include "../../include/teams_client.h"

bool check_subs_msg(char *command)
{
    for (int i = 0; subs_msg[i] != NULL; i++) {
        if (strcmp(subs_msg[i], command) == 0) {
            return (true);
        }
    }
    return (false);
}

bool check_log(char *command)
{
    for (int i = 0; log[i] != NULL; i++) {
        if (strcmp(log[i], command) == 0) {
            return (true);
        }
    }
    return (false);
}

bool check_create(char *command)
{
    for (int i = 0; create[i] != NULL; i++) {
        if (strcmp(create[i], command) == 0) {
            return (true);
        }
    }
    return (false);
}

bool check_user_msg(char *command)
{
    for (int i = 0; user_msg[i] != NULL; i++) {
        if (strcmp(user_msg[i], command) == 0) {
            return (true);
        }
    }
    return (false);
}
