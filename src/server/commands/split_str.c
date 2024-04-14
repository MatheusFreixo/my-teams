/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** split_str
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../../include/lib.h"

void auxiliar(split_t split, char const *str, char c)
{
    split.letters = 0;
    split.words = 0;
    for (int index = 0; str[index] != '\0'; index++){
        if (str[index] == c){
            split.arr[split.words][split.letters] = '\0';
            split.letters = 0;
            split.words++;
        } else {
            split.arr[split.words][split.letters] = str[index];
            split.letters++;
        }
    }
    split.arr[split.words][split.letters] = '\0';
}

struct split init_struct(void)
{
    split_t tmp;

    tmp.count_word = 1;
    tmp.letters = 0;
    tmp.words = 0;
    return (tmp);
}

char **split_str(char const *str, char c)
{
    split_t split = init_struct();

    for (int index = 0; str[index] != '\0'; index++) {
        if (str[index] == c)
            split.count_word++;
    }
    split.arr = malloc(sizeof(char *) * (split.count_word + 1));
    split.arr[split.count_word] = NULL;
    for (int index = 0; str[index] != '\0'; index++) {
        if (str[index] == c) {
            split.arr[split.words] = malloc(sizeof(char) * split.letters + 1);
            split.words++;
            split.letters = 0;
        } else
            split.letters++;
    }
    split.arr[split.words] = malloc(sizeof(char) * split.letters + 1);
    auxiliar(split, str, c);
    return (split.arr);
}
