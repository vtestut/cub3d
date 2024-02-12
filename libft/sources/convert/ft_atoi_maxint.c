/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_maxint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 11:08:16 by hvercell          #+#    #+#             */
/*   Updated: 2024/02/12 18:13:26 by hvercell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>

int	ft_atoi_maxint(const char *nptr, int *nb)
{
	long	ret;
	int		signe;
	int		i;

	ret = 0;
	signe = 1;
	i = 0;
	while (ft_isspace(nptr[i]) != false)
		++i;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			signe *= (-1);
		++i;
	}
	while (ft_isdigit(nptr[i]) != 0)
	{
		ret = ret * 10 + (nptr[i] - '0');
		if (ret - (signe == -1) > INT_MAX)
			return (1);
		++i;
	}
	if (!ft_isspace(nptr[i]) && nptr[i] != '\0')
		return (1);
	return (*nb = ret * signe, 0);
}

// int	ft_atoi_maxint(const char *nptr, int *nb)
// {
// 	int	ret;
// 	int	signe;
// 	int	i;

// 	(void) nb;
// 	ret = 0;
// 	signe = 1;
// 	i = 0;
// 	while (isspace(nptr[i]) != false)
// 		++i;
// 	if (nptr[i] == '-' || nptr[i] == '+')
// 	{
// 		if (nptr[i] == '-')
// 			signe *= (-1);
// 		++i;
// 	}
// 	while (ft_isdigit(nptr[i]) != 0)
// 	{
// 		ret = ret * 10 + (nptr[i] - '0');
// 		printf("----%d----\n", ret);
// 		++i;
// 	}
// 	printf("--------90\n");
// 	return (ret * signe);
// }
