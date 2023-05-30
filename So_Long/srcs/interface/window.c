/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 18:46:12 by lwencesl          #+#    #+#             */
/*   Updated: 2023/05/31 00:25:53 by lwencesl         ###   ########.fr       */
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

t_win	window_init(void)
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

/*
void	paint_wind(t_win win, t_data img)
{
	int	i;
	int	j;
	int	k;
	int	l;

	i = -1;
	k = 1280 /2;
	l = 720 / 2;
	while (++i < 1920)
	{
		j = -1;
		while (++j < 1080)
			if (((i > k - 40) && j > (l - 22)) && (i < (k + 40) && j < (l + 22)))
				my_mlx_pixel_put(&img, i, j, 0x00000000);
			else if (((i > k - 80) && j > (l - 45)) && (i < (k + 80) && j < (l + 45)))
				my_mlx_pixel_put(&img, i, j, 0x000000AA);
			else if (((i > k - 160) && j > (l - 90)) && (i < (k + 160) && j < (l + 90)))
				my_mlx_pixel_put(&img, i, j, 0x000000BB);
			else if (((i > k - 240) && j > (l - 135)) && (i < (k + 240) && j < (l + 135)))
				my_mlx_pixel_put(&img, i, j, 0x000000CC);
			else if (((i > k - 360) && j > (l - 180)) && (i < (k + 360) && j < (l + 180)))
				my_mlx_pixel_put(&img, i, j, 0x000000DD);
			else if (((i > k - 400) && j > (l - 225)) && (i < (k + 400) && j < (l + 225)))
				my_mlx_pixel_put(&img, i, j, 0x000000EE);
			else if (((i > k - 480) && j > (l - 270)) && (i < (k + 480) && j < (l + 270)))
				my_mlx_pixel_put(&img, i, j, 0x000000FF);
			else if (((i > k - 560) && j > (l - 315)) && (i < (k + 560) && j < (l + 315)))
				my_mlx_pixel_put(&img, i, j, 0x0000DDDD);
			else if (((i > k - 640) && j > (l - 360)) && (i < (k + 640) && j < (l + 360)))
				my_mlx_pixel_put(&img, i, j, 0x00CCCCFF);
			else if (((i > k - 720) && j > (l - 405)) && (i < (k + 720) && j < (l + 405)))
				my_mlx_pixel_put(&img, i, j, 0x00DDDDFF);
	}
	mlx_put_image_to_window(win.mlx, win.mlx_win, img.img, 0, 0);
}
*/

t_data	color_win(t_data img, char **map, int i, int j, int x, int y)
{
	if (map[i][j] == '1')
		my_mlx_pixel_put(&img, x, y, 0x00005AFF);
	else if (map[i][j] == '0')
		my_mlx_pixel_put(&img, x, y, 0x00DDDDFF);
	else if (map[i][j] == 'p')
		my_mlx_pixel_put(&img, x, y, 0x0000FF00);
	else if (map[i][j] == 'c')
		my_mlx_pixel_put(&img, x, y, 0x00DDCC5F);
	else if (map[i][j] == 'e')
		my_mlx_pixel_put(&img, x, y, 0x00FF0000);
	return (img);
}

t_data	pain_block(int length, int heigth, t_data img, char **map)
{
	int	x;
	int	y;
	int	lgen;
	int	hegn;
	int	block_length;
	int	block_heigth;
	int	cont_length;
	int	cont_heigth;
	int	a;

	a = 0;
	block_length = 1280 / length;
	if (1080 % length >= 5)
		block_length++;
	block_heigth = 720 / heigth;
	if (720 % heigth >= 5)
		block_heigth++;
	lgen = block_length;
	hegn = block_heigth;	
	ft_printf("length->%i\nheigth->%i\n", length, heigth);
	ft_printf("block_length->%i\nblock_heigth->%i\n", block_length, block_heigth);
	y = -1;
	cont_heigth = 0;
	while (++y < 1080 && cont_heigth < heigth)
	{
		x = -1;
		cont_length = 0;
		block_length = 1280 / length;
		if (1080 % length >= 5 && a == 0)
		{
			block_length++;
			a = 1;
		}
		if (1080 % length >= 5 && a == 1)
			a = 0;
		while (++x < 1920 && cont_length < length)
		{
			color_win(img, map, cont_heigth, cont_length, x, y);
			if (x >= block_length)
			{
				block_length += lgen;
				cont_length++;
				ft_printf("x = %i, y = %i\n", x, y);
			}
			if (y >= block_heigth)
			{
				block_heigth += hegn;
				cont_heigth++;
				ft_printf("cont_length -> %i\ncont_heigth -> %i\n", cont_length, cont_heigth);
				ft_printf("x = %i, y = %i\n", x, y);
			}
			if (cont_heigth >= heigth)
				break ;
		}
	}
	ft_printf("length->%i\nheigth->%i\n", length, heigth);
	ft_printf("block_length->%i\nblock_heigth->%i\n", lgen, hegn);
	ft_printf("x = %i, y = %i\n", x, y);
	return (img);
}

