/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 01:12:08 by                   #+#    #+#             */
/*   Updated: 2021/10/12 12:46:22 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

char	*get_next_line(int fd);

char	*ft_strchr(const char *str, int c);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char	*dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
#endif
