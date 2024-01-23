/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08.pars_map_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:24:39 by vtestut           #+#    #+#             */
/*   Updated: 2024/01/23 12:39:27 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_check_map_border_bis(char *file, int max_w, int max_l, t_map *data)
{
	char	**map;
	int		i;

	map = ft_calloc(sizeof(char *), (max_l + 6));
	if (!map)
		return (1);
	i = 0;
	while (i < max_l + 5)
	{
		map[i] = ft_calloc(sizeof(char), (max_w + 5));
		if (!map[i])
			return (1);
		i++;
	}
	map = ft_add_border(max_w, max_l, map);
	map = ft_fill_middle(file, map, data);
	if (ft_check_each_char_map(map))
	{
		ft_free_arr((void **)map);
		return (1);
	}
	ft_free_arr((void **)map);
	return (0);
}

int	ft_check_map_border(char *file, t_map *data)
{
	int	i;
	int	width;
	int	len;
	int	max_width;

	i = data->map_index;
	width = 0;
	len = 0;
	max_width = 0;
	while (file[i])
	{
		if (file[i] == '\n')
		{
			if (width > max_width)
				max_width = width;
			width = 0;
			len++;
		}
		else
			width++;
		i++;
	}
	if (ft_check_map_border_bis(file, max_width, len, data))
		return (1);
	return (0);
}

int	ft_check_valid_char(char *file, int i)
{
	if (file[i] != '\n' && file[i] != 'N' && \
		file[i] != 'S' && file[i] != 'E' && \
		file[i] != 'W' && file[i] != ' ' && \
		file[i] != '0' && file[i] != '1')
		return (1);
	return (0);
}

int	ft_check_map_loop(char *file, int i)
{
	int	player;
	int	valid;
	int	newline;

	valid = 0;
	player = 0;
	newline = 0;
	while (file[i])
	{
		if (file[i] == 'N' || file[i] == 'S' || \
			file[i] == 'E' || file[i] == 'W')
			player++;
		if (ft_check_valid_char(file, i))
			return (1);
		if (file[i] == '1')
			valid++;
		if (file[i] == '\n')
			newline++;
		i++;
	}
	if (player != 1 || valid < 8 || newline < 2)
		return (1);
	return (0);
}

int	ft_check_map(t_map *data, char *file)
{
	int	i;

	i = data->map_index;
	while (file[i] && file[i] == '\n')
		i++;
	data->map_index = i;
	if (ft_check_map_loop(file, i))
		return (1);
	if (ft_check_map_border(file, data))
		return (1);
	return (0);
}
