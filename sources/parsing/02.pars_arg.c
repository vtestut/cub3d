/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02.pars_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:01:39 by vtestut           #+#    #+#             */
/*   Updated: 2024/01/19 17:06:10 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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
		ft_putstr_fd("Error\nusage: ./cub3d path/to/map.cub\n", 2);
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