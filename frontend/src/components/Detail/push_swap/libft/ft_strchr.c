/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbyun <gbyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 02:11:13 by gbyun             #+#    #+#             */
/*   Updated: 2021/01/07 00:16:34 by gbyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
		if ((char)*s++ == (char)c)
			return ((char *)(--s));
	if ((char)*s == (char)c)
		return ((char *)s);
	return (NULL);
}
