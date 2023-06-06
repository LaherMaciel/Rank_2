/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:19:36 by lwencesl          #+#    #+#             */
/*   Updated: 2023/06/06 23:15:04 by lwencesl         ###   ########.fr       */
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
	void	*img_wall;
	void	*img_floor;
	void	*img_exit;
	void	*img_player;
	void	*img_collectibles;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_win
{
	void	*mlx;
	void	*mlx_win;
	int		length_size;
	int		heigth_size;
	int		colors;
	char	**mapa;
	int		player;
	int		player_x;
	int		player_y;
	int		player_walk;
	int		player_look;
	int		walls;
	int		floor;
	int		collectibles;
	int		exit;
	int		image_length;
	int		image_heigth;
	int		i;
	int		j;
	int		x;
	int		y;
}		t_win;

//EVENTS
int		keycode_decisions(int keycode, t_win *win);
int		my_close(t_win *win);
void	mov_left(t_win *win);
void	mov_right(t_win *win);
void	mov_up(t_win *win);
void	mov_down(t_win *win);
int		mouse_handler(int mousekey, int x, int y, t_win *win);
int		window_destroy(t_win *win);

//CREAT_MAP
char	**creat_map(void);
char	**read_file(void);
int		map_base_check(t_win map);

//WINDOWS
char	**creat_map_mod(void);
t_win	window_init(t_win win);
t_data	create_image(t_win win, void *img_player);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

//IMAGE
void	*wall_image(t_win *win);
void	*player_image(t_win *win);
void	*floor_image(t_win *win);
void	*collectibles_image(t_win *win);
void	*exit_image(t_win *win);

//COLORS
t_data	color_win(t_data img, t_win *win, int x, int y);

//ANIMATIONS
void	*walk_up(t_win *win);
void	*walk_down(t_win *win);
void	*walk_left(t_win *win);
void	*walk_right(t_win *win);
void	*look_up(t_win *win);
void	*look_down(t_win *win);
void	*look_left(t_win *win);
void	*look_right(t_win *win);

#endif // !SO_LONG_H
