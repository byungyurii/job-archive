/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbyun <gbyun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 20:39:06 by gbyun             #+#    #+#             */
/*   Updated: 2021/01/18 18:06:30 by gbyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char				*r;
	unsigned int		i;

	if (!s)
		return (NULL);
	if (!(r = (char *)malloc(ft_strlen((char *)s) + 1)))
		return (NULL);
	i = 0;
	while (s[i])
	{
		r[i] = f(i, (char)s[i]);
		i++;
	}
	r[i] = '\0';
	return (r);
}
