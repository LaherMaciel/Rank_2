/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_movs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:08:25 by lwencesl          #+#    #+#             */
/*   Updated: 2023/06/06 21:09:10 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	mov_left(t_win *win)
{
	t_data	img;
	int		i;
	int		j;

	i = 0;
	while (win->mapa[++i])
	{
		j = 0;
		while (win->mapa[i][++j])
		{
			if (win->mapa[i][j] == 'p')
			{
				if (win->mapa[i][j - 1] == 'e')
					my_close(win);
				if (win->mapa[i][j - 1] != '1')
				{
					win->mapa[i][j - 1] = 'p';
					win->mapa[i][j] = '0';
					win->player_look = 2;
					img.img_wall = walk_left(win);
					mlx_put_image_to_window(win->mlx, win->mlx_win, img.img_player, i, j);
				}
			}
		}
	}
}

void	mov_right(t_win *win)
{
	t_data	img;
	int		i;
	int		j;

	i = 0;
	while (win->mapa[++i])
	{
		j = 0;
		while (win->mapa[i][++j])
		{
			if (win->mapa[i][j] == 'p')
			{
				if (win->mapa[i][j + 1] == 'e')
					my_close(win);
				if (win->mapa[i][j + 1] != '1')
				{
					win->mapa[i][j + 1] = 'p';
					win->mapa[i][j] = '0';
					win->player_look = 3;
					j++;
					img.img_wall = walk_right(win);
					mlx_put_image_to_window(win->mlx, win->mlx_win, img.img_player, i, j);
				}
			}
		}
	}
}

void	mov_up(t_win *win)
{
	t_data	img;
	int		i;
	int		j;

	i = 0;
	while (win->mapa[++i])
	{
		j = 0;
		while (win->mapa[i][++j])
		{
			if (win->mapa[i][j] == 'p')
			{
				if (win->mapa[i - 1][j] == 'e')
					my_close(win);
				if (win->mapa[i - 1][j] != '1')
				{
					win->mapa[i - 1][j] = 'p';
					win->mapa[i][j] = '0';
					win->player_look = 0;
					img.img_wall = walk_up(win);
					mlx_put_image_to_window(win->mlx, win->mlx_win, img.img_player, i, j);
				}
			}
		}
	}
}

void	mov_down(t_win *win)
{
	t_data	img;
	int		i;
	int		j;

	i = 0;
	while (win->mapa[++i])
	{
		j = 0;
		while (win->mapa[i][++j])
		{
			if (win->mapa[i][j] == 'p')
			{
				if (win->mapa[i - 1][j] == 'e')
					my_close(win);
				if (win->mapa[i + 1][j] != '1')
				{
					win->mapa[i + 1][j] = 'p';
					win->mapa[i][j] = '0';
					win->player_look = 1;
					i++;
					img.img_wall = walk_down(win);
					mlx_put_image_to_window(win->mlx, win->mlx_win, img.img_player, i, j);
				}
			}
		}
	}
}
