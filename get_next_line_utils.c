/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-m <aperez-m@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 10:33:22 by aperez-m          #+#    #+#             */
/*   Updated: 2022/12/29 19:18:14 by aperez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *temp_stash, char *buff)
{
	size_t	i;
	size_t	j;
	char	*ret;

	if (!temp_stash)
	{
		temp_stash = malloc(1);
		temp_stash[0] = '\0';
	}
	if (!temp_stash || !buff)
		return (NULL);
	ret = malloc((ft_strlen(temp_stash) + ft_strlen(buff)) + 1);
	if (ret == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (temp_stash)
		while (temp_stash[++i] != '\0')
			ret[i] = temp_stash[i];
	while (buff[j] != '\0')
		ret[i++] = buff[j++];
	ret[ft_strlen(temp_stash) + ft_strlen(buff)] = '\0';
	free(temp_stash);
	return (ret);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return (s + i);
		i++;
	}
	return (NULL);
}

char	*fill_ret(char *s)
{
	char	*ret;
	int		i;
	int		l_max;

	i = 0;
	if (!*s)
		return (NULL);
	while (s[i] != '\n' && s[i])
		i++;
	l_max = i;
	ret = malloc(l_max + 2);
	if (ret == NULL)
		return (NULL);
	i = -1;
	while (++i < l_max)
		ret[i] = s[i];
	if (s[i] == '\n')
	{
		ret[i] = '\n';
		i++;
	}
	ret[i] = 0;
	return (ret);
}

char	*trim_temp_stash(char *temp_stash)
{
	char	*ret;
	int		ret_len;
	int		newline_i;
	int		i;

	i = 0;
	while (temp_stash[i] && temp_stash[i] != '\n')
		i++;
	if (!temp_stash[i])
	{
		free(temp_stash);
		return (NULL);
	}
	newline_i = i;
	ret_len = ft_strlen(temp_stash) - newline_i - 1;
	ret = malloc(ret_len + 1);
	if (ret == NULL)
		return (NULL);
	i = -1;
	while (++i < ret_len)
		ret[i] = temp_stash[newline_i + 1 + i];
	ret[i] = 0;
	free(temp_stash);
	return (ret);
}
