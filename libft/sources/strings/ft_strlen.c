/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:21:43 by vtestut           #+#    #+#             */
/*   Updated: 2024/01/19 19:05:18 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

// size_t	ft_strlen(const char *str)
// {
// 	size_t	i;

// 	i = 0;
// 	while (*str++)
// 		++i;
// 	return (i);
// }

size_t	ft_strnlen(const char *str, size_t n)
{
	size_t	i;

	i = 0;
	while (n-- && *str++)
		++i;
	return (i);
}
