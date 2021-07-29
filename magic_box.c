/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magic_box.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinnune <vkinnune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 19:54:40 by vkinnune          #+#    #+#             */
/*   Updated: 2021/07/28 20:06:40 by vkinnune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

char	**sort_map(char *map)
{
	int i;
	int j;
	char** ptr_map;
	int size = charlen(map);
	int ptr_i;

	ptr_map = malloc(8 * (lines + 1));
	ptr_map[0] = malloc(lines + size);

	i = 5;
	j = 0;
	ptr_i = 0;
	while(map[i] != '\0')
	{
		while(map[i] != '\n')
		{
			ptr_map[j][ptr_i] = map[i];
			i++;
			ptr_i++;
		}
		ptr_map[j][ptr_i] = '\0';
		i++;
		ptr_i++;
		ptr_map[j + 1] = &ptr_map[j][ptr_i];
		j++;
		ptr_i = 0;
	}
	ptr_map[j + 1] = 0;
	return (ptr_map);
}

void	conv_int(char *map)
{
	map_array = sort_map(map);
	int x;
	int i;
	int obstacles;
	int size = charlen(map);
	len = int_len(map_array);

	x = 0;
	i = 0;
	obstacles = 0;

	map_int = malloc(8 * (lines + 1));
	map_int[0] = malloc(sizeof(int) * lines + size);

	if (map_array == 0)
		return;

	while (x != lines)
	{
		while (i != len)
		{
			if (map_array[x][i] == obstacle_char)
				map_int[x][i] = 1;
			if (map_array[x][i] == empty_char)
				map_int[x][i] = 0;
			i++;
		}
		map_int[x][i] = '\0';
		map_int[x + 1] = &map_int[x][i + 1];
		x++;
		i = 0;
	}
	map_int[x + 1] = 0;
	free(map_array);

	x = 0;
	i = 0;
}
void	dataprep()
{
	int i;
	int x;

	i = 1;
	x = 0;

	while (x != lines)
		{
			while(i != len)
			{
				if (x > 0)
				{
					if (map_int[x][i] || map_int[x - 1][i] || map_int[x ][i - 1] > 0)
					{
						map_int[x][i] = map_int[x][i - 1] +  map_int[x - 1][i] - map_int[x - 1][i - 1] + map_int[x][i];
						i++;
					}
					else
					{
						i++;
					}
				}
				else if (map_int[x][i] == 0)
				{ 
					if (map_int[x][i - 1] > 0)
						map_int[x][i] = 1;
					else
						map_int[x][i] = 0;
					i++;
				}
				else
				{
					i++;
				}
			}
			i = 0;
			x++;
		}
	x = 0;
	i = 0;
	while(x != lines)
	{
		while(i != len)
		{
			printf("%d ", map_int[x][i]);
			i++;
		}
		printf("\n");
		i = 0;
		x++;
	}
}

int	algo(int row, int str_nmb)
{
	int nmb;
	int height;
	int x;

	nmb = str_nmb;
	height = 0;
	x = row;
	printf("row: %d, current: %d\n", row, nmb);
	printf("location: %d\n", map_int[row][nmb]);
	int str_value = map_int[x][nmb];
	
	int lenb = len - nmb;
	int max = lines - 1;
	if (lenb < max)
		max = lenb;

	printf("%d\n", max);
	height = max;
	while (!(map_int[x][nmb] > str_value) && (nmb != max))
	{
		nmb++;
	}
	height = nmb;
	while (!(map_int[height - 1][nmb] > str_value))
	{
		height--;
	}
	nmb = height;
	printf("%d \n %d \n", nmb, height);
	return(0);
}
/* 
void	print(int start, int length, char* map)
{
	int i;
	int x;
	char** ptr_map = sort_map(map);

	i = 0;
	x = length;
	while(x--)
	{
		while(i != length)
		{
			ptr_map[start][i] = full_char;
			i++;
		}
	}
	i = 0;
	x = 0;
	while(x != length)
	{
		printf("%s\n", ptr_map[x]);
		x++;
	}
}
 */