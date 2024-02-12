/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catch_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 20:14:43 by vtestut           #+#    #+#             */
/*   Updated: 2024/02/12 14:26:13 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_press(int key, t_game *game)
{
	if (key == XK_Escape)
		exit_mlx(game);
	if (key == XK_Left)
		game->player.rotate -= 1;
	if (key == XK_Right)
		game->player.rotate += 1;
	if (key == XK_w)
		game->player.move_y = 1;
	if (key == XK_a)
		game->player.move_x = -1;
	if (key == XK_s)
		game->player.move_y = -1;
	if (key == XK_d)
		game->player.move_x = 1;
	return (0);
}

int	key_release(int key, t_game *game)
{
	if (key == XK_Escape)
		exit_mlx(game);
	if (key == XK_w && game->player.move_y == 1)
		game->player.move_y = 0;
	if (key == XK_s && game->player.move_y == -1)
		game->player.move_y = 0;
	if (key == XK_a && game->player.move_x == -1)
		game->player.move_x += 1;
	if (key == XK_d && game->player.move_x == 1)
		game->player.move_x -= 1;
	if (key == XK_Left && game->player.rotate <= 1)
		game->player.rotate = 0;
	if (key == XK_Right && game->player.rotate >= -1)
		game->player.rotate = 0;
	return (0);
}
