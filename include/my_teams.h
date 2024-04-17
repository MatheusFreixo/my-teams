/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** my_teams
*/

#ifndef MY_TEAMS_H_
    #define MY_TEAMS_H_

    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include <string.h>
    #include <unistd.h>
    #include <arpa/inet.h>
    #include <sys/socket.h>
    #include <sys/select.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <sys/wait.h>
    #include <sys/queue.h>
    #include <dirent.h>
    #include <uuid/uuid.h>

    #define INPUT_FD 0
    #define OUTPUT_FD 1
    #define MAX_NAME_LENGTH 32
    #define MAX_DESCRIPTION_LENGTH 255
    #define MAX_BODY_LENGTH 512

void writefile(char *filepath, char *buffer);

char *readfile(char *filepath);

char **split_str(char const *str, char c);

char *parse_message(char *message);

#endif /* !MY_TEAMS_H_ */
