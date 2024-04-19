/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** manage_subs
*/

#include "../../../include/teams_client.h"

void manage_subs_unsubs_event(char **command)
{
    char **det;

    if (strcmp(command[0], "SUBSCRIBED") == 0) {
        det = split_str(parse_message(command[1]), '\t');
        client_print_subscribed(parse_message(det[0]), parse_message(det[1]));
    }
    if (strcmp(command[0], "UNSUBSCRIBED") == 0) {
        det = split_str(parse_message(command[1]), '\t');
        client_print_unsubscribed(
            parse_message(det[0]), parse_message(det[1]));
    }
}

void manage_subs_message(char **command)
{
    char **det = NULL;

    if (strcmp(command[0], "SUBSCRIBED") == 0
    || strcmp(command[0], "UNSUBSCRIBED") == 0){
        manage_subs_unsubs_event(command);
        return;
    }
    if (strcmp(command[0], "SUBSCRIBED-TEAMS") == 0)
        for (int i = 1; command[i] != NULL; i++) {
            det = split_str(command[i], '\t');
            client_print_teams(parse_message(det[0]),
                parse_message(det[1]), parse_message(det[2]));
        }
    if (strcmp(command[0], "SUBSCRIBED-USERS") == 0)
        for (int i = 1; command[i] != NULL; i++) {
            det = split_str(command[i], '\t');
            client_print_users(parse_message(det[0]),
                parse_message(det[1]), atoi(det[2]));
        }
}
