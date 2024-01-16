/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 23:26:55 by vtestut           #+#    #+#             */
/*   Updated: 2024/01/16 19:38:27 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	**ft_split(const char *str, int c)
{
	char	charset[2];

	charset[0] = c;
	charset[1] = 0;
	return (ft_splitcs(str, charset));
}
