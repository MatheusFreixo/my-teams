/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** write_file
*/

#include "../../include/my_teams.h"

void writefile(char *filepath, char *buffer)
{
    int fd = open(filepath, O_RDWR | O_CREAT, S_IRWXU | S_IRWXG | S_IRWXO);

    if (fd == -1){
        return;
    }
    write(fd, buffer, strlen(buffer));
    close(fd);
    free(buffer);
}
