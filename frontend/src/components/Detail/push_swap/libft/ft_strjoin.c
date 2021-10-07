/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbyun <gbyun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 20:57:20 by gbyun             #+#    #+#             */
/*   Updated: 2021/01/18 18:04:54 by gbyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*r;
	char	*tmp;

	if (!s1 || !s2)
		return (NULL);
	r = (char *)malloc(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1);
	if (r == NULL)
		return (NULL);
	tmp = r;
	while (*s1)
		*r++ = *s1++;
	while (*s2)
		*r++ = *s2++;
	*r = '\0';
	return (tmp);
}
