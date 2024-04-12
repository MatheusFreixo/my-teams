/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** read_file
*/

#include "../../include/my_teams.h"

char *readfile(char *filepath)
{
    int size = 1024;
    char *bf = malloc(sizeof(char) * size + 1);
    int rd = 0;
    int fd = open(filepath, O_RDONLY);

    if (fd == -1){
        return (NULL);
    }
    rd = read(fd, bf, size);
    bf[rd] = '\0';
    close(fd);
    return (bf);
}
