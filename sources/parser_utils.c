/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser7.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:32:26 by vtestut           #+#    #+#             */
/*   Updated: 2024/02/12 14:04:46 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned long	rgb_to_hexa(int *rgb_tab)
{
	unsigned long	res;
	int				r;
	int				g;
	int				b;

	r = rgb_tab[0];
	g = rgb_tab[1];
	b = rgb_tab[2];
	res = ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
	return (res);
}

int	check_textures(t_tex *tex)
{
	if (!tex->north || !tex->south || !tex->west || !tex->east)
		return (msg_error("no texture", 1));
	if (!tex->floor || !tex->ceiling)
		return (msg_error("no color", 1));
	if (check_arg(tex->north, false) || check_arg(tex->south, false)
		|| check_arg(tex->west, false) || check_arg(tex->east, false)
		|| check_valid_rgb(tex->floor) || check_valid_rgb(tex->ceiling))
		return (1);
	tex->hexa_floor = rgb_to_hexa(tex->floor);
	tex->hexa_ceil = rgb_to_hexa(tex->ceiling);
	return (0);
}

int	check_map_is_eof(t_game *map)
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

int	check_pos_is_valid(t_game *game, char **map)
{
	int	i;
	int	j;

	i = (int)game->player.pos_y;
	j = (int)game->player.pos_x;
	if (ft_strlen(map[i - 1]) < (size_t)j || ft_strlen(map[i + 1]) < (size_t)j
		|| ft_isspace(map[i][j - 1]) == 0 || ft_isspace(map[i][j + 1]) == 0
		|| ft_isspace(map[i - 1][j]) == 0 || ft_isspace(map[i + 1][j]) == 0)
		return (1);
	return (0);
}
