/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_fill_textures.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:06:12 by vtestut           #+#    #+#             */
/*   Updated: 2024/02/13 19:38:16 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*get_texture_path(char *line, int j)
{
	int		len;
	int		i;
	char	*path;

	while (line[j] && (line[j] == ' ' || line[j] == '\t'))
		j++;
	len = j;
	while (line[len] && (line[len] != ' ' && line[len] != '\t'))
		len++;
	path = malloc(sizeof(char) * (len - j + 1));
	if (!path)
		return (NULL);
	i = 0;
	while (line[j] && (line[j] != ' ' && line[j] != '\t' && line[j] != '\n'))
		path[i++] = line[j++];
	path[i] = '\0';
	while (line[j] && (line[j] == ' ' || line[j] == '\t'))
		j++;
	if (line[j] && line[j] != '\n')
	{
		free(path);
		path = NULL;
	}
	return (path);
}

int	get_direction_textures(t_tex *tex, char *line, int j)
{
	if (line[j + 2] && ft_isprint(line[j + 2]))
		return (1);
	if (line[j] == 'N' && line[j + 1] == 'O' && !(tex->north))
		tex->north = get_texture_path(line, j + 2);
	else if (line[j] == 'S' && line[j + 1] == 'O' && !(tex->south))
		tex->south = get_texture_path(line, j + 2);
	else if (line[j] == 'W' && line[j + 1] == 'E' && !(tex->west))
		tex->west = get_texture_path(line, j + 2);
	else if (line[j] == 'E' && line[j + 1] == 'A' && !(tex->east))
		tex->east = get_texture_path(line, j + 2);
	else
		return (1);
	return (0);
}

int	create_map(t_game *game, char **file, int i)
{
	if (get_map_info(game, file, i))
		return (1);
	change_spaces_to_walls(game);
	return (0);
}

int	skip_spaces_fill_tex(t_game *game, char **map, int i, int j)
{
	while (map[i][j] == ' ' || map[i][j] == '\t' || map[i][j] == '\n')
		j++;
	if (ft_isprint(map[i][j]) && !ft_isdigit(map[i][j]))
	{
		if (map[i][j + 1] && ft_isprint(map[i][j + 1])
			&& !ft_isdigit(map[i][j]))
		{
			if (get_direction_textures(&game->tex, map[i], j))
				return (msg_error("invalid texture", 1));
			return (3);
		}
		else
		{
			if (get_colors(&game->tex, map[i], j) == 2)
				return (1);
			return (3);
		}
	}
	else if (ft_isdigit(map[i][j]))
	{
		if (create_map(game, map, i) == 1)
			return (msg_error("invalid map description", 1));
		return (0);
	}
	return (4);
}

int	parse_file(t_game *game, char **map)
{
	int	i;
	int	j;
	int	ret;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			ret = skip_spaces_fill_tex(game, map, i, j);
			if (ret == 3)
				break ;
			else if (ret == 1)
				return (1);
			else if (ret == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (0);
}
