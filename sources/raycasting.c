/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 15:40:40 by vtestut           #+#    #+#             */
/*   Updated: 2024/02/12 16:21:06 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_ray(t_ray *ray)
{
	ray->camera_x = 0;
	ray->dir_x = 0;
	ray->dir_y = 0;
	ray->map_x = 0;
	ray->map_y = 0;
	ray->step_x = 0;
	ray->step_y = 0;
	ray->side_x = 0;
	ray->side_y = 0;
	ray->delta_x = 0;
	ray->delta_y = 0;
	ray->wall_dist = 0;
	ray->wall_x = 0;
	ray->side = 0;
	ray->line_h = 0;
	ray->draw_start = 0;
	ray->draw_end = 0;
}

void	set_raycasting(int x, t_ray *ray, t_player *player)
{
	init_ray(ray);
	ray->camera_x = 2 * x / (float)WIDTH - 1;
	ray->dir_x = player->dir_x + player->plan_x * ray->camera_x;
	ray->dir_y = player->dir_y + player->plan_y * ray->camera_x;
	ray->map_x = (int)player->pos_x;
	ray->map_y = (int)player->pos_y;
	ray->delta_x = fabs(1 / ray->dir_x);
	ray->delta_y = fabs(1 / ray->dir_y);
}

void	set_dda(t_ray *ray, t_player *player)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_x = (player->pos_x - ray->map_x) * ray->delta_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_x = (ray->map_x + 1.0 - player->pos_x) * ray->delta_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_y = (player->pos_y - ray->map_y) * ray->delta_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_y = (ray->map_y + 1.0 - player->pos_y) * ray->delta_y;
	}
}

void	perform_dda(t_game *game, t_ray *ray)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (ray->side_x < ray->side_y)
		{
			ray->side_x += ray->delta_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_y += ray->delta_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (ray->map_y < 0.25
			|| ray->map_x < 0.25
			|| ray->map_y > game->height - 0.25
			|| ray->map_x > game->width - 1.25)
			break ;
		else if (game->map[ray->map_y][ray->map_x] > '0')
			hit = 1;
	}
}

int	raycasting(t_player *player, t_game *game)
{
	t_ray	ray;
	int		x;

	x = 0;
	ray = game->ray;
	while (x < game->win_w)
	{
		set_raycasting(x, &ray, player);
		set_dda(&ray, player);
		perform_dda(game, &ray);
		find_line_height(&ray, game, player);
		set_texture_pxl(game, &game->tex, &ray, x);
		x++;
	}
	return (0);
}
