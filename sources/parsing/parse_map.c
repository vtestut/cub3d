/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:07:33 by vtestut           #+#    #+#             */
/*   Updated: 2024/01/23 12:49:13 by vtestut          ###   ########.fr       */
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

int	ft_manage_north_loop(t_map *data, char *file, int i, int len)
{
	while (file[i] && file[i] != '\n')
	{
		len++;
		i++;
	}
	data->north_txt = ft_calloc(sizeof(char), len + 1);
	i -= len;
	len = 0;
	while (file[i] && file[i] != '\n')
	{
		data->north_txt[len] = file[i];
		i++;
		len++;
	}
	return (i);
}

int	ft_manage_north(t_map *data, char *file, int i, t_parse *parse)
{
	int	len;

	len = 0;
	if (i == 0)
		i += 2;
	else
		i += 3;
	while (file[i] && file[i] == ' ')
		i++;
	if (parse->valid_north == 1)
		return (-1);
	i = ft_manage_north_loop(data, file, i, len);
	parse->valid_north = 1;
	return (i - 1);
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

int	ft_check_file(t_map *data, char *file, t_parse *parse)
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
	if (ft_check_file(data, file, parse))
	{
		ft_putstr_fd("Error\nProblem with files's map\n", 2);
		ft_free_texture(data);
		free(file);
		return (-1);
	}
	return (1);
}

int	ft_check_format(char *argv)
{
	int	i;

	i = ft_strlen(argv) - 1;
	if ((argv[i] != 'b' || argv[i - 1] != 'u' || \
	argv[i - 2] != 'c' || argv[i - 3] != '.'))
	{
		ft_putstr_fd("Error\nMap file must be in .cub format\n", 2);
		exit (1);
	}
	return (0);
}

int	ft_check_arg(int argc, char **argv)
{
	int	fd;

	if (argc != 2 || !argv[1][0])
	{
		ft_putstr_fd("Error\nExec with: ./cub3d path/to/map.cub\n", 2);
		exit(1);
	}
	ft_check_format(argv[1]);
	fd = open(argv[1], O_RDONLY | __O_DIRECTORY, 0644);
	if (fd > 0)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd(argv[1], 2);
		ft_putstr_fd(": is a directory\n", 2);
	}
	fd = open(argv[1], O_RDONLY, 0644);
	if (fd < 0)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd(argv[1], 2);
		perror(" ");
		exit (1);
	}
	close(fd);
	return (0);
}

int	ft_start(int argc, char **argv, t_map *data, t_parse *parse)
{
	ft_check_arg(argc, argv);
	if (ft_check_file(argv, data, parse) == -1)
		return (-1);
	return (0);
}

static void	ft_init_parse(t_parse *parse)
{
	parse->valid_north = 0;
	parse->valid_south = 0;
	parse->valid_east = 0;
	parse->valid_west = 0;
	parse->valid_floor = 0;
	parse->valid_ceil = 0;
}

void	ft_init_data(t_map *data)
{
	data->north_txt = NULL;
	data->south_txt = NULL;
	data->east_txt = NULL;
	data->west_txt = NULL;
	data->floor_color[0] = 0;
	data->floor_color[1] = 0;
	data->floor_color[2] = 0;
	data->ceil_color[0] = 0;
	data->ceil_color[1] = 0;
	data->ceil_color[2] = 0;
	data->pos_player_x = 0;
	data->pos_player_y = 0;
	data->map_index = 0;
	data->map_max_x = 0;
	data->map_max_y = 0;
	data->map = NULL;
}

void	map_parsing(int argc, char **argv, t_game *game)
{
	t_parse	parse;

	ft_init_parse(&parse);
	ft_init_data(&game->data);
	ft_start(argc, argv, &game->data, &parse);
}

int	main(int argc, char **argv)
{
	t_game	game;

	map_parsing(argc, argv, &game);
	return (0);
}
