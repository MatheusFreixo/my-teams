/*
** EPITECH PROJECT, 2024
** my_ftp
** File description:
** client
*/

#include "../../include/teams_client.h"

int server_connection(cteams_t *client)
{
    if (connect(client->fd, (struct sockaddr*) &client->addr,
                sizeof(client->addr)) != 0){
        printf("Connection failed\n");
        return(84);
    }
    return (0);
}
