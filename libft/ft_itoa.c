/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 20:48:37 by                   #+#    #+#             */
/*   Updated: 2021/10/08 09:27:11 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	*calloc_for_itoa(int n);
static int	zero_integer(int n);
static char	*init_min_int(char *str);
static void	run_itoa(int n, int zero_int, char *new_str);

char	*ft_itoa(int n)
{
	char	*new_str;
	int		zero_int;

	new_str = calloc_for_itoa(n);
	if (!new_str)
		return (NULL);
	zero_int = zero_integer(n);
	if (n == 0)
		new_str[0] = '0';
	else if (n == -2147483648)
		return (init_min_int(new_str));
	else
		run_itoa(n, zero_int, new_str);
	return (new_str);
}

static char	*init_min_int(char *str)
{
	str[0] = '-';
	str[1] = '2';
	str[2] = '1';
	str[3] = '4';
	str[4] = '7';
	str[5] = '4';
	str[6] = '8';
	str[7] = '3';
	str[8] = '6';
	str[9] = '4';
	str[10] = '8';
	str[11] = '\0';
	return (str);
}

static void	run_itoa(int n, int zero_int, char *new_str)
{
	size_t	i;

	i = 0;
	if (n < 0)
	{
		n = -1 * n;
		new_str[i] = '-';
		i++;
	}
	while (zero_int != 0)
	{
		new_str[i] = (char)(((n / zero_int) % 10) + '0');
		zero_int /= 10;
		i++;
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

static char	*calloc_for_itoa(int n)
{
	int	len;

	if (n == 0)
		return (ft_calloc(2, sizeof(char)));
	len = 0;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (ft_calloc(len + 2, sizeof(char)));
}
