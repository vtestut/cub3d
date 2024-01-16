/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:59:54 by vtestut          #+#    #+#             */
/*   Updated: 2023/10/12 17:58:56 by vtestut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"
#include "ft_string.h"

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*new_ptr;

	if (!ptr)
	{
		new_ptr = malloc(new_size);
		if (!new_ptr)
			return (NULL);
		ft_memset(new_ptr, 0, new_size);
		return (new_ptr);
	}
	else if (!new_size)
		return (free(ptr), NULL);
	new_ptr = malloc(new_size);
	if (!new_ptr)
		return (free(ptr), NULL);
	if (new_size < old_size)
		ft_memcpy(new_ptr, ptr, new_size);
	else
	{
		ft_memcpy(new_ptr, ptr, old_size);
		ft_memset(new_ptr + old_size, 0, new_size - old_size);
	}
	free(ptr);
	return (new_ptr);
}
