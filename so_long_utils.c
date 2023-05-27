/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbenaiss <zbenaiss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 13:08:34 by zbenaiss          #+#    #+#             */
/*   Updated: 2023/05/27 17:34:38 by zbenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strjoinso(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s1 || !s2)
		return (0);
	str = (char *)malloc(ft_strlengnl(s1) + ft_strlengnl(s2) + 1);
	if (!str)
		return (0);
	i = 0;
	j = 0;
	while (s1[i])
		str[j++] = s1[i++];
	i = 0;
	while (s2[i])
		str[j++] = s2[i++];
	str[j] = '\0';
	free(s1);
	return (str);
}

void	check_corners(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[j])
	{
		while (data->map[j][i])
		{
			if (!(data->map[0][i] == '1') || !(data->map[data->lines_len
					- 1][i] == '1') || !(data->map[j][0] == '1')
				|| !(data->map[j][data->width_len - 1] == '1'))
			{
				perror("Map corners machi homa hadok\n");
				exit(1);
			}
			i++;
		}
		i = 0;
		j++;
	}
}

void	ber_check(char *str, char *format)
{
	int	i;
	int	len;

	i = ft_strlen(str) - 1;
	len = ft_strlen(format) - 1;
	while (len > 0)
	{
		if (str[i] == format[len] && str[i - 1] == format[len - 1])
		{
			len--;
			i--;
		}
		else
			break ;
	}
	if (len != 0)
	{
		perror("wrong file format!\n");
		exit(1);
	}
}

void	free_things(char **visited, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->lines_len)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
}

void	digit_check(t_data *data, int j, int i)
{
	if (data->map[j][i] != 'P' && data->map[j][i] != 'E'
		&& data->map[j][i] != 'C' && data->map[j][i] != '0'
		&& data->map[j][i] != '1')
	{
		perror("Check Input!\n");
		exit(1);
	}
	else if (data->map[j][i] == 'P')
	{
		data->p_count++;
		data->p_y = j;
		data->p_x = i;
	}
	else if (data->map[j][i] == 'E')
	{
		data->e_count++;
		data->e_y = j;
		data->e_x = i;
	}
	else if (data->map[j][i] == 'C')
		data->c_count++;
}
