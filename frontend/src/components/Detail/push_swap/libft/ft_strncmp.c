/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbyun <gbyun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 19:06:52 by gbyun             #+#    #+#             */
/*   Updated: 2021/01/12 02:18:26 by gbyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

int		ft_strncmp(char *s1, char *s2, size_t n)
{
	while (*s1 && *s2 && n > 0)
	{
		if (*s1++ != *s2++)
		{
			return ((unsigned char)*(--s1) - (unsigned char)*(--s2));
		}
		n--;
	}
	if (n != 0)
	{
		return ((unsigned char)*s1 - (unsigned char)*s2);
	}
	return (0);
}
