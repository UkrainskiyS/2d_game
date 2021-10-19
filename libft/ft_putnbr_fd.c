/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerissa <amerissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 20:49:05 by                   #+#    #+#             */
/*   Updated: 2021/10/16 11:52:06 by amerissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	zero_integer(int n);

void	ft_putnbr_fd(int n, int fd)
{
	int		zero_int;
	char	num;

	zero_int = zero_integer(n);
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		write(fd, "-", 1);
		n = n * -1;
	}
	else if (n == 0)
		write(fd, "0", 1);
	while (zero_int != 0)
	{
		num = (char)(((n / zero_int) % 10) + '0');
		write(fd, &num, 1);
		zero_int /= 10;
	}
}

static int	zero_integer(int n)
{
	int	i;

	if (n < 0)
		n = n * -1;
	if (n > 999999999)
		return (1000000000);
	i = 1;
	while (i <= n)
		i *= 10;
	return (i / 10);
}
