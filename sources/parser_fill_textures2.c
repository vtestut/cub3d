/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_fill_textures2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 10:27:02 by vtestut           #+#    #+#             */
/*   Updated: 2024/02/13 19:38:54 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	no_digit(char *str)
{
	int		i;
	bool	digit;

	i = 0;
	digit = true;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			digit = false;
		i++;
	}
	return (digit);
}

int	*copy_into_rgb_tab(char **rgb_tab, int *rgb)
{
	int		i;
	int		err;

	i = -1;
	err = 0;
	while (rgb_tab[++i])
	{
		err = ft_atoi_maxint(rgb_tab[i], &rgb[i]);
		if (err != 0)
		{
			ft_free_tab((void **)rgb_tab);
			free(rgb);
			return (0);
		}
	}
	ft_free_tab((void **)rgb_tab);
	return (rgb);
}

int	check_rgb(char **rgb_tab)
{
	int	n;
	int	digit_count;
	int	i;
	int	j;

	i = 0;
	while (rgb_tab && rgb_tab[i])
	{
		digit_count = 0;
		n = ft_strlen(rgb_tab[i]);
		j = 0;
		while (rgb_tab[i] && rgb_tab[i][j])
		{
			if (ft_isdigit(rgb_tab[i][j]))
				digit_count++;
			else if (rgb_tab[i][j] != ' ' && rgb_tab[i][j] != '\n')
				return (0);
			j++;
		}
		if (digit_count < 1 || digit_count > 3)
			return (0);
		i++;
	}
	return (1);
}

int	*set_rgb_colors(char *line)
{
	char	**rgb_tab;
	int		*rgb;
	int		count;

	rgb_tab = ft_split(line, ',');
	count = 0;
	if (check_rgb(rgb_tab) == 0)
	{
		ft_free_tab((void **)rgb_tab);
		return (0);
	}
	while (rgb_tab[count])
		count++;
	if (count != 3)
	{
		ft_free_tab((void **)rgb_tab);
		return (0);
	}
	rgb = malloc(sizeof(int) * 3);
	if (!rgb)
	{
		msg_error("malloc failed", 0);
		return (0);
	}
	return (copy_into_rgb_tab(rgb_tab, rgb));
}

int	get_colors(t_tex *tex, char *line, int j)
{
	if (line[j + 1] && ft_isprint(line[j + 1]))
		return (msg_error("Invalid floor/ceiling color", 2));
	if (!tex->ceiling && line[j] == 'C')
	{
		tex->ceiling = set_rgb_colors(line + j + 1);
		if (tex->ceiling == 0)
			return (msg_error("Invalid ceiling color", 2));
	}
	else if (!tex->floor && line[j] == 'F')
	{
		tex->floor = set_rgb_colors(line + j + 1);
		if (tex->floor == 0)
			return (msg_error("Invalid floor color", 2));
	}
	else
		return (msg_error("Invalid floor/ceiling color", 2));
	return (0);
}
