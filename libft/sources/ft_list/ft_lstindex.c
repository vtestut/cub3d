/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstindex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:39:34 by vtestut          #+#    #+#             */
/*   Updated: 2023/06/16 16:40:45 by vtestut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_lstindex(t_list lst, t_list nd)
{
	int	i;

	i = 0;
	while (lst.list)
	{
		if (lst.list == nd.list)
			return (i);
		++i;
		lst.list = lst.list->next;
	}
	return (-1);
}
