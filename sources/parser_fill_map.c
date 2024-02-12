/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_fill_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:43:51 by vtestut           #+#    #+#             */
/*   Updated: 2024/02/12 17:56:22 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	change_spaces_to_walls(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j] == ' ' || game->map[i][j] == '\t'
		|| game->map[i][j] == '\r' || game->map[i][j] == '\v'
		|| game->map[i][j] == '\f')
			j++;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == ' '
				&& j != game->map[i][ft_strlen(game->map[i]) - 1])
				game->map[i][j] = '1';
		}
		i++;
	}
}

size_t	find_biggest_line(t_game *game, int i)
{
	size_t	line;

	line = ft_strlen(game->file[i]);
	while (game->file[i])
	{
		if (ft_strlen(game->file[i]) > line)
			line = ft_strlen(game->file[i]);
		i++;
	}
	return (line);
}

int	fill_map_tab(t_game *game, char **map_tab, int index)
{
	int		i;
	int		j;

	game->width = find_biggest_line(game, index);
	i = 0;
	while (i < game->height)
	{
		j = 0;
		map_tab[i] = malloc(sizeof(char) * (game->width + 1));
		if (!map_tab[i])
			return (msg_error("malloc failed", 1));
		while (game->file[index][j] && game->file[index][j] != '\n')
		{
			map_tab[i][j] = game->file[index][j];
			j++;
		}
		while (j < game->width)
			map_tab[i][j++] = '\0';
		i++;
		index++;
	}
	map_tab[i] = NULL;
	return (0);
}

int	count_map_lines(t_game *game, char **file, int i)
{
	int	index_value;
	int	j;

	index_value = i;
	while (file[i])
	{
		j = 0;
		while (file[i][j] == ' ' || file[i][j] == '\t' || file[i][j] == '\r'
		|| file[i][j] == '\v' || file[i][j] == '\f')
			j++;
		if (file[i][j] != '1')
			break ;
		i++;
	}
	game->map_end = i;
	return (i - index_value);
}

int	get_map_info(t_game *game, char **file, int i)
{
	game->height = count_map_lines(game, file, i);
	game->map = malloc(sizeof(char *) * (game->height + 1));
	if (!game->map)
		return (msg_error("malloc failed", 1));
	if (fill_map_tab(game, game->map, i))
		return (1);
	return (0);
}
