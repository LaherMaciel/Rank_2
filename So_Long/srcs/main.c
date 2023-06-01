/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:19:10 by lwencesl          #+#    #+#             */
/*   Updated: 2023/06/01 14:05:30 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	window_start(t_win win)
{
	t_map	map;
	t_data	img;
	int		i;

	//map.mapa = creat_map_mod();
	map.mapa = creat_map();
	if (map.mapa == NULL)
		return ;
	if (map_base_check(map) == 0)
	{
		ft_printf("ERROR\n");
		return ;
	}
	win = window_init(win);
	img = create_image(win, map);
	mlx_hook(win.mlx_win, 2, 1L<<0, close, &win);
	mlx_hook(win.mlx_win, 2, 1L<<1, close, &win);
	mlx_hook(win.mlx_win, 2, 1L<<2, close, &win);
	mlx_hook(win.mlx_win, 2, 1L<<3, close, &win);
	mlx_loop(win.mlx);
	ft_printf("img: %p\n", img);
	i = -1;
	while (map.mapa[++i])
		free(map.mapa[i]);
	free(map.mapa);
}

int	main(void)
{
	t_win	win;

	win.length_size = 1920;
	win.heigth_size = 1080;
	window_start(win);
	return (0);
}

/*
typedef struct s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	mlx_hook(vars.win, 2, 1L<<0, close, &vars);
	mlx_loop(vars.mlx);
}
*/
