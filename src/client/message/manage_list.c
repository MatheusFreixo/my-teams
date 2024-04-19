/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** manage_list
*/

#include "../../../include/teams_client.h"

void manage_list_replies(char **msg)
{
    char **details = NULL;
    time_t time;

    for (int i = 1; msg[i] != NULL; i++){
        details = split_str(msg[i], '\t');
        if (details[2] == NULL){
            break;
        }
        time = parse_time(details[2]);
        client_thread_print_replies(details[0], details[1], time, details[3]);
    }
}

void manage_list_threads(char **msg)
{
    char **details = NULL;
    time_t time;

    for (int i = 1; msg[i] != NULL; i++){
        details = split_str(msg[i], '\t');
        if (details[2] == NULL){
            break;
        }
        time = parse_time(details[2]);
        client_channel_print_threads(
            details[0], details[1], time, details[3], details[4]);
    }
}

void manage_list_channels(char **msg)
{
    char **details = NULL;

    for (int i = 1; msg[i] != NULL; i++){
        details = split_str(msg[i], '\t');
        if (details[2] == NULL){
            break;
        }
        client_team_print_channels(details[0], details[1], details[2]);
    }
}

void manage_list_teams(char **msg)
{
    char **details = NULL;

    for (int i = 1; msg[i] != NULL; i++){
        details = split_str(msg[i], '\t');
        if (details[2] == NULL){
            break;
        }
        client_print_teams(details[0], details[1], details[2]);
    }
}

void manage_list_message(char **msg)
{
    if (strcmp(msg[0], "LIST-TEAMS") == 0)
        manage_list_teams(msg);
    if (strcmp(msg[0], "LIST-CHANNELS") == 0)
        manage_list_channels(msg);
    if (strcmp(msg[0], "LIST-THREADS") == 0)
        manage_list_threads(msg);
    if (strcmp(msg[0], "LIST-REPLIES") == 0)
        manage_list_replies(msg);
}
