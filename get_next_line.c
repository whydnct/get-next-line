/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-m <aperez-m@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 10:32:45 by aperez-m          #+#    #+#             */
/*   Updated: 2023/01/03 18:26:06 by aperez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*fill_temp_stash(int fd, char *temp_stash)
{
	char	*buff;
	int		chars_read;

	buff = malloc(BUFFER_SIZE + 1);
	if (buff == NULL)
		return (NULL);
	chars_read = 1;
	while (chars_read && !ft_strchr(temp_stash, '\n'))
	{
		chars_read = read(fd, buff, BUFFER_SIZE);
		if (chars_read == -1)
		{
			free (buff);
			free (temp_stash);
			return (NULL);
		}
		buff[chars_read] = '\0';
		temp_stash = ft_strjoin(temp_stash, buff);
	}
	free (buff);
	return (temp_stash);
}

char	*get_next_line(int fd)
{
	static char	*temp_stash;
	char		*ret;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	temp_stash = fill_temp_stash(fd, temp_stash);
	if (temp_stash == NULL)
		return (NULL);
	ret = fill_ret(temp_stash);
	temp_stash = trim_temp_stash(temp_stash);
	return (ret);
}
