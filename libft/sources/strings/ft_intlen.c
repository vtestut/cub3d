/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:42:22 by vtestut           #+#    #+#             */
/*   Updated: 2024/01/16 17:27:14 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	ft_intlen(int n)
{
	int	len;
	int	sign;

	if (!n)
		return (0);
	sign = 0;
	if (n < 0)
		sign = 1;
	len = 0;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len + sign);
}
