/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbyun <gbyun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 02:05:13 by gbyun             #+#    #+#             */
/*   Updated: 2021/01/14 01:30:42 by gbyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	tmp;
	unsigned int	i;

	i = 0;
	tmp = (unsigned char)c;
	while (i < len)
	{
		*((char *)b + i++) = tmp;
	}
	return (b);
}
