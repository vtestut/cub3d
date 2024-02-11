/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:36:48 by vtestut           #+#    #+#             */
/*   Updated: 2024/02/11 19:59:50 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		exit_free(game, msg_error("mlx_init failed", 1));
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "Cub3D");
	if (!game->win)
		exit_free(game, msg_error("Could not create mlx window", 1));
	return ;
}

void	init_textures(t_game *game)
{
	game->textures = ft_calloc(5, sizeof * game->textures);
	if (!game->textures)
		exit_free(game, msg_error("malloc error init textures", 1));
	game->textures[NORTH] = xpm_to_img(game, game->data.north);
	game->textures[SOUTH] = xpm_to_img(game, game->data.south);
	game->textures[EAST] = xpm_to_img(game, game->data.east);
	game->textures[WEST] = xpm_to_img(game, game->data.west);
}

void	render_game(t_game *game)
{
	init_pixl(game);
	init_ray(&game->ray);
	raycasting(&game->player, game);
	render_window(game);
}

void	catch_input(t_game *game)
{
	mlx_hook(game->win, ClientMessage, NoEventMask, quit_cub3d, game);
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
		render_game(&game);
		catch_input(&game);
		mlx_loop_hook(game.mlx, render_loop, &game);
		mlx_loop(game.mlx);
	}
	else
		return (msg_error("launch with ./cub3d <path/to/map.cub>", 1));
	return (0);
}
