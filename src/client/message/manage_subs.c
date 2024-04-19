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
        client_print_subscribed(
            parse_message(details[0]), parse_message(details[1]));
    }
    if (strcmp(command[0], "UNSUBSCRIBED") == 0) {
        details = split_str(command[1], '\t');
        client_print_unsubscribed(
            parse_message(details[0]), parse_message(details[1]));
    }
    if (strcmp(command[0], "SUBSCRIBED-TEAMS") == 0)
        for (int i = 1; command[i] != NULL; i++) {
            details = split_str(command[i], '\t');
            client_print_teams(parse_message(command[0]),
                parse_message(command[1]), parse_message(command[2]));
        }
    if (strcmp(command[0], "SUBSCRIBED-USERS") == 0)
        for (int i = 1; command[i] != NULL; i++) {
            details = split_str(command[i], '\t');
            client_print_users(parse_message(command[0]),
                parse_message(command[1]), atoi(command[2]));
        }
}
