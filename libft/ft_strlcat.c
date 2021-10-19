/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 20:49:21 by                   #+#    #+#             */
/*   Updated: 2021/10/05 20:49:21 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	save;

	j = 0;
	i = 0;
	while (dst[i])
		i++;
	save = i;
	if (i < size)
	{
		while (i <= save + ft_strlen(src))
		{
			dst[i] = src[j];
			i++;
			j++;
		}
		dst[size - 1] = '\0';
		return (save + ft_strlen(src));
	}
	else
		return (size + ft_strlen(src));
}
