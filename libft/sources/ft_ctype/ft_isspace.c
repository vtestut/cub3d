/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 19:27:36 by vtestut          #+#    #+#             */
/*   Updated: 2023/08/01 19:31:56 by vtestut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctype.h"
#include "ft_string.h"

int	ft_isspace(int c)
{
	static const char	*spaces = "\t\n\v\f\r ";

	return (ft_strchr(spaces, c) != NULL);
}
