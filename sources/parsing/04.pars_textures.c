/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04.pars_map_fill_data.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:08:16 by vtestut           #+#    #+#             */
/*   Updated: 2024/01/23 12:49:29 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_check_if_full(t_parse *parse)
{
	if (parse->valid_north && parse->valid_east && parse->valid_south && \
		parse->valid_west && parse->valid_ceil && parse->valid_floor)
		return (1);
	return (0);
}

int	ft_fill_first_data(t_map *data, char *file, int i, t_parse *parse)
{
	if (!ft_strncmp(file, "NO", 2))
		i = ft_manage_north(data, file, i, parse);
	else if (!ft_strncmp(file, "EA", 2))
		i = ft_manage_east(data, file, i, parse);
	else if (!strncmp(file, "WE", 2))
		i = ft_manage_west(data, file, i, parse);
	else if (!strncmp(file, "SO", 2))
		i = ft_manage_south(data, file, i, parse);
	else if (!strncmp(file, "C", 2))
		i = ft_manage_ceiling(data, file, i, parse);
	else if (!ft_strncmp(file, "F ", 2))
		i = ft_manage_floor(data, file, i, parse);
	else if (file[i] != ' ' && file[i] != '\n')
		return (-1);
	if (i == -1)
		return (-1);
	return (i);
}

int	ft_fill_data(t_map *data, char *file, int i, t_parse *parse)
{
	if (i == 0)
		i = ft_fill_first_data(data, file, i, parse);
	else if (!ft_strncmp(file + i, "\nNO", 3))
		i = ft_manage_north(data, file, i, parse);
	else if (!ft_strncmp(file + i, "\nEA", 3))
		i = ft_manage_east(data, file, i, parse);
	else if (!ft_strncmp(file + i, "\nWE", 3))
		i = ft_manage_west(data, file, i, parse);
	else if (!ft_strncmp(file + i, "\nSO", 3))
		i = ft_manage_south(data, file, i, parse);
	else if (!ft_strncmp(file + i, "\nC ", 3))
		i = ft_manage_ceiling(data, file, i, parse);
	else if (!ft_strncmp(file + i, "\nF ", 3))
		i = ft_manage_floor(data, file, i, parse);
	else if (file[i] != ' ' && file[i] != '\n')
		return (-1);
	if (i == -1)
		return (-1);
	return (i);
}

int	ft_check_file_data(t_map *data, char *file, t_parse *parse)
{
	int	i;

	i = 0;
	while (file[i])
	{
		i = ft_fill_data(data, file, i, parse);
		if (i == -1)
			return (1);
		if (ft_check_if_full(parse))
		{
			data->map_index = i + 1;
			return (0);
		}
		i++;
	}
	return (1);
}
