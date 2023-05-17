/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 19:13:45 by lwencesl          #+#    #+#             */
/*   Updated: 2023/05/16 19:15:55 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	read_file(void)
{
	int		fds;
	char	*a;
	int		cont;

	cont = 1;
	fds = open("test.txt", O_RDONLY);
	printf("\n");
	while ((a = get_next_line(fds)) != NULL)
	{
		printf("%i - %s", cont, a);
		free(a);
		cont++;
	}
	printf("\n\n");
	return (0);
}