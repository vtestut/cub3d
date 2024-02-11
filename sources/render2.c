/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:38:47 by vtestut           #+#    #+#             */
/*   Updated: 2024/02/11 18:24:28 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_image_pixel(t_img *image, int x, int y, int color)
{
	int	pixel;

	pixel = y * (image->size_line / 4) + x;
	image->addr[pixel] = color;
}

void	set_frame_image_pixel(t_game *game, t_img *image, int x, int y)
{
	if (game->pixels_tex[y][x] > 0)
		set_image_pixel(image, x, y, game->pixels_tex[y][x]);
	else if (y < game->win_h / 2)
		set_image_pixel(image, x, y, game->data.hex_ceiling);
	else if (y < game->win_h -1)
		set_image_pixel(image, x, y, game->data.hex_floor);
}
