/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05.pars_north_south.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:13:57 by vtestut           #+#    #+#             */
/*   Updated: 2024/01/23 11:17:29 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_manage_north_loop(t_map *data, char *file_data, int i, int len)
{
	while (file_data[i] && file_data[i] != '\n')
	{
		len++;
		i++;
	}
	data->north_txt = ft_calloc(sizeof(char), len + 1);
	i -= len;
	len = 0;
	while (file_data[i] && file_data[i] != '\n')
	{
		data->north_txt[len] = file_data[i];
		i++;
		len++;
	}
	return (i);
}

int	ft_manage_north(t_map *data, char *file_data, int i, t_parse *parse)
{
	int	len;

	len = 0;
	if (i == 0)
		i += 2;
	else 
		i += 3;
	while (file_data[i] && file_data[i] == ' ')
		i++;
	if (parse->valid_north == 1)
		return (-1);
	i = ft_manage_north_loop(data, file_data, i, len);
	parse->valid_north = 1;
	return (i - 1);
}

int	ft_manage_south_loop(t_map *data, char *file_data, int i, int len)
{
	while (file_data[i] && file_data[i] != '\n')
	{
		len++;
		i++;
	}
	data->south_txt = ft_calloc(sizeof(char), len + 1);
	i -= len;
	len = 0;
	while (file_data[i] && file_data[i] != '\n')
	{
		data->south_txt[len] = file_data[i];
		i++;
		len++;
	}
	return (i);
}

int	ft_manage_south(t_map *data, char *file_data, int i, t_parse *parse)
{
	int	len;

	len = 0;
	if (i == 0)
		i += 2;
	else
		i += 3;
	while (file_data[i] && file_data[i] != ' ')
		i++;
	if (parse->valid_south == 1)
		return (-1);
	i = ft_manage_south_loop(data, file_data, i, len);
	parse->valid_south = 1;
	return (i - 1);
}
