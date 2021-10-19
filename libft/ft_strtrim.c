/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 20:49:38 by                   #+#    #+#             */
/*   Updated: 2021/10/07 13:05:19 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strtrim(char const	*s1, char const	*set)
{
	size_t	length;
	size_t	start;
	size_t	end;

	if (!s1)
		return (NULL);
	start = 0;
	length = ft_strlen(s1);
	while (start < length && ft_strchr(set, s1[start]))
		start++;
	end = length - 1;
	while (end && ft_strchr(set, s1[end]))
		end--;
	length = end - start + 1;
	return (ft_substr(s1, start, length));
}
