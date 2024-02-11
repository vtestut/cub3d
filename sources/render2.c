/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:38:47 by vtestut           #+#    #+#             */
/*   Updated: 2024/02/11 20:25:59 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	img_pixl_utils(t_img *image, int x, int y, int color)
{
	int	pixel;

	pixel = y * (image->size_line / 4) + x;
	image->addr[pixel] = color;
}

void	set_img_pixl(t_game *game, t_img *image, int x, int y)
{
	if (game->pixl_tex[y][x] > 0)
		img_pixl_utils(image, x, y, game->pixl_tex[y][x]);
	else if (y < game->win_h / 2)
		img_pixl_utils(image, x, y, game->data.hex_ceil);
	else if (y < game->win_h -1)
		img_pixl_utils(image, x, y, game->data.hex_floor);
}
