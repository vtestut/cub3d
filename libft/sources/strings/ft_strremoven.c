/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strremoven.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:44:11 by vtestut          #+#    #+#             */
/*   Updated: 2023/11/28 14:44:40 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strremoven(const char *src, size_t begin, size_t n)
{
	char	*new;
	size_t	srclen;

	srclen = ft_strlen(src);
	new = malloc(srclen - n + 1);
	if (!new)
		return (NULL);
	ft_memcpy(new, src, begin);
	if (begin + n < srclen)
		ft_memcpy(new + begin, src + begin + n, srclen - begin - n);
	new[srclen - n] = '\0';
	return (new);
}
