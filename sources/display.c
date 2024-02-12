/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:30:04 by vtestut           #+#    #+#             */
/*   Updated: 2024/02/12 14:26:49 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_pxl(t_game *game)
{
	int	i;

	if (game->tex_pxl)
		ft_free_tab((void **)game->tex_pxl);
	game->tex_pxl = ft_calloc(game->win_h + 1,
			sizeof * game->tex_pxl);
	if (!game->tex_pxl)
		exit_free(game, msg_error("malloc failed", 1));
	i = 0;
	while (i < game->win_h)
	{
		game->tex_pxl[i] = ft_calloc(game->win_w + 1,
				sizeof * game->tex_pxl);
		if (!game->tex_pxl[i])
			exit_free(game, msg_error("malloc failed", 1));
		i++;
	}
}

void	create_image(t_game *game, t_img *image, int width, int height)
{
	init_img(image);
	image->img = mlx_new_image(game->mlx, width, height);
	if (image->img == NULL)
		exit_free(game, msg_error("mlx_new_image failed", 1));
	image->addr = (int *)mlx_get_data_addr(image->img, &image->pxl_bit,
			&image->line_size, &image->endian);
	return ;
}

void	display_window(t_game *game)
{
	t_img	image;
	int		x;
	int		y;

	image.img = NULL;
	create_image(game, &image, game->win_w, game->win_h);
	y = 0;
	while (y < game->win_h)
	{
		x = 0;
		while (x < game->win_w)
		{
			set_img_pxl(game, &image, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(game->mlx, game->win, image.img, 0, 0);
	mlx_destroy_image(game->mlx, image.img);
}

int	display_loop(t_game *game)
{
	game->player.has_moved += move_player(game);
	if (game->player.has_moved == 0)
		return (0);
	display_game(game);
	return (0);
}
