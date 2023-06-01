/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 18:12:35 by lwencesl          #+#    #+#             */
/*   Updated: 2023/05/31 17:56:39 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/*
Since each byte contains 2^8 = 256 values (1 byte = 8 bits),
and RGB values range from 0 to 255, we can perfectly fit a integer
(as an int is 4 bytes). In order to set the values programatically
we use bitshifting. Let’s create a function which does precisely
that for us, shall we?
*/

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

/*
Because ints are stored from right to left,
we need to bitshift each value the according
amount of bits backwards. We can also do the
exact opposite and retrieve integer values
from a encoded TRGB integer.
*/

int	get_t(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

int	get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}
