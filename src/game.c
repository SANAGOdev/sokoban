/*
** EPITECH PROJECT, 2023
** sokoban
** File description:
** game.c
*/

#include "main.h"

int game_loop(map_t *map, int *reset)
{
    int y = 0;
    int x = 0;
    char c = '\0';
    int game_state = -1;

    init_ncurses();
    do {
        getmaxyx(stdscr, y, x);
        clear();
        if (x < map->nb_columns || y < map->nb_lines)
            enlarge_terminal(x, y);
        else
            game_logic(map, c, reset, &game_state);
        refresh();
        if (game_state < 2 || *reset)
            break;
        c = getch();
    } while (c != 27);
    exit_ncurses();
    return (game_state);
}

void game_logic(map_t *map, char c, int *reset, int *game_state)
{
    handle_events(map, c, reset);
    draw_map(map);
    *game_state = get_game_state(map);
}

void handle_events(map_t *map, char c, int *reset)
{
    switch (c) {
    case 2:
        player_moove_line(map, 1);
        return;
    case 3:
        player_moove_line(map, -1);
        return;
    case 4:
        player_moove_column(map, -1);
        return;
    case 5:
        player_moove_column(map, 1);
        return;
    case 32:
        *reset = 1;
        return;
    default:
        return;
    }
}

void draw_map(map_t *map)
{
    int line = 0;

    for (; map->array[line]; line++)
        draw_line(map->array[line]);
}

void draw_line(const char *str)
{
    int i = 0;

    for (; str[i]; i++) {
        if (str[i] == 'x')
            addch('X');
        else
            addch(str[i]);
    }
    addch('\n');
}
