/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 18:27:58 by vtestut           #+#    #+#             */
/*   Updated: 2024/01/16 19:14:28 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

size_t	ft_countc(const char *str, int c)
{
	size_t	i;
	size_t	count;

	i = ft_strlen(str);
	count = 0;
	while (i--)
		if (c == str[i])
			++count;
	return (count);
}
