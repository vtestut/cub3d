/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 18:27:58 by vtestut            #+#    #+#             */
/*   Updated: 2023/05/08 16:36:19 by vtestut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

size_t	ft_countc(const char *str, int c)
{
	size_t	i;
	size_t	count;

	i = ft_strlen(str);
	count = 0;
	while (i--)
		if (c == str[i])
			++count;
	return (count);
}

size_t	ft_countcs(const char *str, const char *charset)
{
	size_t	i;
	size_t	count;

	i = ft_strlen(charset);
	count = 0;
	while (i--)
		count += ft_countc(str, charset[i]);
	return (count);
}
