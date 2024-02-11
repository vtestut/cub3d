/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 21:14:06 by vtestut           #+#    #+#             */
/*   Updated: 2024/02/11 20:19:52 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	do_rotation(t_game *game, float rotspeed)
{
	t_player	*p;
	float		tmp_x;

	p = &game->player;
	tmp_x = p->dir_x;
	p->dir_x = p->dir_x * cos(rotspeed) - p->dir_y * sin(rotspeed);
	p->dir_y = tmp_x * sin(rotspeed) + p->dir_y * cos(rotspeed);
	tmp_x = p->plane_x;
	p->plane_x = p->plane_x * cos(rotspeed) - p->plane_y * sin(rotspeed);
	p->plane_y = tmp_x * sin(rotspeed) + p->plane_y * cos(rotspeed);
	return (1);
}

int	rotation(t_game *game, float rotdir)
{
	int		moved;
	float	rotspeed;

	moved = 0;
	rotspeed = ROTSPEED * rotdir;
	moved += do_rotation(game, rotspeed);
	return (moved);
}

bool	check_for_collision(t_game *game, float x, float y)
{
	if (game->map[(int)y][(int)x] == '0')
		return (true);
	return (false);
}

bool	is_valid_pos(t_game *game, float x, float y)
{
	if (check_for_collision(game, x, y))
		return (true);
	return (false);
}

int	is_valid_move(t_game *game, float new_x, float new_y)
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
