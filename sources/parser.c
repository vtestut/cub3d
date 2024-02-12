/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:47:11 by vtestut           #+#    #+#             */
/*   Updated: 2024/02/12 13:53:36 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_xpm_file(char *argv)
{
	int	i;

	i = ft_strlen(argv) - 1;
	if ((argv[i] != 'm' || argv[i - 1] != 'p' || argv[i - 2] != 'x'
			|| argv[i - 3] != '.'))
		return (0);
	return (1);
}

int	check_format(char *argv)
{
	int	i;

	i = ft_strlen(argv) - 1;
	if ((argv[i] != 'b' || argv[i - 1] != 'u' || argv[i - 2] != 'c'
			|| argv[i - 3] != '.'))
		return (1);
	return (0);
}

int	is_directory(char *argv)
{
	int		fd;
	bool	ret;

	ret = 0;
	fd = open(argv, O_DIRECTORY);
	if (fd >= 0)
	{
		close (fd);
		ret = 1;
	}
	return (ret);
}

int	check_arg(char *arg, bool cub)
{
	int	fd;

	if (is_directory(arg))
		return (msg_error("map file is a directory", 1));
	fd = open(arg, O_RDONLY);
	if (fd == -1)
		return (msg_error("can't open map file", 1));
	close(fd);
	if (cub && check_format(arg))
		return (msg_error("map file must be in .cub format", 1));
	if (!cub && !is_xpm_file(arg))
		return (msg_error("not an .xpm file", 1));
	return (0);
}

int	parser(t_game *game, char **argv)
{
	init_game(game);
	init_data(&game->tex);
	init_player(&game->player);
	if (check_arg(argv[1], true))
		exit_free(game, 1);
	start_fill_map(argv[1], game);
	if (parse_file(game, game->file) == 1)
		return (free_game(game));
	if (check_map(game, game->map) == 1)
		return (free_game(game));
	if (check_textures(&game->tex) == 1)
		return (free_game(game));
	init_player_dir(game);
	return (0);
}
