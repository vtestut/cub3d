/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:50:29 by vtestut           #+#    #+#             */
/*   Updated: 2024/02/11 16:21:47 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctype.h"

// modified to include the space character for cub3d. 32 instead of 33
int	ft_isprint(int c)
{
	if (c >= 33 && c <= 126)
		return (1);
	return (0);
}
