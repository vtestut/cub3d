/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:21:53 by vtestut           #+#    #+#             */
/*   Updated: 2024/01/30 11:50:51 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = n / sizeof(u_int64_t);
	while (i--)
		*((u_int64_t *)dest + i) = *((const u_int64_t *)src + i);
	i = n % sizeof(u_int64_t);
	while (i--)
		*((u_int8_t *)dest + n - i - 1) = *((const u_int8_t *)src + n - i - 1);
	return (dest);
}
