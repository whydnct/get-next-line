/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-m <aperez-m@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 10:32:45 by aperez-m          #+#    #+#             */
/*   Updated: 2022/12/18 17:12:30 by aperez-m         ###   ########.fr       */
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

char	*get_next_line(int fd)
{
}
