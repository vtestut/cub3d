/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_06.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 22:18:24 by vtestut           #+#    #+#             */
/*   Updated: 2024/02/11 17:20:14 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// check where the player is in the map and fill the player structure.
int	check_player_position(t_game *game, char **map_tab)
{
	int	i;
	int	j;

	if (game->player.dir == '0')
		return (err_msg("no player position", 1));
	i = 0;
	while (map_tab[i])
	{
		j = 0;
		while (map_tab[i][j])
		{
			if (ft_strchr("NSEW", map_tab[i][j]))
			{
				game->player.pos_x = (double)j + 0.5;
				game->player.pos_y = (double)i + 0.5;
				map_tab[i][j] = '0';
			}
			j++;
		}
		i++;
	}
	if (check_position_is_valid(game, map_tab) == 1)
		return (err_msg("wrong player position", 1));
	return (0);
}

// check if map file contains only "10NSEW"
int	check_map_elements(t_game *game, char **map_tab)
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
				return (err_msg("invalid char in map file", 1));
			if (ft_strchr("NSEW", map_tab[i][j]) && game->player.dir != '0')
				return (err_msg("map must have 1 player", 1));
			if (ft_strchr("NSEW", map_tab[i][j]) && game->player.dir == '0')
				game->player.dir = map_tab[i][j];
			j++;
		}
		i++;
	}
	return (0);
}

// check the top and bottom of the map
int	check_top_or_bottom(char **map_tab, int i, int j)
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

// check the sides of the map
int	check_map_sides(t_game *map, char **map_tab)
{
	int	i;
	int	j;

	if (check_top_or_bottom(map_tab, 0, 0) == 1)
		return (1);
	i = 1;
	while (i < (map->height - 1))
	{
		j = ft_strlen(map_tab[i]) - 1;
		if (map_tab[i][j] != '1')
			return (1);
		i++;
	}
	if (check_top_or_bottom(map_tab, i, 0) == 1)
		return (1);
	return (0);
}

// launch the map check
int	check_map_validity(t_game *game, char **map_tab)
{
	if (!game->map)
		return (err_msg("map is missing", 1));
	if (check_map_sides(game, map_tab) == 1)
		return (err_msg("map must be surrounded by walls", 1));
	if (game->height < 3)
		return (err_msg("map too small", 1));
	if (check_map_elements(game, map_tab) == 1)
		return (1);
	if (check_player_position(game, map_tab) == 1)
		return (1);
	if (check_map_is_at_the_end(game) == 1)
		return (err_msg("map must be a the end of file", 1));
	return (0);
}