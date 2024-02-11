/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser7.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:32:26 by vtestut           #+#    #+#             */
/*   Updated: 2024/02/11 19:44:40 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned long	convert_rgb_to_hex(int *rgb_tab)
{
	unsigned long	result;
	int				r;
	int				g;
	int				b;

	r = rgb_tab[0];
	g = rgb_tab[1];
	b = rgb_tab[2];
	result = ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
	return (result);
}

int	check_textures(t_data *textures)
{
	if (!textures->north || !textures->south || !textures->west
		|| !textures->east)
		return (msg_error("no texture", 1));
	if (!textures->floor || !textures->ceiling)
		return (msg_error("no color", 1));
	if (check_arg(textures->north, false) == 1
		|| check_arg(textures->south, false) == 1
		|| check_arg(textures->west, false) == 1
		|| check_arg(textures->east, false) == 1
		|| check_valid_rgb(textures->floor) == 1
		|| check_valid_rgb(textures->ceiling) == 1)
		return (1);
	textures->hex_floor = convert_rgb_to_hex(textures->floor);
	textures->hex_ceiling = convert_rgb_to_hex(textures->ceiling);
	return (0);
}

int	check_map_is_at_the_end(t_game *map)
{
	int	i;
	int	j;

	i = map->map_end;
	while (map->file[i])
	{
		j = 0;
		while (map->file[i][j])
		{
			if (map->file[i][j] != ' ' && map->file[i][j] != '\t'
				&& map->file[i][j] != '\r' && map->file[i][j] != '\n'
				&& map->file[i][j] != '\v' && map->file[i][j] != '\f')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_a_white_space(char c)
{
	if (c != ' ' && c != '\t' && c != '\r'
		&& c != '\n' && c != '\v' && c != '\f')
		return (1);
	else
		return (0);
}

int	check_position_is_valid(t_game *game, char **map_tab)
{
	int	i;
	int	j;

	i = (int)game->player.pos_y;
	j = (int)game->player.pos_x;
	if (ft_strlen(map_tab[i - 1]) < (size_t)j
		|| ft_strlen(map_tab[i + 1]) < (size_t)j
		|| is_a_white_space(map_tab[i][j - 1]) == 0
		|| is_a_white_space(map_tab[i][j + 1]) == 0
		|| is_a_white_space(map_tab[i - 1][j]) == 0
		|| is_a_white_space(map_tab[i + 1][j]) == 0)
		return (1);
	return (0);
}
