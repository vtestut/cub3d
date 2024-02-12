/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:28:23 by vtestut           #+#    #+#             */
/*   Updated: 2024/02/12 16:18:32 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_texture_idx(t_game *game, t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->dir_x < 0)
			game->tex.index = WEST;
		else
			game->tex.index = EAST;
	}
	else
	{
		if (ray->dir_y > 0)
			game->tex.index = SOUTH;
		else
			game->tex.index = NORTH;
	}
}

/*	détermine la texture à appliquer sur chq pixel de la ligne pour un
	rayon donné, en fonction de l'intersection du rayon avec un mur */
void	set_texture_pxl(t_game *game, t_tex *tex, t_ray *ray, int x)
{
	int			y;
	int			color;

	get_texture_idx(game, ray);
	tex->x = (int)(ray->wall_x * tex->size);
	if ((ray->side == 0 && ray->dir_x < 0)
		|| (ray->side == 1 && ray->dir_y > 0))
		tex->x = tex->size - tex->x - 1;
	tex->step = 1.0 * tex->size / ray->line_h;
	tex->pos = (ray->draw_start - game->win_h
			/ 2 + ray->line_h / 2) * tex->step;
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		tex->y = (int)tex->pos & (tex->size - 1);
		tex->pos += tex->step;
		color = game->tex_arr[tex->index][tex->size * tex->y + tex->x];
		if (tex->index == NORTH || tex->index == EAST)
			color = (color >> 1) & 8355711;
		if (color > 0)
			game->tex_pxl[y][x] = color;
		y++;
	}
}

// détermine la hauteur de la ligne à display pour ce rayon.
void	find_line_height(t_ray *ray, t_game *game, t_player *player)
{
	if (ray->side == 0)
		ray->wall_dist = (ray->side_x - ray->delta_x);
	else
		ray->wall_dist = (ray->side_y - ray->delta_y);
	ray->line_h = (int)(game->win_h / ray->wall_dist);
	ray->draw_start = -(ray->line_h) / 2 + game->win_h / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_h / 2 + game->win_h / 2;
	if (ray->draw_end >= game->win_h)
		ray->draw_end = game->win_h - 1;
	if (ray->side == 0)
		ray->wall_x = player->pos_y + ray->wall_dist * ray->dir_y;
	else
		ray->wall_x = player->pos_x + ray->wall_dist * ray->dir_x;
	ray->wall_x -= floor(ray->wall_x);
}
