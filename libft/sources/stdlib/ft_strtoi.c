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

static const char		*g_base_8 = "01234567";
static const char		*g_base_10 = "0123456789";
static const char		*g_base_16 = "0123456789abcdef";

typedef unsigned int	t_ui;

typedef struct s_ninfo {
	unsigned int	cutoff;
	unsigned int	acc;
	unsigned int	cutlim;
	int				neg;
	int				base;
}	t_ninfo;

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

static int	init(const char *s, char **endptr, t_ninfo *ninfo, int base)
{
	if (!ft_strlen(s))
		return (0);
	else if (*s == '-')
		ninfo->neg = 1;
	else
		ninfo->neg = 0;
	ninfo->acc = 0;
	ninfo->cutoff = INT_MAX + ninfo->neg;
	ninfo->cutlim = ninfo->cutoff % base;
	ninfo->cutoff /= base;
	ninfo->base = base;
	*endptr = (char *)s;
	if (*s == '+' || *s == '-')
	{
		if (ft_strlen(s) == 1)
			return (0);
		else
			++(*endptr);
	}
	return (1);
}

static int	loop(char **endptr, t_ninfo *n, const char *base)
{
	unsigned int	val;
	char			*tmp;

	tmp = ft_strchr(base, **endptr);
	if (!tmp)
		return (0);
	val = tmp - base;
	if (n->acc > n->cutoff || (n->acc == n->cutoff && val > n->cutlim))
		return (0);
	else
	{
		n->acc *= n->base;
		n->acc += (unsigned long)val;
	}
	++(*endptr);
	return (1);
}

int	ft_strtoi(const char *s, char **endptr, int base)
{
	const char		*_base;
	t_ninfo			ninfo;

	_base = set_base(base);
	if (!_base)
		return (0);
	if (!init(s, endptr, &ninfo, base))
		return (0);
	while (**endptr && loop(endptr, &ninfo, _base))
		(void)0;
	if (ninfo.neg)
		return ((int)ninfo.acc * -1);
	else
		return ((int)(ninfo.acc));
}
