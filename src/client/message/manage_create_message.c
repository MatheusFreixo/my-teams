/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** manage_create_message
*/

#include "../../../include/teams_client.h"

void manage_create_team_channel(char **msg)
{
    char *create_id = parse_message(msg[1]);
    char *create_name = parse_message(msg[2]);
    char *create_desc = parse_message(msg[3]);

    if (strcmp(msg[0], "TEAM-CREATED") == 0){
        client_event_team_created(create_id, create_name, create_desc);
        client_print_team_created(create_id, create_name, create_desc);
    }
    if (strcmp(msg[0], "CHANNEL-CREATED") == 0){
        client_event_channel_created(create_id, create_name, create_desc);
        client_print_channel_created(create_id, create_name, create_desc);
    }
}

void manage_create_thread_reply(char **msg)
{
    char *msg_1 = parse_message(msg[1]);
    char *msg_2 = parse_message(msg[2]);
    char *msg_4 = parse_message(msg[4]);
    char *msg_5 = NULL;
    time_t time = parse_time(msg[3]);

    if (strcmp(msg[0], "REPLY-CREATED") == 0){
        client_print_reply_created(msg_1, msg_2, time, msg_4);
        return;
    }
    if (strcmp(msg[0], "THREAD-CREATED") == 0){
        msg_5 = parse_message(msg[5]);
        client_event_thread_created(msg_1, msg_2, time, msg_4, msg_5);
        client_print_thread_created(msg_1, msg_2, time, msg_4, msg_5);
    }
}

void manage_create_message(cteams_t *client, char **msg)
{
    if (strncmp(msg[0], "TEAM", 4) == 0 || strncmp(msg[0], "CHANNEL", 7) == 0){
        manage_create_team_channel(msg);
        return;
    }
    if (strncmp(msg[0], "THREAD", 6) == 0 || strncmp(msg[0], "REPLY", 5) == 0){
        manage_create_thread_reply(msg);
    }
}
