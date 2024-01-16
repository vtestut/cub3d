/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 23:31:43 by vtestut            #+#    #+#             */
/*   Updated: 2023/05/08 16:36:54 by vtestut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strdup(const char *str)
{
	char	*new;
	size_t	i;

	i = ft_strlen(str);
	new = malloc(i + 1);
	if (!new)
		return (NULL);
	ft_memcpy(new, str, i);
	new[i] = 0;
	return (new);
}

char	*ft_strndup(const char *str, size_t n)
{
	char	*new;
	size_t	i;

	i = ft_strlen(str);
	if (n < i)
		i = n;
	new = malloc(i + 1);
	if (!new)
		return (NULL);
	ft_memcpy(new, str, i);
	new[i] = 0;
	return (new);
}
