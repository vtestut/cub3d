/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 20:22:26 by vtestut            #+#    #+#             */
/*   Updated: 2023/07/26 14:44:36 by vtestut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"
#include "ft_string.h"
#include "ft_math.h"
#include <limits.h>

static const char	*g_base_8 = "01234567";
static const char	*g_base_10 = "0123456789";
static const char	*g_base_16 = "0123456789abcdef";

static char	*set_base(int base)
{
	if (base == 8)
		return ((char *)g_base_8);
	else if (base == 10)
		return ((char *)g_base_10);
	else if (base == 16)
		return ((char *)g_base_16);
	else
		return (NULL);
}

static void	strtol_init(long *result, long *incr, const char **str, int *neg)
{
	*result = 0;
	*incr = 1;
	*neg = 1;
	if (**str == '-')
	{
		*neg = -1;
		++(*str);
	}
	else if (**str == '+')
		++(*str);
}

long	ft_strtol(const char *s, char **endptr, int base)
{
	const char	*_base;
	long		incr;
	long		val;
	long		result;
	int			negative;

	if (!ft_strlen(s) || ((*s == '+' || *s == '-') && ft_strlen(s) == 1))
		return (0);
	_base = set_base(base);
	strtol_init(&result, &incr, &s, &negative);
	*endptr = (char *)s + ft_strlen(s) - 1;
	result = ft_strchr(_base, *(*endptr--)) - _base;
	while (s >= *endptr)
	{
		if (incr > ((LONG_MAX + (negative == -1)) / base))
			return (0);
		incr *= base;
		val = incr * (ft_strchr(_base, **endptr) - _base);
		if (result > ((LONG_MAX + (negative == -1)) - val))
			return (0);
		result += val;
		--(*endptr);
	}
	return (negative * result);
}
