/*
** EPITECH PROJECT, 2023
** sokoban
** File description:
** main
*/

#ifndef MAIN_H_
    #define MAIN_H_

/* library include */
    #include "my.h"
    #include <ncurses.h>
    #include <sys/stat.h>

/* structures */
typedef struct vec2i {
    int x;
    int y;
} vec2i_t;

typedef struct storage_loc {
    vec2i_t pos;
    struct storage_loc *next;
} storage_loc_t;

typedef struct box_loc {
    vec2i_t pos;
    struct box_loc *next;
} box_loc_t;

typedef struct map {
    int nb_lines;
    int nb_columns;
    char **array;
    vec2i_t pos;
    storage_loc_t *o_locs;
    box_loc_t *box_locs;
} map_t;

/* main prototypes */
int help_menu(int argc, char const *argv[]);
void black_hole(map_t *map);

/* file_reader prototypes */
char *read_file(const char *filename);
char *close_file(FILE *file);
char *is_valid_content(char *content, unsigned long size);
char *freeing(char *content);

/* map prototypes */
map_t *load_map(const char *content);
void get_lines(const char *content, map_t *map);
int valid_line(const char *str);
int check_size(map_t *map);
int check_content(map_t *map);

/* game prototypes */
int game_loop(map_t *map, int *reset);
void game_logic(map_t *map, char c, int *reset, int *game_state);
void draw_map(map_t *map);
void handle_events(map_t *map, char c, int *reset);
void draw_line(const char *str);

/* game utils prototypes */
int get_game_state(map_t *map);
int check_win(map_t *map);
int is_in_box(map_t *map, box_loc_t *box_loc);
void init_ncurses(void);
void exit_ncurses(void);

/* game fail */
int check_fail(map_t *map);
int check_line(map_t *map, box_loc_t *first);
int check_column(map_t *map, box_loc_t *first);
int check_valid_coord(map_t *map, int x, int y);

/* map_utils prototypes */
int count_lines(const char *content);
int get_line_size(const char *content);
void get_player_line(map_t *map);
void get_player_column(map_t *map);
int contains_player(char const *str);

/* storage explorer */
void find_storage_locs(map_t *map);
void find_storage_line(map_t *map);
void find_storage_column(map_t *map, int line);
void add_to_storage_list(map_t *map, storage_loc_t *storage_loc);
storage_loc_t *get_last_storage(map_t *map);

/* box explorer prototypes */
void find_box_locs(map_t *map);
void find_box_line(map_t *map);
void find_box_column(map_t *map, int line);
void add_to_box_list(map_t *map, box_loc_t *box_loc);
box_loc_t *get_last_box(map_t *map);

/* player prototypes */
void player_moove_line(map_t *map, int direction);
void player_moove_column(map_t *map, int direction);
int player_moove_line_box(map_t *map, int next_line, int next_line_box);
int player_moove_column_box(map_t *map, int next_column, int next_column_box);

/* player utils prototypes */
void check_storage_location(map_t *map, int line, int column);
void update_line_box(map_t *map, int next_line, int next_line_box);
void update_column_box(map_t *map, int next_column, int next_column_box);
void enlarge_terminal(int x, int y);

#endif /* !MAIN_H_ */
