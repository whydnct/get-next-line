/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-m <aperez-m@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 10:33:32 by aperez-m          #+#    #+#             */
/*   Updated: 2022/12/29 18:21:39 by aperez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3 
# endif

size_t	ft_strlen(char *str);
char	*ft_strjoin(char *temp_stash, char *buff);
char	*ft_strchr(char *s, int c);
char	*fill_ret(char *s);
char	*fill_temp_stash(int fd, char *temp_stash);
char	*trim_temp_stash(char *in_str);
char	*get_next_line(int fd);

#endif