/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbyun <gbyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 02:05:20 by gbyun             #+#    #+#             */
/*   Updated: 2021/01/08 18:46:09 by gbyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t			dest_length;
	size_t			src_length;
	unsigned int	i;

	dest_length = ft_strlen(dest);
	src_length = ft_strlen(src);
	if (dest_length >= size)
		return (src_length + size);
	i = 0;
	while (src[i] && i + 1 + dest_length < size)
	{
		dest[dest_length + i] = src[i];
		i++;
	}
	dest[dest_length + i] = '\0';
	return (src_length + dest_length);
}
