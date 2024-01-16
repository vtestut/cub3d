/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 20:57:30 by vtestut           #+#    #+#             */
/*   Updated: 2024/01/16 18:59:55 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_convert.h"

int	ft_atoi(char *str)
{
	long	val;
	char	*_restrict;

	val = ft_strtol(str, &_restrict, 10);
	if (_restrict != str + ft_strlen(str))
		return (0);
	return ((int)val);
}
