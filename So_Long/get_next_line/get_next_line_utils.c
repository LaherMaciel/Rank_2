/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <laherwpayotmaciel@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:47:34 by lwencesl          #+#    #+#             */
/*   Updated: 2023/01/21 19:54:12 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	clean(int newline, int x, int y, char *buffer)
{
	while (buffer[x])
	{
		if (newline == 1)
			buffer[y++] = buffer[x];
		if (buffer[x] == '\n')
			newline = 1;
		buffer[x] = 0;
		x++;
	}
	return (newline);
}

size_t	ft_strlen(char *a)
{
	size_t	i;

	if (!a)
		return (0);
	i = 0;
	while (a[i] != '\0' && a[i] != '\n')
		i++;
	if (a[i] == '\n')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*sjoin;
	size_t	i;

	sjoin = (char *) malloc((ft_strlen(s1) + ft_strlen(s2)) * sizeof(char) + 1);
	if (!sjoin)
		return (NULL);
	i = -1;
	while (s1 && s1[++i] != '\0')
		sjoin[i] = s1[i];
	free(s1);
	if (!s1)
		i = 0;
	while (*s2)
	{
		sjoin[i++] = *s2;
		if (*s2++ == '\n')
			break ;
	}
	sjoin[i] = '\0';
	return (sjoin);
}
