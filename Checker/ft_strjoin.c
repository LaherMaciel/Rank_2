/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:54:27 by marvin            #+#    #+#             */
/*   Updated: 2022/10/31 19:28:33 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
char	*ft_strjoin(char *s1, char s2)
{
	char	*sjoin;
	size_t	i;

	sjoin = (char *) malloc(((ft_strlen(s1)) + 1) * sizeof(char) + 1);
	if (!sjoin)
		return (NULL);
	i = -1;
	while (s1[++i] != '\0')
		sjoin[i] = s1[i];
	free(s1);
	sjoin[i] = s2;
	i++;
	sjoin[i] = '\0';
	ft_printf("strjoin ok");
	return (sjoin);
}
*/

char	*ft_strjoin(char *s1, char *s2)
{
	char	*sjoin;
	size_t	i;
	size_t	j;

	/*if (!s1 || !s2)
		return (NULL);*/
	sjoin = (char *) malloc((ft_strlen(s1) + ft_strlen(s2)) * sizeof(char) + 1);
	if (!sjoin)
		return (NULL);
	i = -1;
	while (s1[++i] != '\0')
		sjoin[i] = s1[i];
	j = -1;
	while (s2[++j] != '\0')
	{
		sjoin[i] = s2[j];
		i++;
	}
	sjoin[i] = '\0';
	return (sjoin);
}
