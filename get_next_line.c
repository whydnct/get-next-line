/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-m <aperez-m@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 10:32:45 by aperez-m          #+#    #+#             */
/*   Updated: 2022/12/26 12:35:58 by aperez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
- rellenar temp_stash
	- crear buffer
	- alocar buffer
	- leer chunck de size = buffer_size de fichero
	- ha leído algo?
		- No
			- devolver nulo
		- Sí
			- guardarlo en buffer
			- copiarlo a temp_stash
				- ¿contiene salto de línea?
					- Sí
						- free buffer
						- devolver temp_stash
					- No
						- 

			
- retornar línea de temp_stash
	- definir y alocar temp_stash
	- rellenar temp_stash	
	- hay contenido en temp_stash?
		- Sí
			- ¿Hay salto de línea en temp_stash?
				- Sí
					- copiar hasta el salto de línea desde temp_stash a ret
					- borrar hasta el salto de línea en temp_stash
					- devolver ret
				- No
					- copiar temp_stash completa a ret
					- borrar temp_stash
					- devolver ret
		- No
			- devolver nulo




*/

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
