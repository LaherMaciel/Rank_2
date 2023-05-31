/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:19:10 by lwencesl          #+#    #+#             */
/*   Updated: 2023/05/31 15:25:08 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	window_start(void)
{
	t_win	win;
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
	win = window_init();
	img = create_image(win, map);
	mlx_loop(win.mlx);
	ft_printf("img: %p\n", img);
	i = -1;
	while (map.mapa[++i])
		free(map.mapa[i]);
	free(map.mapa);
}

int	main(void)
{
	window_start();
	return (0);
}
