/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbyun <gbyun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 03:18:23 by gbyun             #+#    #+#             */
/*   Updated: 2021/01/14 04:11:06 by gbyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_fd_rec(long n, int fd)
{
	char	c;

	if (n / 10)
		ft_putnbr_fd_rec(n / 10, fd);
	c = '0' + n % 10;
	write(fd, &c, 1);
}

void		ft_putnbr_fd(int n, int fd)
{
	long	tmp;

	tmp = (long)n;
	if (tmp < 0)
	{
		write(fd, "-", 1);
		tmp *= -1;
	}
	ft_putnbr_fd_rec(tmp, fd);
}
