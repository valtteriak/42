/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinnune <vkinnune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 16:53:41 by vkinnune          #+#    #+#             */
/*   Updated: 2021/07/27 15:55:06 by vkinnune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int	charlen(char *map)
{
	int i;

	i = 0;
	while (map[i] != '\0')
	{
		i++;
	}
	return (i);
}
/* 
int		ft_strlen(char *map)
{
	int i;

	i = 0;
	while (map[i] != '\0' && map[i] != '\n')//count length of string
		++i;
	return (i);
}
 */