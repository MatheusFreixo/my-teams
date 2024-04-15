/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** server
*/

#include "../../../include/teams_server.h"

struct check setup_check_struct(void)
{
    check_t tmp;

    tmp.user = malloc(sizeof(bool) * 1024);
    tmp.pass = malloc(sizeof(bool) * 1024);
    tmp.auth = malloc(sizeof(bool) * 1024);
    for (int i = 0; i < 1024; i++) {
        tmp.user[i] = false;
        tmp.pass[i] = false;
        tmp.auth[i] = false;
    }
    return (tmp);
}

struct server_teams *setup_server_struct(char *port)
{
    steams_t *tmp = malloc(sizeof(steams_t));

    tmp->port = atoi(port);
    tmp->fd = create_socket();
    if (tmp->fd == 84)
        return (NULL);
    tmp->addr = configure_socket(tmp->port);
    tmp->buffer = malloc(sizeof(char) * 1024 + 1);
    tmp->client_fds = malloc(sizeof(int) * 1024);
    tmp->pwd = malloc(sizeof(char) * 1000 + 1);
    for (int i = 0; i < 1024; i++)
        tmp->client_fds[i] = '\0';
    tmp->file_buff = malloc(sizeof(char) * 1000 + 1);
    tmp->check = setup_check_struct();
    tmp->context = false;
    tmp->create_type = TEAM;
    LIST_INIT(&tmp->users);
    return (tmp);
}

int teams_server(char *port)
{
    steams_t *server = setup_server_struct(port);

    if (error_handling(server) == 84){
        return (84);
    }
    infinite_loop(server);
    return (0);
}
