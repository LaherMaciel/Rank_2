/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mousecode.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 23:22:26 by lwencesl          #+#    #+#             */
/*   Updated: 2023/06/02 15:25:14 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	mouse_handler(int mousekey, int x, int y, t_win *win)
{
	ft_printf("mousekey -> %i\n", mousekey);
	ft_printf("x -> %i\ny -> %i\n", x, y);
	ft_printf("%s\n", win->mapa[0]);
	return (0);
}
