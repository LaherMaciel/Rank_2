/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 23:36:13 by lwencesl          #+#    #+#             */
/*   Updated: 2023/06/06 16:15:23 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*=============================================
include the 'mlx.h' on your '.h' project file
mlx_init() -> used to inicialize the library. It returns a (void *)
mlx_new_window(pointer_returned_by_mlx_init(),
	width, heigth, "the_name_of_the_window") -> used to initialize a window.
	return the (void *) to the new window created.  
mlx_new_image() -> 
mlx_loop() -> initiate the window rendering.
==============================================*/

t_win	window_init(t_win win)
{
	win.mlx = mlx_init();
	win.mlx_win = mlx_new_window(win.mlx, win.length_size, win.heigth_size, "Hello world");
	ft_printf("WINDOOW CREATED\n");
	return (win);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

/*
t_data	paint_wind(t_win *win, t_data img)
{
	
}
*/

t_data	create_image(t_win win)
{
	t_data	img;

	img.img = mlx_new_image(win.mlx, win.length_size, win.heigth_size);
	img.addr = mlx_get_data_addr(img.img,
			&img.bits_per_pixel, &img.line_length, &img.endian);
	my_mlx_pixel_put(&img, 32, 32, 0x00FF0000);
	mlx_put_image_to_window(win.mlx, win.mlx_win, img.img, 0, 0);
	ft_printf("IMAGE CREATED\n");
	return (img);
}

void	destroy_map(t_win *win)
{
	int	i;

	i = 0;
	while (win->mapa[i])
	{
		free(win->mapa[i]);
		i++;
	}
	free(win->mapa);
}

int	window_destroy(t_win *win)
{
	mlx_destroy_window(win->mlx, win->mlx_win);
	mlx_destroy_display(win->mlx);
	destroy_map(win);
	free(win->mlx);
	exit(0);
}
