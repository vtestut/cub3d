/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digitat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:34:08 by vtestut            #+#    #+#             */
/*   Updated: 2023/06/27 16:03:07 by vtestut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

int	ft_digitat(int val, int *d, int n)
{
	int	i;

	if (n < 0)
		return (0);
	else if (val < 0)
		val *= -1;
	i = 0;
	while (i < n)
	{
		val /= 10;
		++i;
	}
	if (d)
		*d = val % 10;
	return (val % 10);
}
