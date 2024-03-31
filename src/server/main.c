/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** main
*/

#include "../../include/teams_server.h"

int main(int argc, char **argv)
{
    if (argc != 2){
        return (84);
    }
    teams_server(argv[1]);
    return (0);
}
