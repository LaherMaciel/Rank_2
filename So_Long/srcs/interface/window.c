/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 18:46:12 by lwencesl          #+#    #+#             */
/*   Updated: 2023/05/28 17:49:56 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/*=============================================
include the 'mlx.h' on your '.h' project file
mlx_init() -> used to inicialize the library. It returns a (void *)
mlx_new_window(pointer_returned_by_mlx_init(),
	width, heigth, "the_name_of_the_window") -> used to initialize a window.
	return the (void *) to the new window created.  
mlx_new_image() -> 
mlx_loop() -> initiate the window rendering.
==============================================*/

t_win	window_start(void)
{
	t_win	win;

	win.mlx = mlx_init();
	win.mlx_win = mlx_new_window(win.mlx, 1280, 720, "Hello world");
	ft_printf("WINDOOW CREATED\n");
	return (win);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

t_data	create_image(t_win win)
{
	t_data	img;

	img.img = mlx_new_image(win.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img,
			&img.bits_per_pixel, &img.line_length, &img.endian);
	my_mlx_pixel_put(&img, 620, 350, 0x00FFFFFF);
	mlx_put_image_to_window(win.mlx, win.mlx_win, img.img, 0, 0);
	ft_printf("IMAGE CREATED\n");
	return (img);
}
