/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:04:51 by marvin            #+#    #+#             */
/*   Updated: 2022/11/14 18:58:05 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_pos_search(const char *str, int spliter)
{
	size_t	a;
	size_t	len;

	a = -1;
	len = ft_strlen(str);
	while (++a <= len)
		if (str[a] == spliter)
			return (a);
	return (-1);
}

size_t	ft_skip(const char *str, int spliter)
{
	size_t	a;
	size_t	len;

	a = -1;
	len = ft_strlen(str);
	while (++a < len)
		if (str[a] != spliter)
			return (a);
	return (-1);
}

size_t	find_size(const char *str, char spliter)
{
	size_t	start;
	size_t	sep;
	size_t	i;
	size_t	sk;

	start = 0;
	i = 0;
	sep = 0;
	while (sep != (size_t) -1)
	{
		sk = ft_skip(str + (start + sep), spliter);
		if (sk != (size_t) - 1)
			start = start + sep + sk;
		else if (sk == (size_t) - 1)
			break ;
		sep = ft_pos_search((str + start), spliter);
		i++;
	}
	return (i);
}

char	**ft_terminator(const char *str, char spliter, char **splited)
{
	size_t	start;
	size_t	sep;
	size_t	i;
	size_t	sk;

	start = 0;
	i = 0;
	sep = 0;
	while (sep != (size_t) -1)
	{
		sk = ft_skip(str + (start + sep), spliter);
		if (sk != (size_t) - 1)
			start = start + sep + sk;
		else if (sk == (size_t) - 1)
			break ;
		sep = ft_pos_search((str + start), spliter);
		if (sep != (size_t) - 1)
			splited[i] = ft_substr(str, start, sep);
		else if (sep == (size_t) - 1)
			splited[i] = ft_substr(str, start, ft_strlen(str + start));
		i++;
	}
	splited[i] = NULL;
	return (splited);
}

char	**ft_split(char const *str, char spliter)
{
	char	**splited;

	if (!str)
		splited = (char **) malloc(sizeof(char *));
	else
		splited = (char **) malloc((find_size(str,
						spliter) + 1) * sizeof(char *));
	if (!splited)
		return (NULL);
	return (ft_terminator(str, spliter, splited));
}
