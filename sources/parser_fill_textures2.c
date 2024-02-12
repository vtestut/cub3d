/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_fill_textures2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 10:27:02 by vtestut           #+#    #+#             */
/*   Updated: 2024/02/12 14:20:22 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	create_map(t_game *game, char **file, int i)
{
	if (get_map_info(game, file, i))
		return (1);
	change_spaces_to_walls(game);
	return (0);
}

int	no_digit(char *str)
{
	int		i;
	bool	digit;

	i = 0;
	digit = 0; // true
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			digit = 1;
		i++;
	}
	return (digit);
}

int	*copy_into_rgb_tab(char **rgb_tab, int *rgb)
{
	int		i;

	i = -1;
	while (rgb_tab[++i])
	{
		rgb[i] = ft_atoi(rgb_tab[i]);
		if (rgb[i] == -1 || no_digit(rgb_tab[i]) == 0)
		{
			ft_free_tab((void **)rgb_tab);
			free(rgb);
			return (0);
		}
	}
	ft_free_tab((void **)rgb_tab);
	return (rgb);
}

int	*set_rgb_colors(char *line)
{
	char	**rgb_tab;
	int		*rgb;
	int		count;

	rgb_tab = ft_split(line, ',');
	count = 0;
	while (rgb_tab[count])
		count++;
	if (count != 3)
	{
		ft_free_tab((void **)rgb_tab);
		return (0);
	}
	rgb = malloc(sizeof(int) * 3);
	if (!rgb)
	{
		msg_error("malloc failed", 0);
		return (0);
	}
	return (copy_into_rgb_tab(rgb_tab, rgb));
}

int	get_colors(t_tex *tex, char *line, int j)
{
	if (line[j + 1] && ft_isprint(line[j + 1]))
		return (msg_error("Invalid floor/ceiling color", 2));
	if (!tex->ceiling && line[j] == 'C')
	{
		tex->ceiling = set_rgb_colors(line + j + 1);
		if (tex->ceiling == 0)
			return (msg_error("Invalid ceiling color", 2));
	}
	else if (!tex->floor && line[j] == 'F')
	{
		tex->floor = set_rgb_colors(line + j + 1);
		if (tex->floor == 0)
			return (msg_error("Invalid floor color", 2));
	}
	else
		return (msg_error("Invalid floor/ceiling color", 2));
	return (0);
}
