/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 21:13:24 by vtestut           #+#    #+#             */
/*   Updated: 2024/02/11 18:15:01 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	move_player_forward(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos_x + game->player.dir_x * SPEED;
	new_y = game->player.pos_y + game->player.dir_y * SPEED;
	return (validate_move(game, new_x, new_y));
}

int	move_player_backward(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos_x - game->player.dir_x * SPEED;
	new_y = game->player.pos_y - game->player.dir_y * SPEED;
	return (validate_move(game, new_x, new_y));
}

int	move_player_left(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos_x + game->player.dir_y * SPEED;
	new_y = game->player.pos_y - game->player.dir_x * SPEED;
	return (validate_move(game, new_x, new_y));
}

int	move_player_right(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos_x - game->player.dir_y * SPEED;
	new_y = game->player.pos_y + game->player.dir_x * SPEED;
	return (validate_move(game, new_x, new_y));
}

int	move_player(t_game *game)
{
	int	moved;

	moved = 0;
	if (game->player.move_y == 1)
		moved += move_player_forward(game);
	if (game->player.move_y == -1)
		moved += move_player_backward(game);
	if (game->player.move_x == -1)
		moved += move_player_left(game);
	if (game->player.move_x == 1)
		moved += move_player_right(game);
	if (game->player.rotate != 0)
		moved += rotate_player(game, game->player.rotate);
	return (moved);
}
