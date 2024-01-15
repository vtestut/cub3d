/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 17:30:54 by vtestut          #+#    #+#             */
/*   Updated: 2023/06/30 17:30:54 by vtestut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strreplace(const char *str, const char *begin,
			const char *end, const char *what)
{
	char	*new;
	char	*tmp;

	tmp = ft_strremove(str, begin, end);
	if (!tmp)
		return (NULL);
	new = ft_strinsert(tmp, tmp + (begin - str), what);
	if (!new)
		return (free(tmp), NULL);
	free(tmp);
	return (new);
}
