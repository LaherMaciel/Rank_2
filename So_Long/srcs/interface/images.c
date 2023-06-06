/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 23:44:27 by lwencesl          #+#    #+#             */
/*   Updated: 2023/06/06 18:16:18 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
use this command to resize and convert a image 
in to the size and format u want
 $ convert input.jpeg -resize 64x64 output.xpm
*/

t_data	wall_image(t_win *win, t_data img)
{
	int	i;
	int	j;

	i = -1;
	while (++i <= win->image_heigth)
	{
		j = -1;
		while (++j <= win->image_length)
		{
			if (i >= 53 && i <= 55)
				my_mlx_pixel_put(&img, j, i, 0x00FFFFFF);
			else if ((i > 55) || (j < 4 && j > 61))
				my_mlx_pixel_put(&img, j, i, 0x00000000);
			else
				my_mlx_pixel_put(&img, j, i, 0x00808080);
		}
	}
	return (img);
}

t_data	floor_image(t_win *win, t_data img)
{
	return (img);
}

t_data	player_image(t_win *win, t_data img)
{
	return (img);
}

t_data	collectibles_image(t_win *win, t_data img)
{
	return (img);
}

t_data	exit_image(t_win *win, t_data img)
{
	return (img);
}
