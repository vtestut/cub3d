/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 21:36:24 by vtestut           #+#    #+#             */
/*   Updated: 2024/01/16 19:38:01 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strchr(const char *str, int c)
{
	size_t	i;

	i = ft_strlen(str);
	while (i-- && *str != c)
		++str;
	if (*str == c)
		return ((char *)str);
	return (NULL);
}
