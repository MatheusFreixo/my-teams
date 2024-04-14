/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** command_checkers
*/

#include "./../../../include/teams_server.h"

bool check_log(char *command)
{
    for (int i = 0; log[i] != NULL; i++) {
        if (strcmp(log[i], command) == 0) {
            return (true);
        }
    }
    return (false);
}
