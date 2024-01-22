/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:21:43 by vtestut           #+#    #+#             */
/*   Updated: 2024/01/20 14:05:21 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (*str++)
		++i;
	return (i);
}

size_t	ft_strnlen(const char *str, size_t n)
{
	size_t	i;

	i = 0;
	while (n-- && *str++)
		++i;
	return (i);
}
