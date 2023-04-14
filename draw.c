#include "so_long.h"


int key_pressed(int pressed, t_data *data)
{
    // printf("%d\n", pressed);
        if (pressed == LEFT)
            mv_left(data);
        else if (pressed == RIGHT)
            mv_right(data);
        else if (pressed == UP)
            mv_up(data);
        else if (pressed == DOWN)
            mv_down(data);
        else if (pressed == ESC)
            exit(0);
        else
            write(1, "fuck yourself!\n", 15);
    return 0;
}

void init(t_data *data)
{
    data->mlx = mlx_init();
    data->window = mlx_new_window(data->mlx, data->width_len * 32, data->lines_len * 32 , "Niggers");
    init_image(data);
    draw_map(data);
    mlx_key_hook(data->window, key_pressed, data);
    // mlx_hook(data->window,17,0,NULL,data);
    mlx_loop(data->mlx);
}

void init_image(t_data *data)
{
    data->floor = "./textures/wall.xpm";
    data->player = "./textures/player.xpm";
    data->door = "./textures/volcano_portal.xpm";
    data->wall = "./textures/floor.xpm";
    data->collectible = "./textures/collectible.xpm";

    data->image_floor = mlx_xpm_file_to_image(data->mlx, data->floor, &data->image_width, &data->image_height);
    data->image_player = mlx_xpm_file_to_image(data->mlx, data->player, &data->image_width, &data->image_height);
    data->image_door = mlx_xpm_file_to_image(data->mlx, data->door, &data->image_width, &data->image_height);
    data->image_wall = mlx_xpm_file_to_image(data->mlx, data->wall, &data->image_width, &data->image_height);
    data->image_collectible = mlx_xpm_file_to_image(data->mlx, data->collectible, &data->image_width, &data->image_height);
}

void draw_map(t_data *data)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while(data->map[j])
    {
        while(data->map[j][i])
        {
            if (data->map[j][i] == '1')
                mlx_put_image_to_window(data->mlx, data->window, data->image_wall, i * 32, j * 32);
            if (data->map[j][i] == '0'||data->map[j][i] == 'P'||data->map[j][i] == 'E'||data->map[j][i] == 'C')
                mlx_put_image_to_window(data->mlx, data->window, data->image_floor, i * 32, j * 32);
            if (data->map[j][i] == 'P')
                mlx_put_image_to_window(data->mlx, data->window, data->image_player, i * 32, j * 32);
            if (data->map[j][i] == 'E')
                mlx_put_image_to_window(data->mlx, data->window, data->image_door, i * 32, j * 32);
            if (data->map[j][i] == 'C')
                mlx_put_image_to_window(data->mlx, data->window, data->image_collectible, i * 32, j * 32);
            i++;
        }
        i = 0;
        j++;
    }
}

void player_on_door(t_data *data){

    mlx_put_image_to_window(data->mlx, data->window, data->image_door, data->E_X * 32, (data->E_Y) * 32);
    mlx_put_image_to_window(data->mlx, data->window, data->image_player, data->E_X * 32, (data->E_Y) * 32);
}