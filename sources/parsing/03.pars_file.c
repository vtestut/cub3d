/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03.pars_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:05:15 by vtestut           #+#    #+#             */
/*   Updated: 2024/01/23 16:21:31 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_fill_map(t_map *data, char *file)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	data->map = ft_split(file + data->map_index, '\n');
	data->map_max_x = ft_strlen(data->map[i]);
	while (data->map[i])
	{
		if (ft_strlen(data->map[i]) > data->map_max_x)
			data->map_max_x = ft_strlen(data->map[i]);
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'N' || data->map[i][j] == 'W' || \
			data->map[i][j] == 'E' || data->map[i][j] == 'S')
			{
				data->pos_player_x = j;
				data->pos_player_y = i;
			}
			j++;
		}
		j = 0;
		i++;
	}
	data->map_max_y = i;
}

char	*ft_get_file(char *arg)
{
	int		fd;
	char	*file;
	char	*line;
	char	*tmp;

	fd = open(arg, O_RDONLY, 0644);
	file = get_next_line(fd);
	if (!file)
		return (NULL);
	while (true)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		tmp = ft_strdup(file);
		free(file);
		file = ft_strjoin(tmp, line);
		free(tmp);
		free(line);
	}
	close(fd);
	return (file);
}

int	ft_check_file(char **argv, t_map *data, t_parse *parse)
{
	char	*file;

	file = ft_get_file(argv[1]);
	if (!file)
	{
		ft_putstr_fd("Error\nFile is empty\n", 2);
		return (-1);
	}
	if (ft_check_file_data(data, file, parse))
	{
		ft_putstr_fd("Error\nProblem with files's map\n", 2);
		ft_free_texture(data);
		free(file);
		return (-1);
	}
	if (ft_check_map(data, file))
	{
		ft_putstr_fd("Error\nProblem with file's map\n", 2);
		ft_free_texture(data);
		free(file);
		return (-1);
	}
	ft_fill_map(data, file);
	free(file);
	return (0);
}
