/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:30:04 by vtestut           #+#    #+#             */
/*   Updated: 2024/02/11 18:24:28 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_pixels_tex(t_game *game)
{
	int	i;

	if (game->pixels_tex)
		free_tab((void **)game->pixels_tex);
	game->pixels_tex = ft_calloc(game->win_h + 1,
			sizeof * game->pixels_tex);
	if (!game->pixels_tex)
		exit_free(game, err_msg("malloc error init_texture", 1));
	i = 0;
	while (i < game->win_h)
	{
		game->pixels_tex[i] = ft_calloc(game->win_w + 1,
				sizeof * game->pixels_tex);
		if (!game->pixels_tex[i])
			exit_free(game, err_msg("malloc error init_texture", 1));
		i++;
	}
}

void	init_img(t_game *game, t_img *image, int width, int height)
{
	init_img_clean(image);
	image->img = mlx_new_image(game->mlx, width, height);
	if (image->img == NULL)
		exit_free(game, err_msg("Could not create mlx image", 1));
	image->addr = (int *)mlx_get_data_addr(image->img, &image->pixel_bits,
			&image->size_line, &image->endian);
	return ;
}

void	render_frame(t_game *game)
{
	t_img	image;
	int		x;
	int		y;

	image.img = NULL;
	init_img(game, &image, game->win_w, game->win_h);
	y = 0;
	while (y < game->win_h)
	{
		x = 0;
		while (x < game->win_w)
		{
			set_frame_image_pixel(game, &image, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(game->mlx, game->win, image.img, 0, 0);
	mlx_destroy_image(game->mlx, image.img);
}

int	render(t_game *game)
{
	game->player.has_moved += move_player(game);
	if (game->player.has_moved == 0)
		return (0);
	render_images(game);
	return (0);
}
