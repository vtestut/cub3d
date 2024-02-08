/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:58:34 by vtestut           #+#    #+#             */
/*   Updated: 2024/02/05 16:48:56 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../libft/includes/libft.h"

void	free_tab(void **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	if (tab)
	{
		free(tab);
		tab = NULL;
	}
}

int	free_game(t_game *game)
{
	if (game->xpm)
		free_tab((void **)game->xpm);
	if (game->texture_pixels)
		free_tab((void **)game->texture_pixels);
	free_texinfo(&game->texinfo);
	free_map(game);
	return (1);
}

int	error_msg(char *str, int return_code)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	return (return_code);
}

void	ft_clean_exit(t_game *game, int return_code)
{
	if (!game)
		exit(return_code);
	if (game->window && game->mlx)
		mlx_destroy_window(game->mlx, game->window);
	if (game->mlx)
	{
		mlx_destroy_dispaly(game->mlx);
		mlx_loop_end(game->mlx);
		free(game->mlx);
	}
	free_game(game);
	exit(return_code);
}

void	ft_init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		ft_clean_exit(game, error_msg("mlx init error\n", 1));
	game->window = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	if (!game->window)
		ft_clean_exit(game, error_msg("mlx window error\n", 1));
	return ;
}

void	init_xpm(t_game *game)
{
	game->xpm = ft_calloc(5, sizeof * game->xpm);
	if (!game->xpm)
		ft_clean_exit(game, error_msg("game->texture malloc failed", 1));
	
}

int	main(int argc, char **argv)
{
	t_game	game;

	map_parsing(argc, argv, &game);
	init_mlx(&game);
	init_xpm(&game);
	return (0);
}
