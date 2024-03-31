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
    if (teams_server(argv[1]) == 84){
        return (84);
    }
    return (0);
}
