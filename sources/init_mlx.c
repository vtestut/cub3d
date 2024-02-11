/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 14:53:13 by vtestut           #+#    #+#             */
/*   Updated: 2024/02/11 19:42:55 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_clean_img(t_img *img)
{
	img->img = NULL;
	img->addr = NULL;
	img->pixl_bit = 0;
	img->size_line = 0;
	img->endian = 0;
}

void	init_texture_img(t_game *game, t_img *image, char *path)
{
	set_clean_img(image);
	image->img = mlx_xpm_file_to_image(game->mlx, path, &game->data.size,
			&game->data.size);
	if (image->img == NULL)
		exit_free(game, msg_error("Could not create mlx image", 1));
	image->addr = (int *)mlx_get_data_addr(image->img, &image->pixl_bit,
			&image->size_line, &image->endian);
	return ;
}

int	*xpm_to_img(t_game *game, char *path)
{
	t_img	tmp;
	int		*buffer;
	int		x;
	int		y;

	init_texture_img(game, &tmp, path);
	buffer = ft_calloc(1,
			sizeof * buffer * game->data.size * game->data.size);
	if (!buffer)
		exit_free(game, msg_error("malloc error xpm_to_img", 1));
	y = 0;
	while (y < game->data.size)
	{
		x = 0;
		while (x < game->data.size)
		{
			buffer[y * game->data.size + x]
				= tmp.addr[y * game->data.size + x];
			++x;
		}
		y++;
	}
	mlx_destroy_image(game->mlx, tmp.img);
	return (buffer);
}
