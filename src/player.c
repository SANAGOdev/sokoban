/*
** EPITECH PROJECT, 2023
** sokoban
** File description:
** player.c
*/

#include "main.h"

void player_moove_line(map_t *map, int direction)
{
    int next_line = map->pos.x + direction;
    int next_line_box = map->pos.x + (direction * 2);

    if (!map->array[next_line] || next_line < 0)
        return;
    if (map->array[next_line][map->pos.y] == '#')
        return;
    if (map->array[next_line][map->pos.y] == 'X')
        if (!player_moove_line_box(map, next_line, next_line_box))
            return;
    map->array[map->pos.x][map->pos.y] = ' ';
    map->array[next_line][map->pos.y] = 'P';
    check_storage_location(map, map->pos.x, map->pos.y);
    map->pos.x = next_line;
}

void player_moove_column(map_t *map, int direction)
{
    int next_column = map->pos.y + direction;
    int next_column_box = map->pos.y + (direction * 2);

    if (!map->array[map->pos.x][next_column] || next_column < 0)
        return;
    if (map->array[map->pos.x][next_column] == '#')
        return;
    if (map->array[map->pos.x][next_column] == 'X')
        if (!player_moove_column_box(map, next_column, next_column_box))
            return;
    map->array[map->pos.x][map->pos.y] = ' ';
    map->array[map->pos.x][next_column] = 'P';
    check_storage_location(map, map->pos.x, map->pos.y);
    map->pos.y = next_column;
}

int player_moove_line_box(map_t *map, int next_line, int next_line_box)
{
    if (!map->array[next_line_box] || next_line_box < 0)
        return (0);
    if (map->array[next_line_box][map->pos.y] == '#'
    || map->array[next_line_box][map->pos.y] == 'X')
        return (0);
    map->array[next_line_box][map->pos.y] = 'X';
    update_line_box(map, next_line, next_line_box);
    return (1);
}

int player_moove_column_box(map_t *map, int next_column, int next_column_box)
{
    if (!map->array[map->pos.x][next_column_box] || next_column_box < 0)
        return (0);
    if (map->array[map->pos.x][next_column_box] == '#'
    || map->array[map->pos.x][next_column_box] == 'X')
        return (0);
    map->array[map->pos.x][next_column_box] = 'X';
    update_column_box(map, next_column, next_column_box);
    return (1);
}
