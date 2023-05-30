/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:19:10 by lwencesl          #+#    #+#             */
/*   Updated: 2023/05/31 00:07:47 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	window_start(char **map)
{
	t_win	win;
	t_data	img;

	win = window_init();
	img = create_image(win, map);
	mlx_loop(win.mlx);
	ft_printf("img: %p\n", img);
}

int	main(void)
{
	char	**map;
	int		i;

	//map = creat_map_mod();
	map = creat_map();
	if (map == NULL)
		return (0);
	if (map_base_check(map) == 0)
	{
		ft_printf("ERROR\n");
		return (0);
	}
	window_start(map);
	i = 0;
	while (map[++i])
		free(map[i]);
	free(map);
	return (0);
}
