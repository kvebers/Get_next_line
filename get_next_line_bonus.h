/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:39:44 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/16 10:20:00 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

#define BUFFER_SIZE 42

char	*ft_strchr(const char *s, int c);
char	*get_next_line(int fd);
int		ft_strlen(const char *str);
char	*ft_strjoin(char *temp, char *buffer, size_t cnt1, size_t cnt2);

#endif