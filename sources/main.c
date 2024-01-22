/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:58:34 by vtestut           #+#    #+#             */
/*   Updated: 2024/01/22 18:09:12 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../libft/includes/libft.h"

int	main(int argc, char **argv)
{
	t_game	game;

	map_parsing(argc, argv, &game);
	
	return (0);
}
