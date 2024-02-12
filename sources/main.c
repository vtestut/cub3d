/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:36:48 by vtestut           #+#    #+#             */
/*   Updated: 2024/02/12 14:26:13 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		exit_free(game, msg_error("mlx_init failed", 1));
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "cub3d");
	if (!game->win)
		exit_free(game, msg_error("mlx_new_window failed", 1));
}

void	init_textures(t_game *game)
{
	game->tex_arr = ft_calloc(5, sizeof * game->tex_arr);
	if (!game->tex_arr)
		exit_free(game, msg_error("malloc failed", 1));
	game->tex_arr[NORTH] = xpm_to_img(game, game->tex.north);
	game->tex_arr[SOUTH] = xpm_to_img(game, game->tex.south);
	game->tex_arr[EAST] = xpm_to_img(game, game->tex.east);
	game->tex_arr[WEST] = xpm_to_img(game, game->tex.west);
}

void	display_game(t_game *game)
{
	init_pxl(game);
	init_ray(&game->ray);
	raycasting(&game->player, game);
	display_window(game);
}

void	catch_input(t_game *game)
{
	mlx_hook(game->win, ClientMessage, NoEventMask, exit_mlx, game);
	mlx_hook(game->win, KeyPress, KeyPressMask, key_press, game);
	mlx_hook(game->win, KeyRelease, KeyReleaseMask, key_release, game);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		if (parser(&game, argv))
			return (1);
		init_mlx(&game);
		init_textures(&game);
		display_game(&game);
		catch_input(&game);
		mlx_loop_hook(game.mlx, display_loop, &game);
		mlx_loop(game.mlx);
	}
	else
		return (msg_error("exec with ./cub3d path/to/map.cub", 1));
	return (0);
}
