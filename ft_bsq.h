/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinnune <vkinnune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 14:32:49 by vkinnune          #+#    #+#             */
/*   Updated: 2021/07/28 20:06:56 by vkinnune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BSQ_H
# define FT_BSQ_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

void	map_file(char *filename);
void	pipe_file();
void	ft_putchar(char c);
void	ft_putnbr(int nb);
void	ft_putstr(char *str);
char	*ft_memcpy(char *source, int size);
int		charlen(char *map);
char	**sort_map(char *map);
void	ft_read(int fd);
void	conv_int(char *map);
int		int_len(char **map_array);
void	dataprep();
int		algo(int row, int str_nmb);
void	print(int start, int length, char* map);

int		**map_int;
int		lines;
char	empty_char;
char	obstacle_char;
char	full_char;
char	*map;
char	**map_array;
int		len;

#endif
