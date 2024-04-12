/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** socket
*/

#include "../../include/teams_client.h"

int create_socket(void)
{
    int fd = socket(AF_INET, SOCK_STREAM, 0);

    if (fd < 0){
        return(84);
    }
    return(fd);
}

struct sockaddr_in configure_socket(int ip, int port)
{
    struct sockaddr_in addr;

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(port);
    return(addr);
}
