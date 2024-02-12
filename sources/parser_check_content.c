/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check_content.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 22:18:24 by vtestut           #+#    #+#             */
/*   Updated: 2024/02/12 14:04:35 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_player_pos(t_game *game, char **map_tab)
{
	int	i;
	int	j;

	if (game->player.dir == '0')
		return (msg_error("no player position", 1));
	i = 0;
	while (map_tab[i])
	{
		j = 0;
		while (map_tab[i][j])
		{
			if (ft_strchr("NSEW", map_tab[i][j]))
			{
				game->player.pos_x = (float)j + 0.5;
				game->player.pos_y = (float)i + 0.5;
				map_tab[i][j] = '0';
			}
			j++;
		}
		i++;
	}
	if (check_pos_is_valid(game, map_tab))
		return (msg_error("wrong player position", 1));
	return (0);
}

int	check_map_char(t_game *game, char **map_tab)
{
	int	i;
	int	j;

	i = 0;
	game->player.dir = '0';
	while (map_tab[i] != NULL)
	{
		j = 0;
		while (map_tab[i][j])
		{
			while (game->map[i][j] == ' ' || game->map[i][j] == '\t'
			|| game->map[i][j] == '\r'
			|| game->map[i][j] == '\v' || game->map[i][j] == '\f')
				j++;
			if (!(ft_strchr("10NSEW", map_tab[i][j])))
				return (msg_error("invalid char in map file", 1));
			if (ft_strchr("NSEW", map_tab[i][j]) && game->player.dir != '0')
				return (msg_error("map must have 1 player", 1));
			if (ft_strchr("NSEW", map_tab[i][j]) && game->player.dir == '0')
				game->player.dir = map_tab[i][j];
			j++;
		}
		i++;
	}
	return (0);
}

int	check_walls_utils(char **map_tab, int i, int j)
{
	if (!map_tab || !map_tab[i] || !map_tab[i][j])
		return (1);
	while (map_tab[i][j] == ' ' || map_tab[i][j] == '\t'
	|| map_tab[i][j] == '\r' || map_tab[i][j] == '\v'
	|| map_tab[i][j] == '\f')
		j++;
	while (map_tab[i][j])
	{
		if (map_tab[i][j] != '1')
			return (1);
		j++;
	}
	return (0);
}

int	check_walls(t_game *map, char **map_tab)
{
	int	i;
	int	j;

	if (check_walls_utils(map_tab, 0, 0))
		return (1);
	i = 1;
	while (i < (map->height - 1))
	{
		j = ft_strlen(map_tab[i]) - 1;
		if (map_tab[i][j] != '1')
			return (1);
		i++;
	}
	if (check_walls_utils(map_tab, i, 0))
		return (1);
	return (0);
}

int	check_map(t_game *game, char **map_tab)
{
	if (!game->map)
		return (msg_error("map is missing", 1));
	if (check_walls(game, map_tab) == 1)
		return (msg_error("map must be surrounded by walls", 1));
	if (game->height < 3)
		return (msg_error("map too small", 1));
	if (check_map_char(game, map_tab) == 1)
		return (1);
	if (check_player_pos(game, map_tab) == 1)
		return (1);
	if (check_map_is_eof(game) == 1)
		return (msg_error("map must be a the end of file", 1));
	return (0);
}
