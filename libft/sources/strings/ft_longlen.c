/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_longlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:44:45 by vtestut           #+#    #+#             */
/*   Updated: 2024/01/16 17:29:08 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	ft_longlen(unsigned int n)
{
	int	len;

	if (!n)
		return (0);
	len = 0;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}
