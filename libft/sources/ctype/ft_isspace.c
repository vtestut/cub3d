/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 19:27:36 by vtestut          #+#    #+#             */
/*   Updated: 2024/08/01 19:31:56 by vtestut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <ctype.h>
// #include <stdio.h>
#include "ft_ctype.h"

int	ft_isspace(char c)
{

	// if (c != ' ' && c != '\t' && c != '\r'
	// 	&& c != '\n' && c != '\v' && c != '\f')
	// 	return (1);
	// else
	// 	return (0);
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}

// int main()
// {
// 	printf("%d  %d\n", ft_isspace('0'), isspace('0'));
// }
