/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:35:38 by vtestut           #+#    #+#             */
/*   Updated: 2024/01/23 11:17:29 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_free_arr(void **array)
{
	int	i;

	i = 0;
	while (array && array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	ft_free_texture(t_map *data)
{
	free(data->north_txt);
	free(data->south_txt);
	free(data->east_txt);
	free(data->west_txt);
}