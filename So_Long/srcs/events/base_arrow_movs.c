/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_arrow_movs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:08:25 by lwencesl          #+#    #+#             */
/*   Updated: 2023/06/01 19:24:05 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	mov_left(t_win *win)
{
	int	i;
	int	j;

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
				}
			}
		}
	}
	return (0);
}

int	mov_right(t_win *win)
{
	int	i;
	int	j;

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
					j++;
				}
			}
		}
	}
	return (0);
}

int	mov_up(t_win *win)
{
	int	i;
	int	j;

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
				}
			}
		}
	}
	return (0);
}

int	mov_down(t_win *win)
{
	int	i;
	int	j;

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
					i++;
				}
			}
		}
	}
	return (0);
}

