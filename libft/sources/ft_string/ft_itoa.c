/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:45:20 by vtestut          #+#    #+#             */
/*   Updated: 2023/07/26 14:45:20 by vtestut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <pthread.h>

char	*ft_itoa(int64_t val)
{
	static __thread char	buff[21] = {0};
	size_t					i;
	char					c;
	int						neg;

	ft_memset(&buff, 0, 21);
	i = 19;
	if (!val)
	{
		buff[i] = '0';
		return (buff + i);
	}
	neg = val < 1;
	while (val)
	{
		c = (char)(val % 10);
		buff[i--] = c + 48;
		val /= 10;
	}
	if (neg)
		buff[i] = '-';
	else
		i++;
	return (buff + i);
}
