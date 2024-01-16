/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_one.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:54:55 by vtestut            #+#    #+#             */
/*   Updated: 2023/12/09 20:26:22 by vtestut         ###   ########.fr       */
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
