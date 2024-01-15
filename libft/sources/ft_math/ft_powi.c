/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_powi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 20:31:10 by vtestut            #+#    #+#             */
/*   Updated: 2023/07/10 01:51:53 by vtestut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

int	ft_powi(int base, int power)
{
	int	ret;

	if (!base)
		return (0);
	else if (power == 0)
		return (1);
	ret = base;
	while (--power)
		ret *= base;
	return (ret);
}
