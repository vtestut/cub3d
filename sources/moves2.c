/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:57:06 by vtestut          #+#    #+#             */
/*   Updated: 2024/01/09 13:49:34 by vtestut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	rotate_left_right(t_game *game, double rotspeed)
{
	t_player	*p;
	double		tmp_x;

	p = &game->player;
	tmp_x = p->dir_x;
	p->dir_x = p->dir_x * cos(rotspeed) - p->dir_y * sin(rotspeed);
	p->dir_y = tmp_x * sin(rotspeed) + p->dir_y * cos(rotspeed);
	tmp_x = p->plane_x;
	p->plane_x = p->plane_x * cos(rotspeed) - p->plane_y * sin(rotspeed);
	p->plane_y = tmp_x * sin(rotspeed) + p->plane_y * cos(rotspeed);
	return (1);
}

int	rotate_player(t_game *game, double rotdir)
{
	int		moved;
	double	rotspeed;

	moved = 0;
	rotspeed = ROTSPEED * rotdir;
	moved += rotate_left_right(game, rotspeed);
	return (moved);
}

bool	is_valid_pos_wall_collision(t_game *game, double x, double y)
{
	if (game->map[(int)y][(int)x] == '0')
		return (true);
	return (false);
}

// static bool	is_valid_pos_in_map(t_game *game, double x, double y)
// {
// 	if (x < 0.25 || x >= game->width - 1.25)
// 		return (false);
// 	if (y < 0.25 || y >= game->height -0.25)
// 		return (false);
// 	return (true);
// }

bool	is_valid_pos(t_game *game, double x, double y)
{
	// if (!BONUS && is_valid_pos_in_map(game, x, y))
	// 	return (true);
	// if (BONUS && is_valid_pos_wall_collision(game, x, y))
	// 	return (true);
	// return (false);
	// if (!BONUS && is_valid_pos_in_map(game, x, y))
	// 	return (true);
	if (is_valid_pos_wall_collision(game, x, y))
		return (true);
	return (false);
}

int	validate_move(t_game *game, double new_x, double new_y)
{
	int	moved;

	moved = 0;
	if (is_valid_pos(game, new_x, game->player.pos_y))
	{
		game->player.pos_x = new_x;
		moved = 1;
	}
	if (is_valid_pos(game, game->player.pos_x, new_y))
	{
		game->player.pos_y = new_y;
		moved = 1;
	}
	return (moved);
}
