/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:19:36 by lwencesl          #+#    #+#             */
/*   Updated: 2023/05/31 15:11:07 by lwencesl         ###   ########.fr       */
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
	int		colors;
}		t_win;

char	**creat_map(void);
char	**read_file(void);
int		map_base_check(t_map map);

//WINDOWS
char	**creat_map_mod(void);
t_win	window_init(void);
t_data	create_image(t_win win, t_map map);

#endif // !SO_LONG_H