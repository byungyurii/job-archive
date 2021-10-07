/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbyun <gbyun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 02:13:07 by gbyun             #+#    #+#             */
/*   Updated: 2021/01/24 01:31:58 by gbyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"
#include "string.h"

void	*ft_memchr(const void *ptr, int val, size_t n)
{
	unsigned char	*tmp;
	unsigned char	v;

	v = (unsigned char)val;
	tmp = (unsigned char *)ptr;

	while (n--)
	{
		if (*tmp == v)
			return ((void *)tmp);
		tmp++;
	}
	return (NULL);
}
