/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbyun <gbyun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 20:29:39 by gbyun             #+#    #+#             */
/*   Updated: 2021/01/15 16:38:49 by gbyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_get_len(long n)
{
	long	tmp;
	int		len;

	tmp = ((long)n < 0 ? -n : n);
	len = 1;
	while (tmp >= 10)
	{
		tmp /= 10;
		len++;
	}
	return (len);
}

static void		ft_itoa_ite(long tmp, char *r, int len)
{
	if (tmp == 0)
	{
		*r = '0';
		return ;
	}
	while (tmp > 0)
	{
		*(r + --len) = (tmp % 10) + '0';
		tmp /= 10;
	}
}

char			*ft_itoa(int n)
{
	char	*r;
	long	tmp;
	int		len;

	tmp = (long)n;
	len = ft_get_len(tmp);
	if (tmp < 0)
	{
		if (!(r = (char *)malloc(++len + 1)))
			return (NULL);
		*r = '-';
		tmp *= -1;
	}
	else
	{
		if (!(r = (char *)malloc(len + 1)))
			return (NULL);
	}
	ft_itoa_ite(tmp, r, len);
	*(r + len) = '\0';
	return (r);
}
