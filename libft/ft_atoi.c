/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 21:54:04 by                   #+#    #+#             */
/*   Updated: 2021/10/09 21:54:04 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	make_integer(const char *str, int minus)
{
	int		int_;
	size_t	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	int_ = 0;
	if (!ft_strncmp(str, "-2147483648", 11))
		return (-2147483648);
	while (str[i] >= '0' && str[i] <= '9')
	{
		int_ = int_ * 10 + (str[i] - '0');
		if (int_ < 0)
		{
			if (minus == -1)
				return (0);
			return (-1);
		}
		i++;
	}
	return (int_ * minus);
}

int	ft_atoi(const char *str)
{
	int		minus;
	int		number;
	size_t	i;

	number = 0;
	minus = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i] == '-')
			minus = -1;
	return (make_integer(&str[i], minus));
}
