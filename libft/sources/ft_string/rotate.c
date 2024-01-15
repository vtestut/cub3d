/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 20:15:10 by vtestut            #+#    #+#             */
/*   Updated: 2023/05/17 23:03:56 by vtestut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_math.h"

static void	r_clock(void *arr, int direction, size_t nelem, size_t size)
{
	char	*tmp;
	void	*juncture;

	tmp = malloc(size * direction);
	if (!tmp)
		return ;
	juncture = arr + (nelem - direction) * size;
	ft_memcpy(tmp, juncture, direction * size);
	ft_memmove(arr + direction * size, arr, (nelem - direction) * size);
	ft_memcpy(arr, tmp, direction * size);
	free(tmp);
}

static void	r_rclock(void *arr, int direction, size_t nelem, size_t size)
{
	char	*tmp;

	tmp = malloc(size * direction);
	if (!tmp)
		return ;
	ft_memcpy(tmp, arr, direction * size);
	ft_memmove(arr, arr + direction * size, (nelem - direction) * size);
	ft_memcpy(arr + (nelem - direction) * size, tmp, direction * size);
	free(tmp);
}

void	rotate(void *arr, int direction, size_t n, size_t size)
{
	int	dir;

	dir = direction % (int)n;
	if (ft_absi(dir) > n / 2)
	{
		if (direction < 0)
			r_clock(arr, (int)n + dir, n, size);
		else
			r_rclock(arr, (int)n - dir, n, size);
	}
	else if (dir < 0)
		r_rclock(arr, (int)ft_absi(dir), n, size);
	else
		r_clock(arr, dir, n, size);
}
