/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 23:31:43 by vtestut           #+#    #+#             */
/*   Updated: 2024/01/16 19:26:47 by vtestut          ###   ########.fr       */
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
