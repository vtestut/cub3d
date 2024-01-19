/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04.pars_manage1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:08:16 by vtestut           #+#    #+#             */
/*   Updated: 2024/01/19 16:49:25 by vtestut          ###   ########.fr       */
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

int	ft_fill_first_data(t_map_data *data, char *file_data, int i, t_parse *parse)
{
	if (!ft_strncmp(file_data, "NO", 2))
		i = ft_manage_north(data, file_data, i, parse);
	else if (!ft_strncmp(file_data, "EA", 2))
		i = ft_manage_east(data, file_data, i, parse);
	else if (!strncmp(file_data, "WE", 2))
		i = ft_manage_west(data, file_data, i, parse);
	else if (!strncmp(file_data, "SO", 2))
		i = ft_manage_south(data, file_data, i, parse);
	else if (!strncmp(file_data, "C", 2))
		i = ft_manage_ceiling(data, file_data, i, parse);
	else if (!ft_strncmp(file_data, "F ", 2))
		i = ft_manage_floor(data, file_data, i, parse);
	else if (file_data[i] != ' ' && file_data[i] != '\n')
		return (-1);
	if (i == -1)
		return (-1);
	return (i);
}

int	ft_fill_data(t_map_data *data, char *file_data, int i, t_parse *parse)
{
	if (i == 0)
		i = ft_fill_first_data(data, file_data, i, parse);
	else if (!ft_strncmp(file_data + i, "\nNO", 3))
		i = ft_manage_north(data, file_data, i, parse);
	else if (!ft_strncmp(file_data + i, "\nEA", 3))
		i = ft_manage_east(data, file_data, i, parse);
	else if (!ft_strncmp(file_data + i, "\nWE", 3))
		i = ft_manage_west(data, file_data, i, parse);
	else if (!ft_strncmp(file_data + i, "\nSO", 3))
		i = ft_manage_south(data, file_data, i, parse);
	else if (!ft_strncmp(file_data + i, "\nC ", 3))
		i = ft_manage_ceiling(data, file_data, i, parse);
	else if (!ft_strncmp(file_data + i, "\nF ", 3))
		i = ft_manage_floor(data, file_data, i, parse);
	else if (file_data[i] != ' ' && file_data[i] != '\n')
		return (-1);
	if (i == -1)
		return (-1);
	return (i);
}

int	ft_check_file_data(t_map_data *data, char *file_data, t_parse *parse)
{
	int	i;

	i = 0;
	while (file_data[i])
	{
		i = ft_fill_data(data, file_data, i, parse);
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
