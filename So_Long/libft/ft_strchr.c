/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 21:33:04 by lwencesl          #+#    #+#             */
/*   Updated: 2023/06/20 16:10:52 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief 
 *
 * @param str
 * @param c
 * @return char*
 */
char	*ft_strchr(const char *str, int c)
{
	size_t	a;

	a = -1;
	while (++a <= ft_strlen(str))
		if (((unsigned char *)str)[a] == (unsigned char) c)
			return ((char *)str + a);
	return (NULL);
}
