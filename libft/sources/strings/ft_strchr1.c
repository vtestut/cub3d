/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 01:51:36 by vtestut          #+#    #+#             */
/*   Updated: 2023/07/10 01:51:39 by vtestut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strchr1(const char *str, const char *charset)
{
	while (*str)
	{
		if (ft_strchr(charset, *str))
			return ((char *)str);
		++str;
	}
	return (NULL);
}
