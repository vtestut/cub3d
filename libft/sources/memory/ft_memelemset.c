/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memelemset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:42:23 by vtestut           #+#    #+#             */
/*   Updated: 2024/01/30 11:50:51 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

void	*ft_memelemset(void *dest, void *src, size_t srclen, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)dest)[i] = ((char *)src)[i % srclen];
		++i;
	}
	return (dest);
}
