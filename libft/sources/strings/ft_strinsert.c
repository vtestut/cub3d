/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 17:30:57 by vtestut          #+#    #+#             */
/*   Updated: 2023/11/11 19:36:15 by vtestut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strinsert(const char *str, const char *begin, const char *what)
{
	size_t	strlen;
	size_t	wlen;
	size_t	offset;
	char	*new;

	strlen = ft_strlen(str);
	wlen = ft_strlen(what);
	offset = begin - str;
	new = malloc(strlen + wlen + 1);
	if (!new)
		return (NULL);
	ft_memcpy(new, str, offset);
	ft_memcpy(new + offset, what, wlen);
	if (begin < str + ft_strlen(str))
		ft_memcpy(new + offset + wlen, begin, ft_strlen(begin));
	new[strlen + wlen] = 0;
	return (new);
}
