/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_animations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:26:48 by lwencesl          #+#    #+#             */
/*   Updated: 2023/06/06 18:29:22 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
	HERE WILL DEAL WITH THE PLAYER ANIMATIONS LIKE WALKING
*/

t_data	*look_up(t_win *win)
{
	t_data	img;

	img = mlx_xpm_file_to_image(mlx, "path", win->image_length, win->image_heigth);
	return (img);
}

t_data	*look_down(t_win win, t_data img)
{
	
}

t_data	*look_left(t_win win, t_data img)
{
	
}

t_data	*look_rigth(t_win win, t_data img)
{
	
}

