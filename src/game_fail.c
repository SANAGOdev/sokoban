/*
** EPITECH PROJECT, 2023
** sokoban
** File description:
** game_fail.c
*/

#include "main.h"

int check_fail(map_t *map)
{
    box_loc_t *first = map->box_locs;

    for (; first; first = first->next) {
        if (check_line(map, first))
            return (0);
        if (check_column(map, first))
            return (0);
    }
    return (1);
}

int check_line(map_t *map, box_loc_t *first)
{
    if (!check_valid_coord(map, first->pos.x + 1, first->pos.y))
        return (0);
    if (!check_valid_coord(map, first->pos.x - 1, first->pos.y))
        return (0);
    return (1);
}

int check_column(map_t *map, box_loc_t *first)
{
    if (!check_valid_coord(map, first->pos.x, first->pos.y + 1))
        return (0);
    if (!check_valid_coord(map, first->pos.x, first->pos.y - 1))
        return (0);
    return (1);
}

int check_valid_coord(map_t *map, int x, int y)
{
    if (!x || x < 0)
        return (0);
    if (!y || y < 0)
        return (0);
    if (!map->array[x] || !map->array[x][y])
        return (0);
    if (map->array[x][y] == '#' || map->array[x][y] == 'X')
        return (0);
    return (1);
}
