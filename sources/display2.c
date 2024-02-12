/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:38:47 by vtestut           #+#    #+#             */
/*   Updated: 2024/02/12 14:25:53 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	img_pxl_utils(t_img *image, int x, int y, int color)
{
	int	pxl;

	pxl = y * (image->line_size / 4) + x;
	image->addr[pxl] = color;
}

void	set_img_pxl(t_game *game, t_img *image, int x, int y)
{
	if (game->tex_pxl[y][x] > 0)
		img_pxl_utils(image, x, y, game->tex_pxl[y][x]);
	else if (y < game->win_h / 2)
		img_pxl_utils(image, x, y, game->tex.hexa_ceil);
	else if (y < game->win_h -1)
		img_pxl_utils(image, x, y, game->tex.hexa_floor);
}
