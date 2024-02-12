/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:05:02 by vtestut           #+#    #+#             */
/*   Updated: 2024/02/12 13:35:01 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_textures(t_tex *tex)
{
	if (tex->north)
		free(tex->north);
	if (tex->south)
		free(tex->south);
	if (tex->west)
		free(tex->west);
	if (tex->east)
		free(tex->east);
	if (tex->floor)
		free(tex->floor);
	if (tex->ceiling)
		free(tex->ceiling);
}

int	free_game(t_game *game)
{
	if (game->tex_arr)
		ft_free_tab((void **)game->tex_arr);
	if (game->tex_pxl)
		ft_free_tab((void **)game->tex_pxl);
	if (game->fd > 0)
		close(game->fd);
	if (game->file)
		ft_free_tab((void **)game->file);
	if (game->map)
		ft_free_tab((void **)game->map);
	free_textures(&game->tex);
	return (1);
}

void	exit_free(t_game *game, int ret)
{
	if (!game)
		exit(ret);
	if (game->win && game->mlx)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		mlx_loop_end(game->mlx);
		free(game->mlx);
	}
	free_game(game);
	exit(ret);
}

int	exit_mlx(t_game *game)
{
	exit_free(game, 0);
	return (0);
}

int	msg_error(char *str, int ret)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	return (ret);
}
