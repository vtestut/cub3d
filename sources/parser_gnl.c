/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:52:54 by vtestut           #+#    #+#             */
/*   Updated: 2024/02/12 13:58:14 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	count_lines(char *path)
{
	int		fd;
	char	*line;
	int		nb_line;

	nb_line = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		msg_error("open failed", 1);
	else
	{
		line = get_next_line(fd);
		while (line != NULL)
		{
			nb_line++;
			free(line);
			line = get_next_line(fd);
		}
		close(fd);
	}
	return (nb_line);
}

void	fill_map_gnl(int row, int col, int i, t_game *game)
{
	char	*line;

	line = get_next_line(game->fd);
	while (line != NULL)
	{
		game->file[row] = ft_calloc(ft_strlen(line) + 1, sizeof(char));
		if (!game->file[row])
		{
			msg_error("malloc failed", 0);
			return (ft_free_tab((void **)game->file));
		}
		while (line[i] != '\0')
			game->file[row][col++] = line[i++];
		game->file[row++][col] = '\0';
		col = 0;
		i = 0;
		free(line);
		line = get_next_line(game->fd);
	}
	game->file[row] = NULL;
}

void	start_fill_map(char *path, t_game *game)
{
	int		row;
	int		i;
	size_t	col;

	i = 0;
	row = 0;
	col = 0;
	game->nb_line = count_lines(path);
	game->path = path;
	game->file = ft_calloc(game->nb_line + 1, sizeof(char *));
	if (game->file == NULL)
	{
		msg_error("malloc failed", 0);
		return ;
	}
	game->fd = open(path, O_RDONLY);
	if (game->fd < 0)
		msg_error("open failed", 1);
	else
	{
		fill_map_gnl(row, col, i, game);
		close(game->fd);
	}
}
