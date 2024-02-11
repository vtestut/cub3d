/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_01.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:36:48 by vtestut           #+#    #+#             */
/*   Updated: 2024/02/11 17:09:57 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// checks if the arg is a valid file and if it has the correct format
int	check_arg(char *arg, bool cub)
{
	int	fd;

	if (check_if_directory(arg))
		return (err_msg("map file is a directory", 1));
	fd = open(arg, O_RDONLY);
	if (fd == -1)
		return (err_msg("can't open  map file", 1));
	close(fd);
	if (cub && check_format(arg))
		return (err_msg("map file must be in .cub format", 1));
	if (!cub && !is_xpm_file(arg))
		return (err_msg("Not an .xpm file", 1));
	return (0);
}

// Initialize the player structure
void	init_player(t_player *player)
{
	player->dir = '\0';
	player->pos_x = 0.0;
	player->pos_y = 0.0;
	player->dir_x = 0.0;
	player->dir_y = 0.0;
	player->plane_x = 0.0;
	player->plane_y = 0.0;
	player->has_moved = 0;
	player->move_x = 0;
	player->move_y = 0;
	player->rotate = 0;
}

// Initialize the data structure
void	init_data(t_data *textures)
{
	textures->north = NULL;
	textures->south = NULL;
	textures->west = NULL;
	textures->east = NULL;
	textures->size = TEX_SIZE;
	textures->floor = 0;
	textures->ceiling = 0;
	textures->hex_floor = 0x0;
	textures->hex_ceiling = 0x0;
	textures->step = 0.0;
	textures->pos = 0.0;
	textures->x = 0;
	textures->y = 0;
}

// Initialize the game structure
void	init_game(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->map = NULL;
	game->path = NULL;
	game->file = NULL;
	game->textures = NULL;
	game->texture_pixels = NULL;
	game->win_height = WIN_HEIGHT;
	game->win_width = WIN_WIDTH;
	game->fd = 0;
	game->n_line = 0;
	game->height = 0;
	game->width = 0;
	game->index_end_of_map = 0;
	init_data(&game->data);
	init_player(&game->player);
}

// handle parsing functions
int	parser(t_game *game, char **argv)
{
	init_game(game);
	if (check_arg(argv[1], true))
		exit_free(game, 1);
	start_parse(argv[1], game);
	if (parse_file(game, game->file) == 1)
		return (free_game(game));
	if (check_map_validity(game, game->map) == 1)
		return (free_game(game));
	if (check_textures_validity(&game->data) == 1)
		return (free_game(game));
	init_player_direction(game);
	return (0);
}