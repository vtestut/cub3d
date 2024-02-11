/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 10:27:02 by vtestut           #+#    #+#             */
/*   Updated: 2024/02/11 19:42:12 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	create_map(t_game *game, char **file, int i)
{
	if (get_map_info(game, file, i) == 1)
		return (1);
	change_space_into_wall(game);
	return (0);
}

bool	no_digit(char *str)
{
	int		i;
	bool	digit;

	i = 0;
	digit = true;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 1)
			digit = false;
		i++;
	}
	return (digit);
}

int	*copy_into_rgb_array(char **rgb_to_convert, int *rgb)
{
	int		i;

	i = -1;
	while (rgb_to_convert[++i])
	{
		rgb[i] = ft_atoi(rgb_to_convert[i]);
		if (rgb[i] == -1 || no_digit(rgb_to_convert[i]) == true)
		{
			free_tab((void **)rgb_to_convert);
			free(rgb);
			return (0);
		}
	}
	free_tab((void **)rgb_to_convert);
	return (rgb);
}

int	*set_rgb_colors(char *line)
{
	char	**rgb_to_convert;
	int		*rgb;
	int		count;

	rgb_to_convert = ft_split(line, ',');
	count = 0;
	while (rgb_to_convert[count])
		count++;
	if (count != 3)
	{
		free_tab((void **)rgb_to_convert);
		return (0);
	}
	rgb = malloc(sizeof(int) * 3);
	if (!rgb)
	{
		msg_error("malloc error set_rgb_colors", 0);
		return (0);
	}
	return (copy_into_rgb_array(rgb_to_convert, rgb));
}

int	fill_color_textures(t_data *textures, char *line, int j)
{
	if (line[j + 1] && ft_isprint(line[j + 1]))
		return (msg_error("Invalid floor/ceiling color", 2));
	if (!textures->ceiling && line[j] == 'C')
	{
		textures->ceiling = set_rgb_colors(line + j + 1);
		if (textures->ceiling == 0)
			return (msg_error("Invalid ceiling color", 2));
	}
	else if (!textures->floor && line[j] == 'F')
	{
		textures->floor = set_rgb_colors(line + j + 1);
		if (textures->floor == 0)
			return (msg_error("Invalid floor color", 2));
	}
	else
		return (msg_error("Invalid floor/ceiling color", 2));
	return (0);
}
