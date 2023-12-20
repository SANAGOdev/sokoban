/*
** EPITECH PROJECT, 2023
** sokoban
** File description:
** map_utils.c
*/

#include "main.h"

int count_lines(const char *content)
{
    int i = 0;
    int count = 0;

    for (; content[i]; i++)
        if (content[i] == '\n')
            count++;
    return (count);
}

int get_line_size(const char *content)
{
    int len = 0;

    for (; content[len] != '\n' && *content; len++);
    return (len);
}

void get_player_line(map_t *map)
{
    int line = 0;

    for (; map->array[line]; line++)
        if (contains_player(map->array[line]))
            map->pos.x = line;
}

void get_player_column(map_t *map)
{
    int column = 0;

    for (; map->array[map->pos.x][column]; column++)
        if (map->array[map->pos.x][column] == 'P')
            map->pos.y = column;
}

int contains_player(char const *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] == 'P')
            return (1);
    return (0);
}
