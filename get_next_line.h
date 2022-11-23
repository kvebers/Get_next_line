/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:39:44 by kvebers           #+#    #+#             */
/*   Updated: 2022/11/22 19:01:37 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H


# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

char	*get_next_line(int fd);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
int	    ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
#endif