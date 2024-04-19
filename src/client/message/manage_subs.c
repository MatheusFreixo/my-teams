/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** manage_subs
*/

#include "../../../include/teams_client.h"

void manage_subs_message(char **command)
{
    char **details = NULL;

    if (strcmp(command[0], "SUBSCRIBED") == 0) {
        details = split_str(command[1], '\t');
        client_print_subscribed(details[0], details[1]);
    }
    if (strcmp(command[0], "UNSUBSCRIBED") == 0) {
        details = split_str(command[1], '\t');
        client_print_unsubscribed(details[0], details[1]);
    }
    if (strcmp(command[0], "SUBSCRIBED-TEAMS") == 0)
        for (int i = 1; command[i] != NULL; i++) {
            details = split_str(command[i], '\t');
            client_print_teams(command[0], command[1], command[2]);
        }
    if (strcmp(command[0], "SUBSCRIBED-USERS") == 0)
        for (int i = 1; command[i] != NULL; i++) {
            details = split_str(command[i], '\t');
            client_print_users(command[0], command[1], atoi(command[2]));
        }
}
