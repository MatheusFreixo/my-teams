/*
** EPITECH PROJECT, 2024
** my_teams [WSL: Ubuntu]
** File description:
** socket
*/

#include "../../../include/teams_server.h"

int create_socket(void)
{
    int fd = socket(AF_INET, SOCK_STREAM, 0);

    if (fd < 0){
        return (84);
    }
    return (fd);
}
