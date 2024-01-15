/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:21:47 by vtestut            #+#    #+#             */
/*   Updated: 2023/05/08 16:36:37 by vtestut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

void	*ft_memset(void *dest, int c, size_t n)
{
	size_t		i;
	u_int64_t	v64;

	v64 = 0x0101010101010101 * (u_int8_t)c;
	i = n / sizeof(u_int64_t);
	while (i--)
		*((u_int64_t *)dest + i) = v64;
	i = n % (sizeof(u_int64_t));
	while (i--)
		*((u_int8_t *)dest + n - 1 - i) = (u_int8_t)c;
	return (dest);
}
