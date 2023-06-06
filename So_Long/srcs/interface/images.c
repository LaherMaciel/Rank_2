/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 23:44:27 by lwencesl          #+#    #+#             */
/*   Updated: 2023/06/06 21:13:57 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
use this command to resize and convert a image 
in to the size and format u want
 $ convert input.jpeg -resize 64x64 output.xpm
*/

void	*wall_image(t_win *win)
{
	t_data	img;
	int		i;
	int		j;

	i = -1;
	img.img_wall = mlx_new_image(win->mlx, win->length_size, win->heigth_size);
	img.addr = mlx_get_data_addr(img.img_wall,
			&img.bits_per_pixel, &img.line_length, &img.endian);
	while (++i <= win->image_heigth)
	{
		j = -1;
		while (++j <= win->image_length)
		{
			if (i >= 53 && i <= 55)
				my_mlx_pixel_put(&img_wall, j, i, 0x00FFFFFF);
			else if ((i > 55) || (j < 4 && j > 61))
				my_mlx_pixel_put(&img_wall, j, i, 0x00000000);
			else
				my_mlx_pixel_put(&img_wall, j, i, 0x00808080);
		}
	}
	return (img_wall);
}

void	*player_image(t_win *win)
{
	void	*img_player;

	if (win->player_look == 0)
		img_player = look_up(win);
	else if (win->player_look == 1)
		img_player = look_down(win);
	else if (win->player_look == 2)
		img_player = look_left(win);
	else
		img_player = look_right(win);
	return (img_player);
}

void	*floor_image(t_win *win)
{
	void	*img_floor;

	img_floor = mlx_xpm_file_to_image(win->mlx, "main_floor.xpm", &win->image_length, &win->image_heigth);
	return (img_floor);
}

void	*collectibles_image(t_win *win)
{
	void	*img_collectibles;

	img_collectibles = mlx_xpm_file_to_image(win->mlx, "main_floor.xpm", &win->image_length, &win->image_heigth);
	return (img_collectibles);
}

void	*exit_image(t_win *win)
{
	void	*img_exit;

	img_exit = mlx_xpm_file_to_image(win->mlx, "main_floor.xpm", &win->image_length, &win->image_heigth);
	return (img_exit);
}
