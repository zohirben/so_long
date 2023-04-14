#ifndef SO_LONG_H
#define SO_LONG_H

#include <stdio.h>
#include <mlx.h>
#include "./get_next_line/get_next_line.h"
#include "./printf/ft_printf.h"
#include "./libft/libft.h"

enum{

   LEFT = 123,
   RIGHT = 124,
   UP = 126,
   DOWN = 125, 
   ESC = 53,

};

typedef struct s_map
{
    char **map;
    int lines_len;
    int width_len;
    int P_count;
    int C_count;
    int E_count;
    int P_X;
    int P_Y;
    int E_X;
    int E_Y;

    int steps;
    void *mlx;
    void *window;
    int image_height;
    int image_width;
    
    char *floor;
    char *player;
    char *collectible;
    char *door;
    char *wall;
    void *image_floor;
    void *image_wall;
    void *image_door;
    void *image_player;
    void *image_collectible;


}   t_data;

void init(t_data *data);
void init_image(t_data *data);
void draw_map(t_data *data);
void mv_up(t_data *data);
void mv_down(t_data *data);
void mv_left(t_data *data);
void mv_right(t_data *data);
void player_on_door(t_data *data);
#endif