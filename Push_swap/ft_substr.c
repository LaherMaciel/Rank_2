/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 23:21:40 by lwencesl          #+#    #+#             */
/*   Updated: 2022/10/29 23:33:56 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	j;
	char	*str;

	if (start >= ft_strlen(s))
	{
		str = (char *)malloc(sizeof(char));
		*str = 0;
		return (str);
	}
	if (len >= ft_strlen(s))
		len = ft_strlen(s) - start;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	j = 0;
	while (start < ft_strlen(s) && j < len)
	{
		str[j++] = s[start++];
	}
	str[j] = '\0';
	return (str);
}
