/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 00:53:09 by                   #+#    #+#             */
/*   Updated: 2021/10/12 12:00:43 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t	ft_strlen(const char	*str)
{
	size_t	i;

	i = 0;
	while (*(str + i))
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	size_t	i;

	i = 0;
	while (*(str + i))
	{
		if (*(str + i) == (unsigned char)c)
			return ((char *)(str + i));
		i++;
	}
	if (str[i] == (char)c)
		return ((char *)(str + i));
	return (NULL);
}

size_t	ft_strlcpy(char	*dst, const char	*src, size_t	size)
{
	size_t	i;

	i = 0;
	if (size >= 1)
	{
		while (i < size - 1 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

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
