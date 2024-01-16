/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplacen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:25:08 by vtestut          #+#    #+#             */
/*   Updated: 2023/11/13 19:25:10 by vtestut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strreplacen(const char *src, size_t begin,
			size_t n, const char *what)
{
	char	*new;
	char	*tmp;

	tmp = ft_strremoven(src, begin, n);
	if (!tmp)
		return (NULL);
	new = ft_strinsertn(tmp, begin, what);
	if (!new)
		return (free(tmp), NULL);
	free(tmp);
	return (new);
}
