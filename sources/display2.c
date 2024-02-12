/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:38:47 by vtestut           #+#    #+#             */
/*   Updated: 2024/02/12 15:51:33 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	img_pxl_utils(t_img *image, int x, int y, int color)
{
	int	pxl;

	pxl = y * (image->line_size / 4) + x;
	image->addr[pxl] = color;
}

void	set_img_pxl(t_game *game, t_img *image, int x, int y)
{
	if (game->tex_pxl[y][x] > 0)
		img_pxl_utils(image, x, y, game->tex_pxl[y][x]);
	else if (y < game->win_h / 2)
		img_pxl_utils(image, x, y, game->tex.hexa_ceil);
	else if (y < game->win_h -1)
		img_pxl_utils(image, x, y, game->tex.hexa_floor);
}

void	init_img(t_img *img)
{
	img->img = NULL;
	img->addr = NULL;
	img->pxl_bit = 0;
	img->line_size = 0;
	img->endian = 0;
}

void	create_texture(t_game *game, t_img *img, char *path)
{
	init_img(img);
	img->img = mlx_xpm_file_to_image(game->mlx, path,
			&game->tex.size, &game->tex.size);
	if (img->img == NULL)
		exit_free(game, msg_error("xpm_file_to_image failed", 1));
	img->addr = (int *)mlx_get_data_addr(img->img, &img->pxl_bit,
			&img->line_size, &img->endian);
	return ;
}

int	*xpm_to_img(t_game *game, char *path)
{
	t_img	img_tmp;
	int		*buffer;
	int		x;
	int		y;

	create_texture(game, &img_tmp, path);
	buffer = ft_calloc(1,
			sizeof * buffer * game->tex.size * game->tex.size);
	if (!buffer)
		exit_free(game, msg_error("malloc failed", 1));
	y = 0;
	while (y < game->tex.size)
	{
		x = 0;
		while (x < game->tex.size)
		{
			buffer[y * game->tex.size + x]
				= img_tmp.addr[y * game->tex.size + x];
			++x;
		}
		y++;
	}
	mlx_destroy_image(game->mlx, img_tmp.img);
	return (buffer);
}
