/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** manage_list
*/

#include "./../../../include/teams_server.h"

void send_replies_info(steams_t *server, int client_fd)
{
    char *replies = get_replies_info(server);

    if (replies == NULL) {
        return;
    }
    write(client_fd, replies, strlen(replies));
}

void send_threads_info(steams_t *server, int client_fd)
{
    char *threads = get_threads_info(server);

    if (threads == NULL) {
        return;
    }
    write(client_fd, threads, strlen(threads));
}

void send_channels_info(steams_t *server, int client_fd)
{
    char *channels = get_channels_info(server);

    if (channels == NULL) {
        return;
    }
    write(client_fd, channels, strlen(channels));
}

void send_teams_info(steams_t *server, int client_fd)
{
    char *teams = get_teams_info(server);

    if (teams == NULL) {
        return;
    }
    write(client_fd, teams, strlen(teams));
}

void manage_list_command(steams_t *server, char **command, int client_fd)
{
    switch (server->create_type) {
        case TEAM:
            send_teams_info(server, client_fd);
            break;
        case CHANNEL:
            send_channels_info(server, client_fd);
            break;
        case THREAD:
            send_threads_info(server, client_fd);
            break;
        case REPLY:
            send_replies_info(server, client_fd);
            break;
    }
}
