/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_02.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:52:54 by vtestut           #+#    #+#             */
/*   Updated: 2024/02/11 17:13:39 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// get the number of lines in the map file.
int	count_lines(char *path)
{
	int		fd;
	char	*line;
	int		n_line;

	n_line = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		err_msg("can't open file", 1);
	else
	{
		line = get_next_line(fd);
		while (line != NULL)
		{
			n_line++;
			free(line);
			line = get_next_line(fd);
		}
		close(fd);
	}
	return (n_line);
}

// parse the map file and fill the game structure with the map data.
void	start_parse(char *path, t_game *game)
{
	int		row;
	int		i;
	size_t	col;

	i = 0;
	row = 0;
	col = 0;
	game->n_line = count_lines(path);
	game->path = path;
	game->file = ft_calloc(game->n_line + 1, sizeof(char *));
	if (game->file == NULL)
	{
		err_msg("malloc error at start parse", 0);
		return ;
	}
	game->fd = open(path, O_RDONLY);
	if (game->fd < 0)
		err_msg("can't open file", 1);
	else
	{
		fill_map(row, col, i, game);
		close(game->fd);
	}
}

// checks if the arg is a .xpm file.
bool	is_xpm_file(char *arg)
{
	size_t	len;

	len = ft_strlen(arg);
	if ((arg[len - 3] != 'x' || arg[len - 2] != 'p'
			|| arg[len - 1] != 'm'
			|| arg[len - 4] != '.'))
		return (false);
	return (true);
}

// checks if the arg has the correct format.
bool	check_format(char *argv)
{
	int	i;

	i = ft_strlen(argv) - 1;
	if ((argv[i] != 'b' || argv[i - 1] != 'u' || \
	argv[i - 2] != 'c' || argv[i - 3] != '.'))
		return (1);
	return (0);
}

// checks if the arg is a directory.
bool	check_if_directory(char *arg)
{
	int		fd;
	bool	ret;

	ret = false;
	fd = open(arg, O_DIRECTORY);
	if (fd >= 0)
	{
		close (fd);
		ret = true;
	}
	return (ret);
}
