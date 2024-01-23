/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07.pars_ceiling_floor.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:19:17 by vtestut           #+#    #+#             */
/*   Updated: 2024/01/23 12:39:27 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_check_id_nb(char *file, int i)
{
	int	values[3];
	int	cur_value;

	values[0] = 0;
	values[1] = 0;
	values[2] = 0;
	cur_value = 0;
	while (file[i] && file[i] != '\n')
	{
		if (file[i] >= '0' && file[i] <= '9')
			values[cur_value] = values[cur_value] * 10 + (file[i] - '0');
		else if (file[i] == ',')
			cur_value++;
		else
			return (-1);
		if (values[cur_value] > 255)
			return (-1);
		i++;
	}
	if (cur_value != 2)
		return (-1);
	return (i);
}

int	ft_get_rgb_value_ceil(t_map *data, char *file, int i, t_parse *parse)
{
	int	j;

	if (parse->valid_ceil == 1)
		return (-1);
	j = 0;
	data->ceil_color[j++] = ft_atoi(file + i);
	while (file[i] && file[i] != ',')
		i++;
	i++;
	data->ceil_color[j++] = ft_atoi(file + i);
	parse->valid_ceil = 1;
	return (0);
}

int	ft_manage_ceiling(t_map *data, char *file, int i, t_parse *parse)
{
	int	stock;

	i += 2;
	while (file[i] && file[i] == ' ')
		i++;
	if (file[i] == '\n')
		return (-1);
	stock = i;
	i = ft_check_id_nb(file, i);
	if (i == -1)
		return (-1);
	if (ft_get_rgb_value_ceil(data, file, stock, parse) == -1)
		return (-1);
	return (i - 1);
}

int	ft_get_rgb_value_floor(t_map *data, char *file, int i, t_parse *parse)
{
	int	j;

	j = 0;
	if (parse->valid_floor == 1)
		return (-1);
	data->floor_color[j++] = ft_atoi(file + i);
	while (file[i] && file[i] != ',')
		i++;
	i++;
	data->floor_color[j++] = ft_atoi(file + i);
	while (file[i] && file[i] != ',')
		i++;
	i++;
	data->floor_color[j++] = ft_atoi(file + i);
	parse->valid_floor = 1;
	return (0);
}

int	ft_manage_floor(t_map *data, char *file, int i, t_parse *parse)
{
	int	stock;

	i += 2;
	while (file[i] && file[i] == ' ')
		i++;
	if (file[i] == '\n')
		return (-1);
	stock = i;
	i = ft_check_id_nb(file, i);
	if (i == -1)
		return (-1);
	if (ft_get_rgb_value_floor(data, file, stock, parse) == -1)
		return (-1);
	return (i - 1);
}
