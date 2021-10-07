/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbyun <gbyun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 02:03:53 by gbyun             #+#    #+#             */
/*   Updated: 2021/01/14 01:52:39 by gbyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, void *src, size_t len)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	*ptr2;

	if (!dst && !src)
		return (NULL);
	ptr = (unsigned char *)dst;
	ptr2 = (unsigned char *)src;
	if (dst > src)
	{
		i = len;
		while (i-- > 0)
			ptr[i] = ptr2[i];
	}
	else
	{
		i = 0;
		while (i++ < len)
			ptr[i - 1] = ptr2[i - 1];
	}
	return (dst);
}
