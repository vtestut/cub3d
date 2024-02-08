/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 20:53:08 by vtestut           #+#    #+#             */
/*   Updated: 2024/01/30 11:50:51 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

// void	ft_bzero(void *s, size_t n)
// {
// 	unsigned char	*p;

// 	p = (unsigned char *)s;
// 	while (n != 0)
// 	{
// 		*p = '\0';
// 		p++;
// 		n--;
// 	}
// }

void	ft_bzero(void *s, size_t n)
{
	size_t	cnt;
	char	*str;

	str = (char *) s;
	cnt = 0;
	while (cnt < n)
	{
		str[cnt] = 0;
		cnt++;
	}
	s = (void *) str;
}

//GPT
// void	ft_bzero(void *s, size_t n)
// {
// 	size_t	cnt;
// 	char	*str;

// 	str = (char *) s;
// 	cnt = 0;
// 	while (cnt < n)
// 	{
// 		str[cnt] = 0;
// 		cnt++;
// 	}
// }
