/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 18:46:12 by lwencesl          #+#    #+#             */
/*   Updated: 2023/05/27 19:38:44 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/*=============================================
include the 'mlx.h' on ur '.h' file
mlx_init() -> used to inicialize the library. It returns a (void *)
mlx_new_window(pointer_returned_by_mlx_init(),
	width, heigth, "the_name_of_the_window") -> return the (void *) to the new window created.  
mlx_new_image() ->
mlx_loop() -> initiate the window rendering.
==============================================*/

int	window_start(void)
{
	void	*mlx;
	void	*mlx_win;
	//void	*img;

	mlx = mlx_init();
	//img = mlx_new_image(mlx, 1920, 1080);
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world");
	mlx_loop(mlx);
	ft_printf("mlx_win: %p\n", mlx_win);
	//ft_printf("img: %p\n", img);
	ft_printf("IT'S WORKING\n");
	return (0);
}
