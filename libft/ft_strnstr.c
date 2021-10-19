/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 18:52:00 by mrudge            #+#    #+#             */
/*   Updated: 2021/10/10 10:39:43 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *dst, const char *src, size_t n)
{
	size_t	len_src;

	if (*src == '\0')
		return ((char *) dst);
	len_src = ft_strlen(src);
	while (*dst && n >= len_src)
	{
		if (*dst == *src && ft_memcmp(dst, src, len_src) == 0)
			return ((char *) dst);
		dst++;
		n--;
	}
	return (NULL);
}
