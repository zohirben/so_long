#include "so_long.h"

void mv_up(t_data *data)
{
    if (data->map[data->P_Y-1][data->P_X] != '1'){
        if (data->map[data->P_Y-1][data->P_X] == 'C')
        {
            data->map[data->P_Y-1][data->P_X] = '0';
            data->C_count--;
        }

        mlx_put_image_to_window(data->mlx, data->window, data->image_floor, data->P_X * 32, (data->P_Y - 1) * 32);
        mlx_put_image_to_window(data->mlx, data->window, data->image_player, data->P_X * 32, (data->P_Y - 1) * 32);
        mlx_put_image_to_window(data->mlx, data->window, data->image_floor, data->P_X * 32, (data->P_Y) * 32);
        mlx_put_image_to_window(data->mlx, data->window, data->image_door, data->E_X * 32,     (data->E_Y) * 32);
        if (data->map[data->P_Y-1][data->P_X] == 'E')
            player_on_door(data);
        if (data->map[data->P_Y-1][data->P_X] == 'E' && data->C_count == 0)
            exit(0);
        
        
        data->P_Y--;
        data->steps++;
        ft_printf("steps : %d\n", data->steps);
    }
}

void mv_down(t_data *data)
{
    if (data->map[data->P_Y+1][data->P_X] != '1'){
        if (data->map[data->P_Y + 1][data->P_X] == 'C')
        {
            data->map[data->P_Y + 1][data->P_X] = '0';
            data->C_count--;
        }
        mlx_put_image_to_window(data->mlx, data->window, data->image_floor, data->P_X * 32, (data->P_Y + 1) * 32);
        mlx_put_image_to_window(data->mlx, data->window, data->image_player, data->P_X * 32, (data->P_Y + 1) * 32);
        mlx_put_image_to_window(data->mlx, data->window, data->image_floor, data->P_X * 32, (data->P_Y) * 32);
        mlx_put_image_to_window(data->mlx, data->window, data->image_door, data->E_X * 32,     (data->E_Y) * 32);
        if (data->map[data->P_Y + 1][data->P_X] == 'E')
            player_on_door(data);
        if (data->map[data->P_Y + 1][data->P_X] == 'E' && data->C_count == 0)
            exit(0);
        
        
        data->P_Y++;
        data->steps++;
        ft_printf("steps : %d\n", data->steps);
    }
}

void mv_left(t_data *data)
{
    if (data->map[data->P_Y][data->P_X - 1] != '1'){
        if (data->map[data->P_Y][data->P_X - 1] == 'C')
        {
            data->map[data->P_Y][data->P_X - 1] = '0';
            data->C_count--;
        }

        mlx_put_image_to_window(data->mlx, data->window, data->image_floor, (data->P_X - 1) * 32, data->P_Y * 32);
        mlx_put_image_to_window(data->mlx, data->window, data->image_player, (data->P_X - 1) * 32, data->P_Y * 32);
        mlx_put_image_to_window(data->mlx, data->window, data->image_floor, data->P_X * 32, data->P_Y * 32);
        mlx_put_image_to_window(data->mlx, data->window, data->image_door, data->E_X * 32,     data->E_Y * 32);
        if (data->map[data->P_Y][data->P_X - 1] == 'E')
            player_on_door(data);
        if (data->map[data->P_Y][data->P_X - 1] == 'E' && data->C_count == 0)
            exit(0);
        
        
        data->P_X--;
        data->steps++;
        ft_printf("steps : %d\n", data->steps);
    }
}

void mv_right(t_data *data)
{
    if (data->map[data->P_Y][data->P_X + 1] != '1'){
        if (data->map[data->P_Y][data->P_X + 1] == 'C')
        {
            data->map[data->P_Y][data->P_X + 1] = '0';
            data->C_count--;
        }

        mlx_put_image_to_window(data->mlx, data->window, data->image_floor, (data->P_X + 1) * 32, data->P_Y * 32);
        mlx_put_image_to_window(data->mlx, data->window, data->image_player, (data->P_X + 1) * 32, data->P_Y * 32);
        mlx_put_image_to_window(data->mlx, data->window, data->image_floor, data->P_X * 32, data->P_Y * 32);
        mlx_put_image_to_window(data->mlx, data->window, data->image_door, data->E_X * 32,     data->E_Y * 32);
        if (data->map[data->P_Y][data->P_X + 1] == 'E')
            player_on_door(data);
        if (data->map[data->P_Y][data->P_X + 1] == 'E' && data->C_count == 0)
            exit(0);
        
        
        data->P_X++;
        data->steps++;
        ft_printf("steps : %d\n", data->steps);
    }
}