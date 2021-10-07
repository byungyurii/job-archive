/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbyun <gbyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 19:05:01 by gbyun             #+#    #+#             */
/*   Updated: 2021/01/07 15:01:46 by gbyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t len2;

	if (*s2 == '\0')
		return ((char *)s1);
	len2 = (size_t)ft_strlen((char *)s2);
	while (*s1 != '\0' && len-- >= len2)
	{
		if (*s1 == *s2 && ft_strncmp((char *)s1, (char *)s2, len2) == 0)
			return ((char *)s1);
		s1++;
	}
	return (NULL);
}
