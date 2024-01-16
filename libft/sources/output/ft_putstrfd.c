/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrfd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 00:15:52 by vtestut           #+#    #+#             */
/*   Updated: 2024/01/15 17:31:48 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

void	ft_putstrfd(const char *str, int fd)
{
	if (!write(fd, NULL, 0))
		write(fd, str, ft_strlen(str));
}
