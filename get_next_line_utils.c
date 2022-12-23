/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-m <aperez-m@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 10:33:22 by aperez-m          #+#    #+#             */
/*   Updated: 2022/12/23 23:06:42 by aperez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize)
	{
		while ((i < (dstsize - 1)) && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = 0;
	}
	return (ft_strlen((char *)src));
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_l;

	i = 0;
	dst_l = ft_strlen(dst);
	if (dst_l >= size)
		return (size + ft_strlen((char *)src));
	while ((i < size - dst_l - 1) && src[i])
	{
		dst[dst_l + i] = src[i];
		i++;
	}
	dst[dst_l + i] = 0;
	return (dst_l + ft_strlen((char *)src));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	size_t	len;

	len = ft_strlen(s1) + ft_strlen(s2);
	s = malloc(len + 1);
	if (s == NULL)
		return (NULL);
	ft_strlcpy(s, s1, len + 1);
	ft_strlcat(s, s2, len +1);
	return (s);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	l;

	l = ft_strlen((char *)s);
	i = 0;
	while (i <= l)
	{
		if (s[i] == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

char	*fill_temp_stash(int fd, char *temp_stash)
{
	char	*buff;
	int		chars_read;

	printf("Entrada en fill | %s | \n", temp_stash);
	buff = malloc(BUFFER_SIZE + 1);
	if (buff == NULL)
		return (NULL);
	chars_read = read(fd, buff, BUFFER_SIZE);
	if (chars_read == 0)
		return (NULL);
	else
	{
		buff[chars_read] = '\0';
		while (chars_read)
		{
			temp_stash = ft_strjoin(temp_stash, buff);
			printf("Entrada en bucle | %s | \n", temp_stash);
			if (ft_strchr(temp_stash, '\n'))
			{
				free (buff);
				return (temp_stash);
			}
			chars_read = read(fd, buff, BUFFER_SIZE);
			buff[chars_read] = '\0';
		}
		free (buff);
		return (temp_stash);
	}
}
