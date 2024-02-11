/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_03.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:06:12 by vtestut           #+#    #+#             */
/*   Updated: 2024/02/11 17:12:43 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//extracts and returns a texture path from a line of text.
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

//fills structure with texture paths corresponding to cardinal directions.
int	fill_direction_textures(t_data *textures, char *line, int j)
{
	if (line[j + 2] && ft_isprint(line[j + 2]))
		return (1);
	if (line[j] == 'N' && line[j + 1] == 'O' && !(textures->north))
		textures->north = get_texture_path(line, j + 2);
	else if (line[j] == 'S' && line[j + 1] == 'O' && !(textures->south))
		textures->south = get_texture_path(line, j + 2);
	else if (line[j] == 'W' && line[j + 1] == 'E' && !(textures->west))
		textures->west = get_texture_path(line, j + 2);
	else if (line[j] == 'E' && line[j + 1] == 'A' && !(textures->east))
		textures->east = get_texture_path(line, j + 2);
	else
		return (1);
	return (0);
}

// fills structure with texture paths corresponding to the floor and ceiling.
int	skip_spaces(t_game *game, char **map, int i, int j)
{
	while (map[i][j] == ' ' || map[i][j] == '\t' || map[i][j] == '\n')
		j++;
	if (ft_isprint(map[i][j]) && !ft_isdigit(map[i][j]))
	{
		if (map[i][j + 1] && ft_isprint(map[i][j + 1])
			&& !ft_isdigit(map[i][j]))
		{
			if (fill_direction_textures(&game->data, map[i], j) == 1)
				return (err_msg("Invalid texture", 1));
			return (3);
		}	
		else
		{
			if (fill_color_textures(&game->data, map[i], j) == 2)
				return (1);
			return (3);
		}	
	}
	else if (ft_isdigit(map[i][j]))
	{
		if (create_map(game, map, i) == 1)
			return (err_msg("problem with map description", 1));
		return (0);
	}
	return (4);
}

// parse the map file and fills the game structure
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
			ret = skip_spaces(game, map, i, j);
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

// fill the game structure with the map data.
void	fill_map(int row, int col, int i, t_game *game)
{
	char	*line;

	line = get_next_line(game->fd);
	while (line != NULL)
	{
		game->file[row] = ft_calloc(ft_strlen(line) + 1, sizeof(char));
		if (!game->file[row])
		{
			err_msg("malloc error", 0);
			return (free_tab((void **)game->file));
		}
		while (line[i] != '\0')
			game->file[row][col++] = line[i++];
		game->file[row++][col] = '\0';
		col = 0;
		i = 0;
		free(line);
		line = get_next_line(game->fd);
	}
	game->file[row] = NULL;
}
