/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 20:49:10 by                   #+#    #+#             */
/*   Updated: 2021/10/09 21:59:20 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_elements_in_array(char const *s, char c)
{
	size_t	i;
	size_t	count_sep;

	i = 0;
	count_sep = 0;
	if (s[i] != c && ft_strchr(s, c))
		count_sep++;
	while (s[i])
	{
		if (s[i] == c)
		{
			while (s[i] == c)
			{
				i++;
				if (s[i] != c && s[i])
					count_sep++;
			}
		}
		else
			i++;
	}
	return (count_sep);
}

void	*free_for_split(char **arr, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

static void	*substr_for_split(char **arr, char const *s, t_split *str,
								t_split *array)
{
	arr[array->length] = ft_substr(s, str->start, str->length);
	if (!arr[array->length])
		return (free_for_split(arr, array->length));
	array->length++;
	return (arr);
}

static void	*run_split(char **arr, char const *s, char c)
{
	size_t			i;
	t_split			str;
	t_split			array;

	i = 0;
	array.length = 0;
	array.start = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			str.start = array.start;
			str.length = (i - array.start);
			if (i > array.start && !substr_for_split(arr, s, &str, &array))
				return (NULL);
			array.start = i + 1;
		}
		i++;
	}
	str.start = array.start;
	str.length = (i - array.start);
	if (i > array.start && i > 0 && !substr_for_split(arr, s, &str, &array))
		return (NULL);
	arr[array.length] = 0;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	elements;

	if (!s)
		return (NULL);
	elements = count_elements_in_array(s, c);
	if (elements == 0 && *s == '\0')
		arr = (char **)malloc(sizeof(s));
	else if (elements == 1)
		arr = (char **)malloc(2 * sizeof(s));
	else
		arr = (char **) malloc((elements + 2) * sizeof(s));
	if (!arr)
		return (NULL);
	if (!run_split(arr, s, c))
		return (NULL);
	return (arr);
}
