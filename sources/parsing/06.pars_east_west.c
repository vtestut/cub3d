/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06.pars_east_west.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:16:47 by vtestut           #+#    #+#             */
/*   Updated: 2024/01/23 12:39:27 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_manage_east_loop(t_map *data, char *file, int i, int len)
{
	while (file[i] && file[i] != '\n')
	{
		len++;
		i++;
	}
	data->east_txt = ft_calloc(sizeof(char), len + 1);
	i -= len;
	len = 0;
	while (file[i] && file[i] != '\n')
	{
		data->east_txt[len] = file[i];
		i++;
		len++;
	}
	return (i);
}

int	ft_manage_east(t_map *data, char *file, int i, t_parse *parse)
{
	int	len;

	len = 0;
	if (i == 0)
		i += 2;
	else
		i += 3;
	while (file && file[i] != ' ')
		i++;
	if (parse->valid_east == 1)
		return (-1);
	i = ft_manage_east_loop(data, file, i, len);
	parse->valid_east = 1;
	return (i - 1);
}

int	ft_manage_west_loop(t_map *data, char *file, int i, int len)
{
	while (file[i] && file[i] != '\n')
	{
		len++;
		i++;
	}
	data->west_txt = ft_calloc(sizeof(char), len + 1);
	i -= len;
	len = 0;
	while (file[i] && file[i] != '\n')
	{
		data->west_txt[len] = file[i];
		i++;
		len++;
	}
	return (i);
}

int	ft_manage_west(t_map *data, char *file, int i, t_parse *parse)
{
	int	len;

	len = 0;
	if (i == 0)
		i += 2;
	else
		i += 3;
	while (file[i] && file[i] != ' ')
		i++;
	if (parse->valid_west == 1)
		return (-1);
	i = ft_manage_west_loop(data, file, i, len);
	parse->valid_west = 1;
	return (i - 1);
}
