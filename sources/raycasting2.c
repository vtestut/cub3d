/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:28:23 by vtestut           #+#    #+#             */
/*   Updated: 2024/02/11 20:11:18 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_texture_idx(t_game *game, t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->dir_x < 0)
			game->data.index = WEST;
		else
			game->data.index = EAST;
	}
	else
	{
		if (ray->dir_y > 0)
			game->data.index = SOUTH;
		else
			game->data.index = NORTH;
	}
}

void	update_pixl_tex(t_game *game, t_data *tex, t_ray *ray, int x)
{
	int			y;
	int			color;

	get_texture_idx(game, ray);
	tex->x = (int)(ray->wall_x * tex->size);
	if ((ray->side == 0 && ray->dir_x < 0)
		|| (ray->side == 1 && ray->dir_y > 0))
		tex->x = tex->size - tex->x - 1;
	tex->step = 1.0 * tex->size / ray->line_height;
	tex->pos = (ray->draw_start - game->win_h / 2
			+ ray->line_height / 2) * tex->step;
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		tex->y = (int)tex->pos & (tex->size - 1);
		tex->pos += tex->step;
		color = game->tex_ar[tex->index][tex->size * tex->y + tex->x];
		if (tex->index == NORTH || tex->index == EAST)
			color = (color >> 1) & 8355711;
		if (color > 0)
			game->pixl_tex[y][x] = color;
		y++;
	}
}

void	find_line_height(t_ray *ray, t_game *game, t_player *player)
{
	if (ray->side == 0)
		ray->wall_dist = (ray->side_x - ray->delta_x);
	else
		ray->wall_dist = (ray->side_y - ray->delta_y);
	ray->line_height = (int)(game->win_h / ray->wall_dist);
	ray->draw_start = -(ray->line_height) / 2 + game->win_h / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + game->win_h / 2;
	if (ray->draw_end >= game->win_h)
		ray->draw_end = game->win_h - 1;
	if (ray->side == 0)
		ray->wall_x = player->pos_y + ray->wall_dist * ray->dir_y;
	else
		ray->wall_x = player->pos_x + ray->wall_dist * ray->dir_x;
	ray->wall_x -= floor(ray->wall_x); //It rounds a floating-point number down to the nearest integer that is less than or equal to the given value.
}
