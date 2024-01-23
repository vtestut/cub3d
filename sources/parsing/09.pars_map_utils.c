/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09.pars_map_fill_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:29:31 by vtestut           #+#    #+#             */
/*   Updated: 2024/01/23 11:17:29 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_check_each_char_map(char **map)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (map[i + 1])
	{
		while (map[i + 1][j + 1])
		{
			if (map[i][j] == ' ')
			{
				if ((map[i - 1][j] != '1' && map[i - 1][j] != ' ') || \
				(map[i + 1][j] != '1' && map[i + 1][j] != ' ') || \
				(map[i][j - 1] != '1' && map[i][j - 1] != ' ') || \
				(map[i][j + 1] != '1' && map[i][j + 1] != ' '))
					return (1);
			}
			j++;
		}
		j = 1;
		i++;
	}
	return (0);
}

char	**ft_fill_middle(char *file, char **map, t_map *data)
{
	int	i;
	int	j;
	int	x;

	i = 2;
	j = 2;
	x = data->map_index;
	while (file[x])
	{
		if (file[x] == '\n')
		{
			j = 1;
			i++;
		}
		else
			map[i][j] = file[x];
		x++;
		j++;
	}
	return (map);
}

char	**ft_add_border(int width, int len, char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < len + 5)
	{
		while (j < width + 4)
		{
			if (i == 0 || i == len + 4 || j == 0 || j == width + 3)
				map[i][j] = '1';
			else
				map[i][j] = ' ';
			j++;
		}
		i++;
		j = 0;
	}
	return (map);
}
