/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 20:54:15 by vtestut           #+#    #+#             */
/*   Updated: 2024/01/16 18:48:05 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*r;

	r = malloc(nmemb * size);
	if (!r)
		return (NULL);
	ft_bzero(r, size * nmemb);
	return (r);
}
