/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:39:41 by kvebers           #+#    #+#             */
/*   Updated: 2022/11/25 12:40:30 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;

	if (s == NULL)
		return (NULL);
	ptr = (char *)s;
	c = c % 256;
	while (*ptr != c && *ptr != '\0')
		ptr++;
	if (*ptr == c)
		return (ptr);
	return (NULL);
}

int	ft_strlen(const char *str)
{
	int	counter;

	counter = 0;
	while (*str++ != 0)
		counter++;
	return (counter);
}

char	*ft_strjoin(char *temp, char *buffer, size_t cnt1, size_t cnt2)
{
	char	*new_temp;

	if (temp == NULL)
	{
		temp = malloc(sizeof(char));
		*temp = '\0';
	}
	if (temp == NULL || buffer == NULL)
		return (NULL);
	new_temp = malloc((ft_strlen(buffer) + ft_strlen(temp) + 1) * sizeof(char));
	if (new_temp == NULL)
		return (NULL);
	while (*(temp + cnt1) != '\0')
	{
		*(new_temp + cnt1) = *(temp + cnt1);
		cnt1++;
	}
	while (*(buffer + cnt2) != '\0')
	{
		*(new_temp + cnt1 + cnt2) = *(buffer + cnt2);
		cnt2++;
	}
	*(new_temp + cnt1 + cnt2) = '\0';
	return (free(temp), new_temp);
}
