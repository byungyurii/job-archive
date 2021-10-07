/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbyun <gbyun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 18:46:22 by gbyun             #+#    #+#             */
/*   Updated: 2021/01/12 01:29:59 by gbyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *str, int ch)
{
	char	*tmp;

	tmp = str - 1;
	while (*str)
		str++;
	while (str != tmp)
	{
		if (*str == (char)ch)
			return (str);
		str--;
	}
	return (NULL);
}
