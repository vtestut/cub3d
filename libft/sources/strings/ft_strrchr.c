/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:38:30 by vtestut           #+#    #+#             */
/*   Updated: 2024/01/22 13:22:53 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*temp;
	char	t;

	temp = NULL;
	t = (char) c;
	while (*s != '\0')
	{
		if (*s == t)
			temp = (char *)s;
		s++;
	}
	if (t == '\0')
		temp = (char *)s;
	return (temp);
}
