/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:28:08 by vtestut           #+#    #+#             */
/*   Updated: 2024/01/16 18:45:12 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

void	*ft_memdup(void *src, size_t n)
{
	void	*dst;

	dst = malloc(n);
	if (!dst)
		return (NULL);
	ft_memcpy(dst, src, n);
	return (dst);
}
