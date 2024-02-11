/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 21:13:24 by vtestut           #+#    #+#             */
/*   Updated: 2024/02/11 19:56:29 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	move_front(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos_x + game->player.dir_x * SPEED;
	new_y = game->player.pos_y + game->player.dir_y * SPEED;
	return (is_valid_move(game, new_x, new_y));
}

int	move_back(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos_x - game->player.dir_x * SPEED;
	new_y = game->player.pos_y - game->player.dir_y * SPEED;
	return (is_valid_move(game, new_x, new_y));
}

int	move_left(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos_x + game->player.dir_y * SPEED;
	new_y = game->player.pos_y - game->player.dir_x * SPEED;
	return (is_valid_move(game, new_x, new_y));
}

int	move_right(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos_x - game->player.dir_y * SPEED;
	new_y = game->player.pos_y + game->player.dir_x * SPEED;
	return (is_valid_move(game, new_x, new_y));
}

int	move_player(t_game *game)
{
	int	moved;

	moved = 0;
	if (game->player.move_y == 1)
		moved += move_front(game);
	if (game->player.move_y == -1)
		moved += move_back(game);
	if (game->player.move_x == -1)
		moved += move_left(game);
	if (game->player.move_x == 1)
		moved += move_right(game);
	if (game->player.rotate != 0)
		moved += rotation(game, game->player.rotate);
	return (moved);
}
