/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbyun <gbyun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 16:45:03 by gbyun             #+#    #+#             */
/*   Updated: 2021/01/19 22:58:58 by gbyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		**ft_2d_malloc_error(char **c)
{
	unsigned int	i;

	i = 0;
	while (c[i])
	{
		free(c[i]);
		c[i++] = NULL;
	}
	free(c);
	c = NULL;
	return (NULL);
}

static int		get_split_num(char const *s, char c)
{
	int				n;

	n = 0;
	while (*s)
	{
		if (*s != c)
		{
			n++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (n);
}

char			**ft_split_sub(char const *s, char c, char **dst)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			j = 0;
			while (*s && *s != c)
			{
				j++;
				s++;
			}
			if (!(dst[i] = (char *)malloc(sizeof(char) * (++j))))
				return ((char **)ft_2d_malloc_error(dst));
			ft_strlcpy(dst[i++], (char *)(s - j + 1), j);
		}
		else
			s++;
	}
	return (dst);
}

char			**ft_split(char const *s, char c)
{
	char			**dst;

	if (!s)
		return (NULL);
	if (!(dst = (char **)malloc(sizeof(char *) * (get_split_num(s, c) + 1))))
		return (NULL);
	dst[get_split_num(s, c)] = NULL;
	return (ft_split_sub(s, c, dst));
}
