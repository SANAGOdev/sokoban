/*
** EPITECH PROJECT, 2023
** sokoban
** File description:
** game_utils.c
*/

#include "main.h"

void init_ncurses(void)
{
    initscr();
    curs_set(0);
    keypad(stdscr, 1);
    noecho();
    raw();
}

void exit_ncurses(void)
{
    curs_set(1);
    keypad(stdscr, 0);
    endwin();
}

int get_game_state(map_t *map)
{
    if (check_win(map))
        return (0);
    if (check_fail(map))
        return (1);
    return (2);
}

int check_win(map_t *map)
{
    box_loc_t *first = map->box_locs;

    for (; first; first = first->next)
        if (!is_in_box(map, first))
            return (0);
    return (1);
}

int is_in_box(map_t *map, box_loc_t *box_loc)
{
    storage_loc_t *first = map->o_locs;

    for (; first; first = first->next)
        if (first->pos.x == box_loc->pos.x && first->pos.y == box_loc->pos.y)
            return (1);
    return (0);
}