t_data	paint_wind(t_win *win, t_data img, char **map)
{
	int	length;
	int	heigth;

	length = ft_strlen(map[0]); // fazer uma função para remover o \n que o get_next_line retorna...
	heigth = 0;
	while (map[heigth])
		heigth++;
	img = pain_block(length, heigth, img, map);
	mlx_put_image_to_window(win->mlx, win->mlx_win, img.img, 0, 0);
	return (img);
}

t_data	create_image(t_win win, char **map)
{
	t_data	img;

	img.img = mlx_new_image(win.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img,
			&img.bits_per_pixel, &img.line_length, &img.endian);
	img = paint_wind(&win, img, map);
	ft_printf("IMAGE CREATED\n");
	return (img);
}

/*
	ft_printf("%c\n", map[0][0]);
	j = -1;
	while (++j < 1080)
	{
		i = -1;
		while (++i < 1920)
		{
			if (i < 160 && j < 90)
				my_mlx_pixel_put(&img, i, j, 0x000000AA);
			else if (i < 320 && j < 180)
				my_mlx_pixel_put(&img, i, j, 0x000000BB);
			else if (i < 480 && j < 270)
				my_mlx_pixel_put(&img, i, j, 0x000000CC);
			else if (i < 640 && j < 360)
				my_mlx_pixel_put(&img, i, j, 0x000000DD);
			else if (i < 800 && j < 450)
				my_mlx_pixel_put(&img, i, j, 0x000000EE);
			else if (i < 960 && j < 540)
				my_mlx_pixel_put(&img, i, j, 0x000000FF);
			else if (i < 1120 && j < 630)
				my_mlx_pixel_put(&img, i, j, 0x0000DDDD);
			else if (i < 1280 && j < 720)
				my_mlx_pixel_put(&img, i, j, 0x00DDDDFF);
		}
	}
	mlx_put_image_to_window(win.mlx, win.mlx_win, img.img, 0, 0);

	while (++i < 1920)
	{
		j = -1;
		while (++j < 1080)
		{
			if (((i > k - 80) && j > (l - 45)) && (i < (k + 80) && j < (l + 45)))
				my_mlx_pixel_put(&img, i, j, 0x00000000);
			else if (((i > k - 160) && j > (l - 90)) && (i < (k + 160) && j < (l + 90)))
				my_mlx_pixel_put(&img, i, j, 0x000000AA);
			else if (((i > k - 240) && j > (l - 135)) && (i < (k + 240) && j < (l + 135)))
				my_mlx_pixel_put(&img, i, j, 0x000000BB);
			else if (((i > k - 360) && j > (l - 180)) && (i < (k + 360) && j < (l + 180)))
				my_mlx_pixel_put(&img, i, j, 0x000000CC);
			else if (((i > k - 400) && j > (l - 225)) && (i < (k + 400) && j < (l + 225)))
				my_mlx_pixel_put(&img, i, j, 0x000000DD);
			else if (((i > k - 480) && j > (l - 270)) && (i < (k + 480) && j < (l + 270)))
				my_mlx_pixel_put(&img, i, j, 0x000000EE);
			else if (((i > k - 560) && j > (l - 315)) && (i < (k + 560) && j < (l + 315)))
				my_mlx_pixel_put(&img, i, j, 0x000000FF);
			else if (((i > k - 640) && j > (l - 360)) && (i < (k + 640) && j < (l + 360)))
				my_mlx_pixel_put(&img, i, j, 0x0000DDDD);
			else if (((i > k - 720) && j > (l - 405)) && (i < (k + 720) && j < (l + 405)))
				my_mlx_pixel_put(&img, i, j, 0x00DDDDFF);
		}
	}

	// SQUAR
	while (++i < 1920)
	{
		j = -1;
		while (++j < 1080)
		{
			if (((i < k - 560) || j < (l - 315)) || (i > (k + 560) || j > (l + 315)))
				my_mlx_pixel_put(&img, i, j, 0x00DDDDFF);
		}
	}

	// top left and bottom right
	while (++i < 1920)
	{
		j = -1;
		while (++j < 1080)
		{
			if (((i < k - 560) || j < (l - 315)) || (i > (k + 560) || j > (l + 315)))
				my_mlx_pixel_put(&img, i, j, 0x00DDDDFF);
		}
	}

	// top right and bottom left
	while (++i < 1920)
	{
		j = -1;
		while (++j < 1080)
		{
			if (((i < k - 560) || j < (l - 315)) && (i > (k + 560) || j > (l + 315)))
				my_mlx_pixel_put(&img, i, j, 0x00DDDDFF);
		}
	}

	while (++i < 1920)
	{
		j = -1;
		while (++j < 1080)
		{
			if (((i > k - 80) || j > (l - 45)) && (i < (k + 80) || j < (l + 45)))
				my_mlx_pixel_put(&img, i, j, 0x00000000);
			else if (((i > k - 160) || j > (l - 90)) && (i < (k + 160) || j < (l + 90)))
				my_mlx_pixel_put(&img, i, j, 0x000000AA);
			else if (((i > k - 240) || j > (l - 135)) && (i < (k + 240) || j < (l + 135)))
				my_mlx_pixel_put(&img, i, j, 0x000000BB);
			else if (((i > k - 360) || j > (l - 180)) && (i < (k + 360) || j < (l + 180)))
				my_mlx_pixel_put(&img, i, j, 0x000000CC);
			else if (((i > k - 400) || j > (l - 225)) && (i < (k + 400) || j < (l + 225)))
				my_mlx_pixel_put(&img, i, j, 0x000000DD);
			else if (((i > k - 480) || j > (l - 270)) && (i < (k + 480) || j < (l + 270)))
				my_mlx_pixel_put(&img, i, j, 0x000000EE);
			else if (((i > k - 560) || j > (l - 315)) && (i < (k + 560) || j < (l + 315)))
				my_mlx_pixel_put(&img, i, j, 0x000000FF);
			else if (((i > k - 640) || j > (l - 360)) && (i < (k + 640) || j < (l + 360)))
				my_mlx_pixel_put(&img, i, j, 0x0000DDDD);
			else if (((i > k - 720) || j > (l - 405)) && (i < (k + 720) || j < (l + 405)))
				my_mlx_pixel_put(&img, i, j, 0x00DDDDFF);
		}
	}

	while (++i < 1920)
	{
		j = -1;
		while (++j < 1080)
		{
			if (((i > k - 80) && j > (l - 45)) || (i < (k + 80) && j < (l + 45)))
				my_mlx_pixel_put(&img, i, j, 0x00000000);
			else if (((i > k - 160) && j > (l - 90)) || (i < (k + 160) && j < (l + 90)))
				my_mlx_pixel_put(&img, i, j, 0x000000AA);
			else if (((i > k - 240) && j > (l - 135)) || (i < (k + 240) && j < (l + 135)))
				my_mlx_pixel_put(&img, i, j, 0x000000BB);
			else if (((i > k - 360) && j > (l - 180)) || (i < (k + 360) && j < (l + 180)))
				my_mlx_pixel_put(&img, i, j, 0x000000CC);
			else if (((i > k - 400) && j > (l - 225)) || (i < (k + 400) && j < (l + 225)))
				my_mlx_pixel_put(&img, i, j, 0x000000DD);
			else if (((i > k - 480) && j > (l - 270)) || (i < (k + 480) && j < (l + 270)))
				my_mlx_pixel_put(&img, i, j, 0x000000EE);
			else if (((i > k - 560) && j > (l - 315)) || (i < (k + 560) && j < (l + 315)))
				my_mlx_pixel_put(&img, i, j, 0x000000FF);
			else if (((i > k - 640) && j > (l - 360)) || (i < (k + 640) && j < (l + 360)))
				my_mlx_pixel_put(&img, i, j, 0x0000DDDD);
			else if (((i > k - 720) && j > (l - 405)) || (i < (k + 720) && j < (l + 405)))
				my_mlx_pixel_put(&img, i, j, 0x00DDDDFF);
		}
	}
*/
