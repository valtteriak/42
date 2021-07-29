/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinnune <vkinnune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 14:32:58 by vkinnune          #+#    #+#             */
/*   Updated: 2021/07/28 20:06:05 by vkinnune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"
#include <stdio.h>

void	map_file(char *filename)
{
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		(write(2, "File is empty or missing", 25));
		close(fd);
	}
	else
	{
		ft_read(fd);
	}
	close(fd);
}

void	map_info(char *map)
{
	lines = map[0] - '0';
	empty_char = map[1];
	obstacle_char = map[2];
	full_char = map[3];
}

int	checkvalidmap(char *map)
{
	int not_valid;
	int checklines;
	int i;

	i = 0;
	checklines = -1;
	not_valid = 0;
	if (map[4] != '\n')
		not_valid = 1;

	while (map[i] != '\0')
	{
		if(map[i] == '\n') checklines++;
		i++;
	}
	if (checklines != lines)
		not_valid = 1;

	return (not_valid);
}

void	ft_read(int fd)
{
	int i;
	char c;
	int size;

	size = 2;
	i = 0;
	map = ft_memcpy(map, size);
	while (read(fd, &c, 1))
	{
		map[i] = c;
		if	(i == size)
		{
			map = ft_memcpy(map, size);
			size = size * 2;
		}
		i++;
	}
	map[i] = '\0';
}

int		int_len(char **map_array)
{
	int i;

	i = 1;
	while (map_array[0][i] != '\0')
	{
		i++;
	}
	return(i);
}

int		main(int argc, char **argv)
{
	if (argc == 1)
		ft_read(0);
	else if (argc > 2)
		write(2, "Too many arguments.\n", 20);
	else
		map_file(argv[1]);
	map_info(map);
	printf("%s\n", map);

	if(checkvalidmap(map))
		return (0);

	conv_int(map);
	dataprep();
	algo(0, 0);
	return (0);
}
