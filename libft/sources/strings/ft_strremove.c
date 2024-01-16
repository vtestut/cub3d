/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strremove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 17:19:55 by vtestut          #+#    #+#             */
/*   Updated: 2023/11/11 19:43:57 by vtestut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strremove(const char *str, const char *begin, const char *end)
{
	size_t	nstr;
	size_t	ndel;
	char	*new;

	nstr = ft_strlen(str);
	if (!end)
		ndel = ft_strlen(begin);
	else
		ndel = end - begin;
	new = malloc(nstr - ndel + 1);
	if (!new)
		return (NULL);
	ft_memcpy(new, str, begin - str);
	ft_memcpy(new + (begin - str), end, ft_strlen(end));
	new[nstr - ndel] = 0;
	return (new);
}
