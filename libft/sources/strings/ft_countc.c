/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:27:58 by vtestut           #+#    #+#             */
/*   Updated: 2024/01/30 11:50:51 by vtestut          ###   ########.fr       */
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
