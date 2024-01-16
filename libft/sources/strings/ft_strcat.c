/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:48:58 by vtestut            #+#    #+#             */
/*   Updated: 2023/05/08 16:36:41 by vtestut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strcat(const char *s1, const char *s2)
{
	size_t	n1;
	size_t	n2;
	char	*new;

	if (!s1)
		n1 = 0;
	else
		n1 = ft_strlen(s1);
	if (!s2)
		n2 = 0;
	else
		n2 = ft_strlen(s2);
	new = malloc(n1 + n2 + 1);
	if (!new)
		return (NULL);
	new[n1 + n2] = 0;
	ft_memcpy(new, s1, n1);
	ft_memcpy(new + n1, s2, n2);
	return (new);
}
