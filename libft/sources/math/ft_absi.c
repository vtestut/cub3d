/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_absi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 22:03:06 by vtestut           #+#    #+#             */
/*   Updated: 2024/01/16 18:33:12 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

unsigned int	ft_absi(int val)
{
	if (val < 0)
		return (-val);
	else
		return (val);
}
