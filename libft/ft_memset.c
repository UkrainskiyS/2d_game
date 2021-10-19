/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 20:48:55 by                   #+#    #+#             */
/*   Updated: 2021/10/05 20:48:55 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *dest, int c, size_t n)
{
	size_t	index;

	index = 0;
	while (index < n)
	{
		*(unsigned char *)(dest + index) = (unsigned char)c;
		index++;
	}
	return (dest);
}
