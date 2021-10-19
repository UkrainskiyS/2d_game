/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 20:49:41 by                   #+#    #+#             */
/*   Updated: 2021/10/06 23:19:23 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	len_s;
	size_t	len_substr;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (len_s <= start)
		len_substr = 0;
	else if (start + len > len_s)
		len_substr = len_s - start;
	else
		len_substr = len;
	sub_str = (char *)malloc((len_substr + 1) * sizeof(*sub_str));
	if (!sub_str)
		return (NULL);
	ft_strlcpy(sub_str, &s[start], len_substr + 1);
	sub_str[len_substr] = '\0';
	return (sub_str);
}
