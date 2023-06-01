/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_arrow_movs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:08:25 by lwencesl          #+#    #+#             */
/*   Updated: 2023/06/01 14:26:45 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	my_close(int keycode, t_win *win)
{
	mlx_destroy_window(win->mlx, win->mlx_win);
	return (0);
}

int	mov_left(int keycode, t_win *win, t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (map->mapa[++i])
		if (map->mapa[i][0] == 'p')
			return (0);
	i = -1;
	while (map->mapa[++i])
	{
		j = -1;
		while (map->mapa[i][++j])
		{
			if (map->mapa[i][j] == 'p')
			{
				map->mapa[i][j - 1] = map->mapa[i][j];
				map->mapa[i][j] = '0';
			}
		}
	}
	return (0);
}

int	mov_right(int keycode, t_win *win, t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (map->mapa[++i])
		if (map->mapa[i][ft_strlen(map->mapa[i])] == 'p')
			return (0);
	i = -1;
	while (map->mapa[++i])
	{
		j = -1;
		while (map->mapa[i][++j])
		{
			if (map->mapa[i][j] == 'p')
			{
				map->mapa[i][j + 1] = map->mapa[i][j];
				map->mapa[i][j] = '0';
			}
		}
	}
	return (0);
}

int	mov_up(int keycode, t_win *win, t_map *map)
{
	return (0);
}

int	mov_down(int keycode, t_win *win, t_map *map)
{
	return (0);
}