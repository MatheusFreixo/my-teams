/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** store_users
*/

#include "../../../../include/teams_server.h"

void store_users(steams_t *server)
{
    char *users = get_all_users(server);

    writefile("./users.txt", users);
}

void store_teams(steams_t *server)
{
    char *teams = get_teams_info(server);

    writefile("teams.txt", teams);
}

void store_channels(steams_t *server)
{
    char *channels = get_channels_info(server);

    writefile("channels.txt", channels);
}

void store_threads(steams_t *server)
{
    char *threads = get_threads_info(server);

    writefile("threads.txt", threads);
}

void store_replies(steams_t *server)
{
    char *replies = get_replies_info(server);

    writefile("replies.txt", replies);
}
