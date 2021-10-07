/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbyun <gbyun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 21:37:13 by gbyun             #+#    #+#             */
/*   Updated: 2021/01/14 03:49:55 by gbyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*r;
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = (size_t)ft_strlen((char *)s1) - 1;
	while (s1[end] && ft_strchr(set, s1[end]) && end >= start)
		end--;
	if (!(r = (char *)malloc(end - start + 2)))
		return (NULL);
	ft_strlcpy(r, (char *)s1 + start, end - start + 2);
	return (r);
}
