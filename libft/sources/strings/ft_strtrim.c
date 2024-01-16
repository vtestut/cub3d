/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:23:11 by vtestut            #+#    #+#             */
/*   Updated: 2023/12/09 13:41:05 by vtestut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	ft_strtrim(char *str, const char *set)
{
	char	*iter;
	int		removed;
	size_t	n;

	iter = str;
	while (*iter && ft_strchr(set, *iter))
		iter++;
	n = ft_strlen(iter);
	removed = iter - str;
	ft_memmove(str, iter, n + 1);
	if (!n)
		return (removed);
	iter = str + ft_strlen(str) - 1;
	while (*iter && ft_strchr(set, *iter))
	{
		*iter = '\0';
		iter--;
	}
	removed += ft_strlen(iter);
	ft_memset(iter + 1, '\0', ft_strlen(iter + 1));
	return (removed);
}
