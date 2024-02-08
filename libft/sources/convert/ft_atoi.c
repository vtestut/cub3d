/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 20:57:30 by vtestut           #+#    #+#             */
/*   Updated: 2024/01/30 11:50:51 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_convert.h"

int	ft_atoi(const char *nptr)
{
	long	nb;
	int		sig;

	sig = 1;
	nb = 0;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == ' ')
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sig *= -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		nb = nb * 10 + (*nptr++ - '0') * sig;
		if (nb > INT_MAX)
			return (-1);
		if (nb < INT_MIN)
			return (0);
	}
	return (nb);
}

// int	ft_atoi(char *str)
// {
// 	long	val;
// 	char	*_restrict;

// 	val = ft_strtol(str, &_restrict, 10);
// 	if (_restrict != str + ft_strlen(str))
// 		return (0);
// 	return ((int)val);
// }
