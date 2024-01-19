/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01.pars_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:56:37 by vtestut           #+#    #+#             */
/*   Updated: 2024/01/19 17:06:16 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void ft_init_parse(t_parse *parse)
{
	parse->valid_north = 0;
	parse->valid_south = 0;
	parse->valid_east = 0;
	parse->valid_west = 0;
	parse->valid_floor = 0;
	parse->valid_ceil = 0;
}

void	ft_init_data(t_map_data *data) //static ?
{
	data->north_txt = NULL;
	data->south_txt = NULL;
	data->east_txt = NULL;
	data->west_txt = NULL;
	data->floor_color[0] = 0;
	data->floor_color[1] = 0;
	data->floor_color[2] = 0;
	data->ceil_color[0] = 0;
	data->ceil_color[1] = 0;
	data->ceil_color[2] = 0;
	data->pos_player_x = 0; // TODO
	data->pos_player_y = 0; // TODO
	data->map_index = 0;
	data->map_max_x = 0;
	data->map_max_y = 0;
	data->map = NULL;
}

static char	get_init_player_dir(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map && map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N'
					|| map[i][j] == 'S'
					|| map[i][j] == 'W'
					|| map[i][j] == 'E')
				return (map[i][j]);
			j++;
		}
		i++;
	}
	return (-1);
}

static void	initial_player_direction(char dir, t_vector_d *player_dir,
		t_vector_d *player_plane)
{
	if (dir == 'N')
	{
		player_dir->x = -1;
		player_plane->y = 0.85;
	}
	else if (dir == 'S')
	{
		player_dir->x = 1;
		player_plane->y = -0.85;
	}
	else if (dir == 'E')
	{
		player_dir->y = 1;
		player_plane->x = 0.85;
	}
	else if (dir == 'W')
	{
		player_dir->y = -1;
		player_plane->x = -0.85;
	}
}

void	map_parsing(int argc, char **argv, t_game *game)
{
	t_parse	parse;

	ft_init_parse(&parse);
	ft_init_data(&game->data);
	ft_start(argc, argv, &game->data, &parse);
	game->bg_colors[CLR_BOT] = game->data.floor_color[0] << 24
		| game->data.floor_color[1] << 16
		| game->data.floor_color[2] << 8
		| 0xff;
	game->bg_colors[CLR_TOP] = game->data.ceil_color[0] << 24
		| game->data.ceil_color[1] << 16
		| game->data.ceil_color[2] << 8
		| 0xff;
	game->player.pos.x = game->data.pos_player_y + 0.5;
	game->player.pos.y = game->data.pos_player_x + 0.5;
	game->player.dir.x = 0;
	game->player.dir.y = 0;
	game->player.plane.x = 0;
	game->player.plane.y = 0;
	initial_player_direction(get_init_player_dir(game->data.map), &game->player.dir, &game->player.plane);
}