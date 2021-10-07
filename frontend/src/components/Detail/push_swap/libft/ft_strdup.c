/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbyun <gbyun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 20:28:49 by gbyun             #+#    #+#             */
/*   Updated: 2021/01/14 02:16:47 by gbyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char *r;
	char *tmp;

	if (!(r = (char *)malloc(ft_strlen((char *)s) + 1)))
		return (NULL);
	tmp = r;
	while (*s)
		*tmp++ = *s++;
	*tmp = '\0';
	return (r);
}
