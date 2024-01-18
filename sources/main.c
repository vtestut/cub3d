/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:58:34 by vtestut           #+#    #+#             */
/*   Updated: 2024/01/18 18:57:40 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../libft/includes/libft.h"

void	ft_init_data(t_map_data *data) //static ?
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
	data->pos_player_x = 0; // TODO
	data->pos_player_y = 0; // TODO
	data->map_index = 0;
	data->map_max_x = 0;
	data->map_max_y = 0;
	data->map = NULL;
}

static void ft_init_parse(t_parse *parse)
{
	parse->valid_north = 0;
	parse->valid_south = 0;
	parse->valid_east = 0;
	parse->valid_west = 0;
	parse->valid_floor = 0;
	parse->valid_ceil = 0;
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

int ft_check_arg(int argc, char **argv)
{
	int	fd;

	if (argc != 2 || !argv[1][0])
	{
		ft_putstr_fd("Error\nusage: ./cub3d path/to/map.cub\n", 2); //TODO
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
			break;
		tmp = ft_strdup(file);
		free(file);
		file = ft_strjoin(tmp, line);
		free(tmp);
		free(line);
	}
	close(fd);
	return (file);
}

int	ft_manage_north_loop(t_map_data *data, char *file_data, int i, int len)
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

int	ft_manage_north(t_map_data *data, char *file_data, int i, t_parse *parse)
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

int	ft_manage_east_loop(t_map_data *data, char *file_data, int i, int len)
{
	while (file_data[i] && file_data[i] != '\n')
	{
		len++;
		i++;
	}
	data->east_txt = ft_calloc(sizeof(char), len + 1);
	i -= len;
	len = 0;
	while (file_data[i] && file_data[i] != '\n')
	{
		data->east_txt[len] = file_data[i];
		i++;
		len++;
	}
	return (i);
}

int	ft_manage_east(t_map_data *data, char *file_data, int i, t_parse *parse)
{
	int	len;

	len = 0;
	if (i == 0)
		i += 2;
	else
		i += 3;
	while (file_data && file_data[i] != ' ')
		i++;
	if (parse->valid_east == 1)
		return (-1);
	i = ft_manage_east_loop(data, file_data, i, len);
	parse->valid_east = 1;
	return (i - 1);	
}

int	ft_manage_west_loop(t_map_data *data, char *file_data, int i, int len)
{
	while (file_data[i] && file_data[i] != '\n')
	{
		len++;
		i++;
	}
	data->west_txt = ft_calloc(sizeof(char), len + 1);
	i -= len;
	len = 0;
	while (file_data[i] && file_data[i] != '\n')
	{
		data->west_txt[len] = file_data[i];
		i++;
		len++;
	}
	return (i);
}

int	ft_manage_west(t_map_data *data, char *file_data, int i, t_parse *parse)
{
	int	len;

	len = 0;
	if (i == 0)
		i += 2;
	else
		i += 3;
	while (file_data[i] && file_data[i] != ' ')
		i++;
	if (parse->valid_west == 1)
		return (-1);
	i = ft_manage_west_loop(data, file_data, i, len);
	parse->valid_west = 1;
	return (i - 1);
}

int	ft_manage_south_loop(t_map_data *data, char *file_data, int i, int len)
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

int	ft_manage_south(t_map_data *data, char *file_data, int i, t_parse *parse)
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

int	ft_check_id_nb(char *file_data, int i)
{
	int	values[3];
	int	cur_value;

	values[0] = 0;
	values[1] = 0;
	values[2] = 0;
	cur_value = 0;
	while (file_data[i] && file_data[i] != '\n')
	{
		if (file_data[i] >= '0' && file_data[i] <= '9')
			values[cur_value] = values[cur_value] * 10 + (file_data[i] - '0');
		else if (file_data[i] == ',')
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

int	ft_get_rgb_value_ceil(t_map_data *data, char *file, int i, t_parse *parse)
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

int	ft_manage_ceiling(t_map_data *data, char *file_data, int i, t_parse *parse)
{
	int	stock;

	i += 2;
	while (file_data[i] && file_data[i] == ' ')
		i++;
	if (file_data[i] == '\n')
		return (-1);
	stock = i;
	i = ft_check_id_nb(file_data, i);
	if (i == -1)
		return (-1);
	if (ft_get_rgb_value_ceil(data, file_data, stock, parse) == -1)
		return (-1);
	return (i - 1);
}

int	ft_get_rgb_value_floor(t_map_data *data, char *file, int i, t_parse *parse)
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

int	ft_manage_floor(t_map_data *data, char *file_data, int i, t_parse *parse)
{
	int	stock;

	i += 2;
	while (file_data[i] && file_data[i] == ' ')
		i++;
	if (file_data[i] == '\n')
		return (-1);
	stock = i;
	i = ft_check_id_nb(file_data, i);
	if (i == -1)
		return (-1);
	if (ft_get_rgb_value_floor(data, file_data, stock, parse) == -1)
		return (-1);
	return (i - 1);
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
	}
}

int	ft_check_file(char **argv, t_map_data *data, t_parse *parse)
{
	char	*file_data;
	
	file_data = ft_get_file(argv[1]);
	if (!file_data)
	{
		ft_putstr_fd("Error\nFile is empty\n", 2);
		return (-1);
	}
	if (ft_check_file_data(data, file_data, parse))
	{
		
	}
	return (0);
}

int	ft_start(int argc, char **argv, t_map_data *data, t_parse *parse)
{
	(void) data;
	(void) parse;
	ft_check_arg(argc, argv);
	if (ft_check_file(argv, data, parse) == -1)
		return (-1);
	return (0);
}

void	map_parsing(int argc, char **argv, t_game *game)
{
	t_parse	parse;
	
	ft_init_parse(&parse);
	ft_init_data(&game->data);
	ft_start(argc, argv, &game->data, &parse);
}


















int main(int argc, char **argv)
{
	t_game	game;
	
	map_parsing(argc, argv, &game);
	return 0;
}