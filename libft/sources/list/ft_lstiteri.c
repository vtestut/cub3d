/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:59:37 by vtestut            #+#    #+#             */
/*   Updated: 2023/06/14 12:59:17 by vtestut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_lstiteri(t_list lst, int (*f)(size_t index, void *content))
{
	size_t	i;

	i = 0;
	while (lst.list)
	{
		if (!f(i++, lst.list->content))
			return (0);
		lst.list = lst.list->next;
	}
	return (1);
}
