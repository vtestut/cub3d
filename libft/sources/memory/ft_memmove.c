/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:07:57 by vtestut            #+#    #+#             */
/*   Updated: 2023/07/09 04:39:54 by vtestut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*buff;

	buff = malloc(n);
	if (!buff)
		return (NULL);
	ft_memcpy(buff, src, n);
	ft_memcpy(dest, buff, n);
	free(buff);
	return (dest);
}
