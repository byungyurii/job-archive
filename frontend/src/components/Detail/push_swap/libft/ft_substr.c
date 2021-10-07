/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbyun <gbyun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 20:42:49 by gbyun             #+#    #+#             */
/*   Updated: 2021/01/14 03:50:19 by gbyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*r;
	unsigned int	i;

	if (!s || (unsigned int)ft_strlen((char *)s) <= start || !len)
		return (ft_strdup(""));
	if (!(r = (char *)malloc(len + 1)))
		return (NULL);
	i = 0;
	ft_strlcpy(r, (char *)s + start, len + 1);
	return (r);
}
