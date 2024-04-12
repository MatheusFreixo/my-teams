/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** main
*/

#include "../../include/teams_client.h"

struct client_teams *setup_client_struct(char *ip, char *port)
{
    cteams_t *tmp = malloc(sizeof(cteams_t));

    tmp->ip = atoi(ip);
    tmp->port = atoi(port);
    tmp->fd = create_socket();
    if (tmp->fd == 84){
        free(tmp);
        return(NULL);
    }
    tmp->addr = configure_socket(tmp->ip, tmp->port);
    tmp->buffer = malloc(sizeof(char) * 1024 + 1);
    tmp->welcome = "Client connected\n";
    tmp->in_buffer = malloc(sizeof(char) * 1024 + 1);
    return(tmp);
}

int main(int argc, char **argv)
{
    cteams_t *client;

    if (argc != 3){
        printf("Usage: ./myteams_cli ip port\n");
        return(84);
    }
    client = setup_client_struct(argv[1], argv[2]);
    if (client == NULL)
        return(84);
    if (infinite_loop(client) == 84){
        close(client->fd);
        to_exit(client);
        return(84);
    }
    close(client->fd);
    to_exit(client);
    return(0);
}
