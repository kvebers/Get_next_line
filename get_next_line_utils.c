/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:39:41 by kvebers           #+#    #+#             */
/*   Updated: 2022/11/22 19:01:18 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	Strlen
Return length of the string.
*/
# include "get_next_line.h"

void	*ft_memset(void *b, int c, size_t len)
{	
	size_t	cnt;
	char	*b_char;

	b_char = (char *)b;
	cnt = 0;
	while (cnt < len)
	{
		*(b_char + cnt) = c;
		cnt++;
	}
	return (b_char);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	*ptr;

	if (size != 0 && count > SIZE_MAX / size)
		return (NULL);
	ptr = malloc(count * size);
	if (ptr == NULL)
		return (ptr);
	ft_memset(ptr, 0, count * size);
	return (ptr);
}

char	*ft_strdup(const char *s1)
{
	int		counter;
	int		counter1;
	char	*dest;

	counter = 0;
	counter1 = 0;
	while (*(s1 + counter) != '\0')
		counter++;
	dest = ft_calloc((counter + 1), sizeof(char));
	if (dest == NULL)
		return (NULL);
	while (counter1 < counter)
	{
		*(dest + counter1) = *(s1 + counter1);
		counter1++;
	}
	return (dest);
}

int	ft_strlen(const char *str)
{
	int	counter;

	counter = 0;
	while (*(str + counter) != 0)
		counter++;
	return (counter);
}

/*	Strjoin
Combines two strings
Small modification from original to not implement ft_calloc function
*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	counter1;
	size_t	counter2;
	size_t	counter3;
	char	*dest;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	counter1 = ft_strlen((char *)s1);
	counter2 = ft_strlen((char *)s2);
	counter3 = 0;
	dest = ft_calloc((counter1 + counter2 + 1), sizeof(char));
	if (dest == NULL)
		return (NULL);
	while (counter3 < counter1)
	{
		*(dest + counter3) = *(s1 + counter3);
		counter3++;
	}
	counter3 = 0;
	while (counter3 < counter2)
	{
		*(dest + counter1 + counter3) = *(s2 + counter3);
		counter3++;
	}
	return (dest);
}
