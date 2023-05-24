/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 19:13:45 by lwencesl          #+#    #+#             */
/*   Updated: 2023/05/18 16:13:56 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**read_file(void)
{
	int		fds;
	char	*a;
	int		cont;

	cont = 1;
	fds = open("mapa.txt", O_RDONLY);
	ft_printf("\n");
	while ((a = get_next_line(fds)) != NULL)
	{
		ft_printf("%i - %s", cont, a);
		free(a);
		cont++;
	}
	ft_printf("\n\n");
	return (0);
}

char	**creat_map(void)
{
	int		fds;
	char	*a;
	char 	**map;
	int		i;

	i = 0;
	a = "o";
	map = NULL;
	fds = open("test.txt", O_RDONLY);
	ft_printf("\n");
	while (a != NULL)
	{
		a = get_next_line(fds);
		map[i++] = a;
		free(a);
	}
	ft_printf("\n\n");
	return (map);
}

int	map_base_check(char **map)
{
	int	x;
	int	y;
	int	x_max_len;
	int	y_max_len;
	int	player;
	int	exit;		
	int	collectible;

	x = -1;
	player = 0;
	exit = 0;
	collectible = 0;
	x_max_len = ft_strstrlen(map);
	while (x <= x_max_len)
	{
		y = -1;
		y_max_len = ft_strlen(map[x]);
		while (y <= y_max_len)
		{
			if ((x == 0 && y == 0 && map[x][y] != '1') || (x == x_max_len && y == y_max_len && map[x][y] != '1'))
				return (0);
			else if ((x == 0 && map[x][y] != '1') || (y == 0 && map[x][y] != '1'))
				return (0);
			else if ((x == x_max_len && map[x][y] != '1') || (y == y_max_len && map[x][y] != '1'))
				return (0);
			if (map[x][y] != 'p')
				player++;
			else if (map[x][y] != 'e')
				exit++;
			else if (map[x][y] != 'c')
				collectible++;
		}
	}
	if (player != 1 || exit != 1 || collectible < 1)
		return (0);
	return (1);
}
