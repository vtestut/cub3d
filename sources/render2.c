/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_render_02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:30:04 by vtestut           #+#    #+#             */
/*   Updated: 2024/02/10 23:34:52 by vtestut          ###   ########.fr       */
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
	if (game->texture_pixels[y][x] > 0)
		set_image_pixel(image, x, y, game->texture_pixels[y][x]);
	else if (y < game->win_height / 2)
		set_image_pixel(image, x, y, game->data.hex_ceiling);
	else if (y < game->win_height -1)
		set_image_pixel(image, x, y, game->data.hex_floor);
}