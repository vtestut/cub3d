/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 16:06:50 by vtestut           #+#    #+#             */
/*   Updated: 2024/02/12 14:28:13 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_player(t_player *player)
{
	player->dir = '\0';
	player->pos_x = 0.0;
	player->pos_y = 0.0;
	player->dir_x = 0.0;
	player->dir_y = 0.0;
	player->plan_x = 0.0;
	player->plan_y = 0.0;
	player->has_moved = 0;
	player->move_x = 0;
	player->move_y = 0;
	player->rotate = 0;
}

void	init_data(t_tex *tex)
{
	tex->north = NULL;
	tex->south = NULL;
	tex->west = NULL;
	tex->east = NULL;
	tex->size = SIZE;
	tex->floor = 0;
	tex->ceiling = 0;
	tex->hexa_floor = 0x0;
	tex->hexa_ceil = 0x0;
	tex->step = 0.0;
	tex->pos = 0.0;
	tex->x = 0;
	tex->y = 0;
}

void	init_game(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->map = NULL;
	game->path = NULL;
	game->file = NULL;
	game->tex_arr = NULL;
	game->tex_pxl = NULL;
	game->win_h = HEIGHT;
	game->win_w = WIDTH;
	game->fd = 0;
	game->nb_line = 0;
	game->height = 0;
	game->width = 0;
	game->map_end = 0;
}
