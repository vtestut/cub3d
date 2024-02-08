/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_one.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:54:55 by vtestut           #+#    #+#             */
/*   Updated: 2024/01/30 11:50:51 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	ft_strtrim_one(char *str, const char *set)
{
	char	*iter;
	char	charset[2];

	charset[1] = 0;
	iter = ft_strchr1(str, set);
	if (iter)
	{
		charset[0] = *iter;
		return (ft_strtrim(str, charset));
	}
	return (0);
}
