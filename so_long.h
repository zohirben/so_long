/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbenaiss <zbenaiss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 13:08:41 by zbenaiss          #+#    #+#             */
/*   Updated: 2023/05/27 18:39:31 by zbenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./get_next_line/get_next_line.h"
# include "./libft/libft.h"
# include "./printf/ft_printf.h"
# include <mlx.h>

enum
{
	LEFT = 123,
	RIGHT = 124,
	UP = 126,
	DOWN = 125,
	ESC = 53,
};

typedef struct s_map
{
	char	**map;
	int		lines_len;
	int		width_len;
	int		p_count;
	int		c_count;
	int		e_count;
	int		p_x;
	int		p_y;
	int		e_x;
	int		e_y;
	int		prize;

	int		steps;
	void	*mlx;
	void	*window;
	int		image_height;
	int		image_width;

	char	*floor;
	char	*player;
	char	*collectible;
	char	*door;
	char	*wall;
	void	*image_floor;
	void	*image_wall;
	void	*image_door;
	void	*image_player;
	void	*image_collectible;

}			t_data;

int			safe(int x, int y, t_data *data, char **visited);
void		create_lines(char **big_line, char **line, int fd);
void		free_things(char **visited, t_data *data);
void		digit_check(t_data *data, int j, int i);
void		ber_check(char *str, char *format);
char		*ft_strjoinso(char *s1, char *s2);
void		draw_map2(t_data *data, int j, int i);
void		player_on_door(t_data *data);
void		check_corners(t_data *data);
void		init_image(t_data *data);
void		draw_map(t_data *data);
void		mv_right(t_data *data);
void		mv_left(t_data *data);
void		mv_down(t_data *data);
void		width_checker(t_data *data);
void		mv_up(t_data *data);
int			path(t_data *data);
void		init(t_data *data);

#endif