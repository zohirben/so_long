/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbenaiss <zbenaiss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:09:31 by zbenaiss          #+#    #+#             */
/*   Updated: 2023/04/09 17:09:19 by zbenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*cut_stock(char *save, int i);
int		checkN(char *str);
char	*ft_strdupgnl(char *s1);
char	*ft_strjoingnl(char *s1, char *s2, size_t size);
char	*ft_substrgnl(char *s, unsigned int start, size_t len);
size_t	ft_strlengnl(const char *str);
void	*ft_callocgnl(size_t count, size_t size);

#endif