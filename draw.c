/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbenaiss <zbenaiss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 13:08:28 by zbenaiss          #+#    #+#             */
/*   Updated: 2023/05/27 17:33:27 by zbenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_pressed(int pressed, t_data *data)
{
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
		write(1, "Invalid Key Pressed!!\n", 23);
	return (0);
}

void	init(t_data *data)
{
	data->mlx = mlx_init();
	data->window = mlx_new_window(data->mlx, data->width_len * 32,
			data->lines_len * 32, "Dungeon X");
	init_image(data);
	draw_map(data);
	mlx_key_hook(data->window, key_pressed, data);
	mlx_loop(data->mlx);
}

void	init_image(t_data *data)
{
	data->floor = "./textures/wall.xpm";
	data->player = "./textures/player.xpm";
	data->door = "./textures/volcano_portal.xpm";
	data->wall = "./textures/floor.xpm";
	data->collectible = "./textures/collectible.xpm";
	data->image_floor = mlx_xpm_file_to_image(data->mlx, data->floor,
			&data->image_width, &data->image_height);
	data->image_player = mlx_xpm_file_to_image(data->mlx, data->player,
			&data->image_width, &data->image_height);
	data->image_door = mlx_xpm_file_to_image(data->mlx, data->door,
			&data->image_width, &data->image_height);
	data->image_wall = mlx_xpm_file_to_image(data->mlx, data->wall,
			&data->image_width, &data->image_height);
	data->image_collectible = mlx_xpm_file_to_image(data->mlx,
			data->collectible,
			&data->image_width, &data->image_height);
}

void	draw_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[j])
	{
		while (data->map[j][i])
		{
			draw_map2(data, j, i);
			i++;
		}
		i = 0;
		j++;
	}
}

void	player_on_door(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->window, data->image_door, data->e_x
		* 32, (data->e_y) * 32);
	mlx_put_image_to_window(data->mlx, data->window, data->image_player,
		data->e_x * 32, (data->e_y) * 32);
}
