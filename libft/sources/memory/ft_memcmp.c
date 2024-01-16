/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:46:37 by virgile           #+#    #+#             */
/*   Updated: 2024/01/16 18:44:49 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	int		comp;

	i = 0;
	while (i < n)
	{
		comp = *(unsigned char *)s1++ - *(unsigned char *)s2++;
		i++;
		if (comp)
			return (comp);
	}
	return (0);
}
