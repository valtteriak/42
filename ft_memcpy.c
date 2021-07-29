/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinnune <vkinnune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 16:59:05 by vkinnune          #+#    #+#             */
/*   Updated: 2021/07/27 10:25:01 by vkinnune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

char	*ft_memcpy(char *ptr, int size)
{
	if (ptr == 0)
		return malloc(size);
	
	int newSize;
	char* newPtr;

	newSize = size * 2;
	newPtr = malloc(newSize);

	const char *s = ptr;
	char *d = newPtr;

	while (*s != '\0')
		*d++ = *s++;

	free(ptr);
	return (newPtr);
}
