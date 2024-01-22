/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 20:53:28 by vtestut           #+#    #+#             */
/*   Updated: 2024/01/20 14:11:20 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_substr(char const *s, unsigned int start, int len)
{
	char	*res;
	char	*src;
	int		reslen;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < (int)start)
		return (ft_strdup(""));
	src = (char *)s + start;
	if (ft_strlen(src) < len)
		reslen = ft_strlen(src) + 1;
	else
		reslen = len + 1;
	res = malloc(reslen * sizeof(char));
	if (!res)
		return (NULL);
	ft_strlcpy(res, src, reslen);
	return (res);
}
