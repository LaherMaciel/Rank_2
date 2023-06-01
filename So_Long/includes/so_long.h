/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:19:36 by lwencesl          #+#    #+#             */
/*   Updated: 2023/05/31 17:53:31 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdint.h>
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>
# include <fcntl.h>
# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"

typedef struct s_data{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_map
{
	char	**mapa;
	int		player;
	int		walls;
	int		floor;
	int		collectibles;
	int		exit;
	int		length;
	int		heigth;
	int		block_length;
	int		block_heigth;
	int		cont_length;
	int		cont_heigth;
}			t_map;

typedef struct s_win
{
	void	*mlx;
	void	*mlx_win;
	int		length_size;
	int		heigth_size;
	int		colors;
}		t_win;

//CREAT_MAP
char	**creat_map(void);
char	**read_file(void);
int		map_base_check(t_map map);

//WINDOWS
char	**creat_map_mod(void);
t_win	window_init(t_win win);
t_data	create_image(t_win win, t_map map);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

//COLORS
t_data	color_win(t_data img, t_map *map, int x, int y);

#endif // !SO_LONG_H