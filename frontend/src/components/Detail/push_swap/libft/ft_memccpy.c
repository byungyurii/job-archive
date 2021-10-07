/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbyun <gbyun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 02:05:01 by gbyun             #+#    #+#             */
/*   Updated: 2021/01/14 03:49:06 by gbyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;
	int		flag;

	if (!dst && !src)
		return (NULL);
	i = 0;
	flag = 0;
	while (i < n)
	{
		*((unsigned char *)dst + i) = *((unsigned char *)src + i);
		if (*((unsigned char *)dst + i) == (unsigned char)c)
		{
			flag = 1;
			break ;
		}
		i++;
	}
	if (flag == 0)
		return (NULL);
	else
		return (dst + i + 1);
}
