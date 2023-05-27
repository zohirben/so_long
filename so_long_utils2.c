/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbenaiss <zbenaiss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 16:57:12 by zbenaiss          #+#    #+#             */
/*   Updated: 2023/05/27 17:35:36 by zbenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	width_checker(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		if (data->width_len != (int)ft_strlen(data->map[i]))
		{
			perror("Map Width mkherbe9\n");
			exit(1);
		}
		i++;
	}
}

void	create_lines(char **big_line, char **line, int fd)
{
	*big_line = ft_calloc(5, 1);
	*line = get_next_line(fd);
	if (!*line)
	{
		perror("empty file~!\n");
		exit(1);
	}
}
