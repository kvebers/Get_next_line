/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_new_temp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:50:15 by kvebers           #+#    #+#             */
/*   Updated: 2022/11/22 17:43:27 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*	Strchr 
Checks for the character in the string returns the location of the char or NULL
if the string is not found.
*/

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;

	ptr = (char *)s;
	c = c % 256;
	while (*ptr != c && *ptr != '\0')
		ptr++;
	if (*ptr == c)
		return (ptr);
	return (NULL);
}

/*	The real Deal
Reads the new_temp until reaches the read_mode = 0 and Buffer_size that includde \n
*/

char	*get_buffers(char *temp, int fd, int read_mode)
{
	char	*buffer;

	buffer = ft_calloc(BUFFER_SIZE, sizeof(char));
	if (buffer == NULL)
		return (NULL);
	while ((ft_strchr(buffer, '\n') == NULL && read_mode > 0))
	{
		read_mode = read(fd, buffer, BUFFER_SIZE);
		if (read_mode <= 0)
		{
			free(buffer);
			return (NULL);
		}
		*(buffer + read_mode) = '\0';
		if (temp != NULL)
			temp = ft_strjoin(temp, buffer);
		else 
			temp = ft_strdup(buffer);
	}
	free (buffer);
	return (temp);
}

char	*get_lines(char *temp)
{
	char	*line;
	int		cnt;

	line = NULL;
	cnt = 0;
	if (temp == NULL)
		return (NULL);
	while ((*(temp + cnt) != '\n'))
		cnt++;
	line = malloc(sizeof(char) * (cnt + 2));
	if (line == NULL)
		return (NULL);
	cnt = 0;
	while (*(temp + cnt) != '\n' && *(temp + cnt) != EOF)
	{
		*(line + cnt) = *(temp + cnt);
		cnt++;
	}
	*(line + cnt) = *(temp + cnt);
	*(line + cnt + 1) = '\0';
	return (line);
}

char	*left_over(char *temp)
{
	int 	cnt1;
	int 	cnt2;
	char	*new_temp;

	cnt1 = 0;
	cnt2 = 0;
	while (*(temp + cnt1) != '\n')
		cnt1++;
	if (*(temp + cnt1 + 1) == '\0')
	{
		free (temp);
		return (NULL);
	}
	while (*(temp + cnt1 + cnt2) != '\0')
		cnt2++;
	new_temp = malloc(sizeof(char) * (cnt2 + 1));
	if (new_temp == NULL)
		return (NULL);
	cnt2 = 0;
	while (*(temp + cnt2 + cnt1) != '\0')
	{
		*(new_temp + cnt2) = *(temp + cnt2 + 1 + cnt1);
		cnt2++;
	}
	free(temp);
	return (new_temp);
}

char	*get_next_line(int fd)
{
	static char	*temp;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp = get_buffers(temp, fd, 1);
	if (temp == NULL)
		return (NULL);
	line = get_lines(temp);
	temp = left_over(temp);
	return (line);
}
